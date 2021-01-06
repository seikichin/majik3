inherit ITEM;

string owner, label;
int page = 1, open, max_pages = 50 + random(50);
static int round;

mapping pages = ([ ]);

create_item ()
{
  set_name (({ "a spellbook", "spellbook", "book" }));
  set_short ("an empty leather-bound spellbook");
  set_long ("Following commands are available:\n"+
            "  acquire spellbook              - attempts to acquire this spellbook\n"+
            "  read spellbook                 - reads current page\n"+
            "  turn spellbook forward         - turns pages forward\n"+
            "  turn spellbook backward        - turns pages backward\n"+
            "  label spellbook as <label>     - labels spellbook as <label>\n"+
            "  open spellbook                 - opens the spellbook\n"+
            "  close spellbook                - closes the spellbook\n"+
            "  write <spell> to spellbook     - adds <spell> to spellbook\n"+
            "  memorize <page> from spellbook - memorize spell starting from <page>\n");

  set_material ("leather");
  set_dimensions (21, 28, 6);

  if (!pages || sizeof(pages) == 0)
    {
      pages = ([ ]);

      for (int i=0;i<max_pages;i++)
        pages[i] = ({ "empty", 1 });
    }
}

init ()
{
  add_action ("do_acquire", "acquire");
  add_action ("do_read", "read");
  add_action ("do_turn", "turn");
  add_action ("do_open", "open");
  add_action ("do_close", "close");
  add_action ("do_write", "write");
  add_action ("do_memorize", "memorize");
  add_action ("do_label", "label");
}

set_owner (string str)
{
  owner = str;
}

query_owner ()
{
  return owner;
}

set_label (string str)
{
  label = str;
}

query_label (string str)
{
  return label;
}

short ()
{
  string buf = "";


  if (THOB->query_owner())
    buf += capitalize(THOB->query_owner());

  if (THOB->query_owner())
    buf += "'s leather-bound spellbook";
  else
    buf += "an empty leather-bound spellbook";

  if (THOB->query_owner() && THOB->query_label())
    buf += " labeled as \""+THOB->query_label()+"\"";
  else if (THOB->query_label())
    buf += " labeled as \""+THOB->query_label()+"\"";

  if (open)
    buf += " (open)";

  if (buf == "")
    return ::short();
  else
    return buf;
}

is_spellbook ()
{
  return 1;
}

int
do_close (string str)
{
  if (!str || present(str, THIS) != THOB)
    {
      notify_fail ("Open what?\n");
      return 0;
    }
  
  if (!open)
    {
      write ("The book is already closed!\n");
      return 1;
    }

  if (round)
    {
      write ("You stop memorizing.\n");
      remove_call_out ("memorize_beat");
    }

  emote ("$n {close} $s spellbook.", THIS, 0, ENV(THIS));
  open = 0;
   
  return 1;
}

int
do_open (string str)
{
  if (!str || present(str, THIS) != THOB)
    {
      notify_fail ("Open what?\n");
      return 0;
    }

  if (open)
    {
      write ("The book is already open!\n");
      return 1;
    }

  emote ("$n carefully {open} $s spellbook.", THIS, 0, ENV(THIS));
  open = 1;

  return 1;
}

int
do_read (string str)
{
  string buf = "";
  object spell;
  string spell_type;

  if (!str || present(str, THIS) != THOB)
    {
      notify_fail ("Read what?\n");
      return 0;
    }

  if (!open)
    {
      write ("You can't read a closed book!\n");
      return 1;
    }

  if (round)
    {
      write ("You can't do that while memorizing a spell!\n");
      return 1;
    }

  write ("Page: ^c1"+page+"^c0/"+max_pages+":\n\n");

  if (pages[page][0] == "empty")
    {
      write ("This page is completely empty.\n");
      return 1;
    }

  spell_type = THIS->find_spell(pages[page][0]);
  spell = load_object("/obj/spell/generic/" + spell_type + "/" + pages[page][0]);

  if (!spell)
    {
      write ("This page contains ancient spell you don't understand.\n");
      return 1;
    }

  buf += "This page contains spell which takes "+pages[page][1]+" pages.\n" +
         "The description of spell is:\n\n" +
         "    Spell name: "+capitalize(replace_string(pages[page][0], "_", " "))+"\n" +
         "          Type: "+capitalize(spell_type)+"\n" +
         "  Casting time: "+spell->query_casting_time()+"\n" +
         "     Offensive: "+(spell->query_offensive() ? "Yes" : "No")+"\n\n " +
           wrap (spell->query_help(), 50, 2) + "\n";

  THIS->more_string (buf);
  tell_room (ENV(THIS), THIS->query_cap_name()+" reads a page from "+
    THIS->query_possessive()+" spellbook.\n", ({THIS}));
  return 1;
}

