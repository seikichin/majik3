mapping spells;

static object current_spell;
static object current_target;
static int round;

#define SPELL_DIR "/obj/spell/generic/"

int add_spell (string);
int add_spell_chance (string, int);
int add_spell_memory (string, int);
int add_spell_exp (string, int);

int query_spell (string);

void spell_init ();
void spell_beat ();

string find_spell (string);
string find_spell_name_by_object (object);

mapping query_spells ();

mapping
query_spells ()
{
  if (!spells)
    THOB->spell_init();

  return spells;
}

void
spell_init ()
{
  spells = ([ ]);
}

int
add_spell (string spell_name)
{
  if (!find_spell(spell_name) || spells[spell_name])
    return -1;

  /* random(6) starting chance,
     spell not memorized,
     100 starting practice experience = random(10) die */

  spells[spell_name] = ({ random(6), 1 + random(THOB->query_int()), 100 });

  return spells[spell_name][0];
}

int
add_spell_chance (string spell_name, int chance)
{
  if (!find_spell(spell_name) || !spells[spell_name])
    return -1;

  spells[spell_name][0] += chance;

  if (spells[spell_name][0] < 0)
    spells[spell_name][0] = 0;
  else if (spells[spell_name][0] > 99)
    spells[spell_name][0] = 99;

  return spells[spell_name][0];
}

int
add_spell_memory (string spell_name, int memory)
{
  if (!find_spell(spell_name) || !spells[spell_name])
    return -1;

  spells[spell_name][1] += memory;

  if (spells[spell_name][1] < 0)
    spells[spell_name][1] = 0;
  else if (spells[spell_name][1] > THOB->query_int())
    spells[spell_name][1] = THOB->query_int();

  return spells[spell_name][1];
}

int
add_spell_exp (string spell_name, int exp)
{
  if (!find_spell(spell_name) || !spells[spell_name])
    return -1;

  spells[spell_name][2] += exp;

  if (spells[spell_name][2] < 0)
    spells[spell_name][2] = 0;
  else if (spells[spell_name][2] > 1000)
    spells[spell_name][2] = 1000;

  return spells[spell_name][2];
}

int
query_spell (string spell_name)
{
  if (!find_spell(spell_name) || !spells[spell_name])
    return -1;

  return spells[spell_name];
}

string
find_spell_name_by_object (object spell)
{
  return explode(base_name(spell), "/")[<1];
}

string
find_spell (string spell_name)
{
  string *spell_type = ({ "abjuration",
                          "alteration",
                          "conjuration",
                          "divination",
                          "enchantment",
                          "illusion",
                          "invocation",
                          "necromancy" });

  if (!spell_name)
    return;

  for (int i=0;i<sizeof(spell_type);i++)
    if (file_size (SPELL_DIR + spell_type[i] + "/" + spell_name + ".c") > -1)
      return spell_type[i];

  return;
}

chant_spell (string spell_name, string target_name)
{
  object spell;

  if (current_spell)
    {
      emote ("$n {lost} concentration.", THOB, 0, ENV(THOB));
      current_spell = 0;
      current_target = 0;
      return;
    }

  spell = load_object(SPELL_DIR + find_spell (spell_name) + "/"
    + spell_name);

  if (!spell || THOB->query_spell(spell_name) == -1)
    {
      tell_object (THOB, "You have no idea how to cast ^c1"+
        replace_string(spell_name,"_"," ")+"^c0.\n");

      return;
    }

  if (THOB->query_spell(spell_name)[1] == 0)
    {
      tell_object (THOB, "You don't remember ^c1"+
        replace_string(spell_name,"_", " ")+"^c0 enough well.\n");

      return;
    }

  emote ("$n {concentrate} on a spell.", THOB, 0, ENV(THOB));
  current_spell = spell;
  current_target = target_name;
  round = spell->query_casting_time();
  return;
}

cast_spell (object spell, string target_name)
{
  int i, j, chance;
  object target;
  string spell_name = "", buf = "";

  current_spell = 0;
  current_target = 0;

  spell_name = find_spell_name_by_object (spell);
  i = spell->query_casting_time()+1*spell->query_level()*(random(10)+1);

  if (i > THOB->query_sp())
    {
      tell_object (THOB, "^cRThe spell drains your life energy!^c0\n");
      THOB->add_hp (-(i-THOB->query_sp()));
      THOB->add_sp (-(i));
    }
  else
    {
      THOB->add_sp (-(i));
    }

  j = 0;
  j = random(100);
  chance = THOB->query_spell(spell_name)[0] + THOB->query_int() % 10 +
                                              THOB->query_pow() % 10 +
                                             ((THOB->query_dex() % 10) / 2);

  if (THOB->query_name() == "namhas")
    {
      tell_object (THOB, "  ROLL: "+j+"\n");
      tell_object (THOB, "CHANCE: "+chance+"\n");
    }

  THOB->add_spell_memory (spell_name, -1);

  if (!random(50))
    THOB->add_spell_exp (spell_name, random(10));

  if (j > chance)
    {
      emote ("$n {fail} the spell.\n", THOB, 0, ENV(THOB));
      spell->do_failure();
      return;
    }
  else
    {
      if (spell->query_components()[0] && spell->query_components()[1])
        buf += "{mutter} cryptic words of magic and {gesture} arcane symbols";
      else if (spell->query_components()[0])
        buf += "{mutter} cryptic words of magic";
      else if (spell->query_components()[1])
        buf += "{gesture} arcane symbols in the air";       
      else
        buf += "{snap} $s fingers";

      emote ("$n "+buf+".", THOB, 0, ENV(THOB));

      target = present(target_name);

      if (target && spell->query_offensive() && target != THOB)
        {
          target->before_battle (THOB);
          target->set_target(THOB->query_name());
          target->begin_battle(THOB);
        }
    }

  spell->perform_spell (THOB, target_name, j);
}

void
spell_beat ()
{
  if (!current_spell)
    return;

  if (!round)
    {
      cast_spell (current_spell, current_target);
      return;
    }

  tell_object(THOB, capitalize(replace_string(
    THOB->find_spell_name_by_object(current_spell),"_"," ")+": "+ 
    repeat_string("#", round)+"\n"));

  THOB->add_ep (-random(2*current_spell->query_level()));
  round--;
}