int
do_memorize (string str)
{
  string s1, s2, s3;
  object spell;
  string spell_type;

  if (!str)
    {
      notify_fail ("Memorize what?\n");
      return 0;
    }

  if(sscanf (str, "%s from %s", s1, s2) != 2)
    {
      write ("Memorize what from what?\n");
      return 1;
    }

  if (present(s2, THIS) != THOB)
    {
      write ("Memorize "+s1+" from what?\n");
      return 1;
    }

  if (!open)
    {
      write ("You can't memorize spells from book while it's closed!\n");
      return 1;
    }
  
  if (THIS->query_position() != POS_SITTING)
    {
      write ("It's better to read such a long story only while sitting.\n");
      return 1;
    }
   
  if (pages[to_int(s1)][0] == "empty")
    {
      write ("The book doesn't contain spell starting from page "+s1+".\n");
      return 1;
    }

  if (round)
    {
      write ("You are already memorizing something.\n");
      return 1;
    }

  emote ("$n {begin} memorizing a spell.", THIS, 0, ENV(THIS));
  round = pages[to_int(s1)][1] * 10;
  call_out ("memorize_beat", 5, pages[to_int(s1)][0]);
  return 1;
}

memorize_beat (string spell_name)
{
  string buf = "";

  if (THIS->query_position() != POS_SITTING)
    {
      write ("You can memorize spells only when sitting and thus you lose concentration.\n");
      round = 0;
      remove_call_out ("memorize_beat");
      return 1;
    }

  if (round % 10 && random(100) > (THIS->query_spell(spell_name)[0] + THIS->query_pow() + THIS->query_int() + THIS->query_wis()))
    {
      write ("You didn't quite understand the formula and begin reading again the previous chapter.\n");
      round += 5 + random(5);
    }
  else if (round % 10 && ((round-5) != 0))
    {
      write ("You turn the page and continue memorizing "+replace_string(spell_name, "_", " ")+".\n");
    }

  round -= 5;
  THOB->add_ep (-(5 + random(5)));

  if (round < 0)
    round = 0;

  if (!round)
    {
      emote ("$n {finish} memorizing a spell.", THIS, 0, ENV(THIS));
      THIS->add_spell_memory(spell_name, THIS->query_int() + random(10));
      THIS->add_spell_exp(spell_name, random(5));
      remove_call_out ("memorize_beat");
      round = 0;
      return 1;
    }

  call_out ("memorize_beat", 5, spell_name);
}

int
do_write (string str)
{
  string s1, s2, s3;
  object spell;
  string spell_type;

  if (!str)
    {
      notify_fail ("Write what?\n");
      return 0;
    }

  if(sscanf (str, "%s to %s", s1, s2) != 2)
    {
      write ("Write what to what?\n");
      return 1;
    }

  if (present(s2, THIS) != THOB)
    {
      write ("Write "+s1+" to what?\n");
      return 1;
    }

  if (!open)
    {
      write ("You can't write spells to book while it's closed!\n");
      return 1;
    }

  if (round)
    {
      write ("You can't write spells while memorizing!\n");
      return 1;
    }

  if (THIS->query_position() != POS_SITTING)
    {
      write ("It's better to write such a long story only while sitting.\n");
      return 1;
    }

  s3 = replace_string(s1, " ", "_");

  if (THIS->query_spell(s3) == -1)
    {
      write ("You dont have such spell!\n");
      return 1;
    }

  if (THIS->query_spell(s3)[1])
    {
      for (int i=1;i<max_pages;i++)
        {
          if (pages[i][0] == "empty")
            {
              spell_type = THIS->find_spell(s3);
              spell = load_object("/obj/spell/generic/" + spell_type + "/" + s3);

              if (!spell)
                {
                  write ("You can't write that spell!\n");
                  return 1;
                }

              if ((spell->query_casting_time() + spell->query_level()) > (max_pages-i))
                {
                  write ("The spell doesn't fit to book!\n");
                  return 1;
                }

              write ("You write "+s1+" to your spellbook, starting from page "+i+".\n");
              tell_room (ENV(THIS), THIS->query_cap_name() + " writes something to "+
                THIS->query_possessive()+" spellbook.\n", ({THIS}));
              pages[i] = ({ s3, spell->query_casting_time() + spell->query_level() });
              return 1;
            }
        }
      }
    write ("You don't remember that spell enough well!\n");
    return 1;
}

int
do_turn (string str)
{
  int i;
  string s1, s2;

  if (!str)
    {
      notify_fail ("Turn what?\n");
      return 0;
    }

  if(sscanf (str, "%s %s", s1, s2) == 1)
    {
      write ("Turn "+THOB->query_name()+"'s pages to forward or backward?\n");
      return 1;
    }

  if ( present(s1, THIS) != THOB)
    {
      write ("Turn what?\n");
      return 1;
    }

  if (!open)
    {
      write ("You can't turn pages until you open it!\n");
      return 1;
    }

  if (round)
    {
      write ("You can't do that while memorizing a spell!\n");
      return 1;
    }

  if (s2 == "backward")
    {
      if (page == 1)
        {
          write ("This is the first page.\n");
          return 1;
        }

      while (1)
        {
          i++;
          if (pages[page][0] != "empty")
            break;
        }

      write ("You turn the book "+i+" pages backward, to the page "+(page-i)+".\n");
      tell_room (ENV(THIS), THIS->query_cap_name() + " turns the pages of "
        +THIS->query_possessive()+" spellbook backwards.\n", ({THIS}));
      page -= i;
      if (page < 1)
        page = 1;
      return 1;
   }

      if (page == max_pages)
        {
          write ("This is the last page.\n");
          return 1;
        }
    
      i = pages[page][1];
      
      if ((page+i) > max_pages)
        page = max_pages;
      else
        page += i;

      write ("You turn the book "+i+" pages forward, to the page "+(page)+".\n");
      tell_room (ENV(THIS), THIS->query_cap_name() + " turns the pages of "
        +THIS->query_possessive()+" spellbook forward.\n", ({THIS}));
      return 1;
}    

int
do_acquire (string str)
{
  if (!str || present(str, THIS) != THOB)
    {
      notify_fail ("Acquire what?\n");
      return 0;
    }

  if (round)
    {
      write ("You can't do that while memorizing a spell!\n");
      return 1;
    }

  emote ("$n {acquire} "+THOB->query_maybe_cap_name()+".\n", THIS, 0, ENV(THIS));
  THOB->set_owner (THIS->query_true_name());
  return 1;
}

int
do_label (string str)
{
 string s1, s2;

  if (!str)
    {
      notify_fail ("Label what?\n");
      return 0;
    }
      
  if(sscanf (str, "%s as %s", s1, s2) != 2)
    {
      write ("Label what as what?\n");
      return 1;
    }
      
  if (present(s1, THIS) != THOB)
    {
      write ("Label what as "+s2+"?\n");
      return 1;
    }

  if (round)
    {
      write ("You can't do that while memorizing a spell!\n");
      return 1;
    }
  
  emote ("$n {label} "+THOB->query_maybe_cap_name()+" as \""+s2+"\".\n", THIS, 0, ENV(THIS));
  THOB->set_label (s2);
  return 1;
}
