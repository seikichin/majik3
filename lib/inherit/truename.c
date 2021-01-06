/* True Name system for players */
#define MASTER "home/aluna/FTP/master"
#define TRUENAME_DIR "/obj/spell/truename/"
#define NONSENSE 1+random(3)
mapping truename_map;

static string create_syllable()
{
    string *vowel, *cons, w1, w2, c1, c2;
    int rnd;
    vowel=({"a","e","i","o","u","y"});
    cons=({"b","c","d","f","g","h","j","k","l","m",
      "n","p","q","r","s","t","v","w","x","z"});
    w1=vowel[random(sizeof(vowel))];
    w2=vowel[random(sizeof(vowel))];
    c1=cons[random(sizeof(cons))];
    c2=cons[random(sizeof(cons))];
    rnd=random(6)+1;
    switch (rnd)
      {
      case 1:
	return c1+w1;
      case 2:
	return w1+c1;
      case 3:
	return w1+c1+w2;
      case 4:
	return c1+w1+c2;
      case 5:
	return c1+w1+w1;
      case 6:
	return w1+w1+c1;
      }
}

void initialize_magical_true_names()
{
    truename_map=([]);
}

static int add_magical_true_name(string true_name, string meaning)
{
    truename_map[true_name]=meaning;
    return 1;
}

string *query_known_true_names()
{
    return keys(truename_map);
}

string *query_known_true_meanings()
{
    return values(truename_map);
}

string query_magical_true_meaning(string true_name);

string list_true_names()
{
    string msg, *truenames;
    int i;
    truenames=keys(truename_map);
    truenames=sort_array(truenames,1);
    msg="";
    for (i=0; i<sizeof(truenames); i++)
    {
	msg+=truenames[i]+"\t("+
	THOB->query_skill_rank("name_of_"+
			       query_magical_true_meaning(truenames[i]))+
	  ")\n";
    }
    return msg;
}

string query_magical_true_meaning(string true_name)
{
    return truename_map[true_name];
}

string query_magical_true_name(string meaning)
{
    int i;
    string *truenames, *meanings;
    truenames=keys(truename_map);
    meanings=values(truename_map);
    i=member_array(meaning, meanings);
    if(i>=0)
	return truenames[i];
    return "";
}

string create_magical_true_name(string meaning)
{
    string new_true_name, *truenames, *meanings;
    truenames=keys(truename_map);
    meanings=values(truename_map);
    if(member_array(meaning, meanings)>=0)
	return "";
    new_true_name=create_syllable()+create_syllable();
    while (member_array(new_true_name, truenames)>=0)
	new_true_name+=create_syllable();
    add_magical_true_name(new_true_name, meaning);
    THOB->add_skill("name_of_"+meaning);
    return new_true_name;
}

string handle_true_names(string divine_chant)
{
    string *tech, *form, *power, *all, *words, *meanings;
    string *tmp_tech, *tmp_form, *tmp_power, true_chant;
    int i, nonsense;
    tech=MASTER->query_tech_names();
    form=MASTER->query_form_names();
    power=MASTER->query_power_names();
    all=MASTER->query_all_names();
    words=explode(divine_chant,"-");
    tmp_tech=({});
    tmp_form=({});
    tmp_power=({});
    meanings=({});
    for (i=0;i<sizeof(words);i++)
    {
	meanings+=({query_magical_true_meaning(words[i])});
	if(meanings[i])
	    if(member_array(meanings[i],tech)>=0)
		tmp_tech+=({meanings[i]});
	    else
	    if(member_array(meanings[i],form)>=0)
		tmp_form+=({meanings[i]});
	    else
	    if(member_array(meanings[i],power)>=0)
		tmp_power+=({meanings[i]});
	    else
		nonsense++;
	else
	  nonsense+=strlen(words[i]);
    }
    if(nonsense)
      {
	tell_object(THOB,"Using nonsense with true names really hurts!\n");
	THOB->add_hp(-nonsense*NONSENSE);
	THOB->add_sp(-nonsense*NONSENSE);
	THOB->add_ep(-nonsense*NONSENSE);
      }
    if(sizeof(tmp_tech)<1||sizeof(tmp_form)<1||sizeof(tmp_power)<1)
    {
	return "incomplete";
    }
    tmp_tech=sort_array(tmp_tech,1);
    tmp_form=sort_array(tmp_form,1);
    tmp_power=sort_array(tmp_power,1);
    true_chant=implode(tmp_tech,"-")+"-"+
    implode(tmp_form,"-")+"-"+
    implode(tmp_power,"-");
    return true_chant;
}

void do_true_name_cost(string the_spell, string target)
{
    string *words;
    int i;
    object ob;
    words=explode(the_spell,"-");
    for (i=0;i<sizeof(words);i++)
    {
	ob=THOB->find_skill("name_of_"+words[i]);
	if(ob)
	{
	    ob->do_skill_costs(THOB,target);
	}
    }
}

int recite_true_name(string divine_chant, string target)
{
    string *words, the_spell;
    int *test, res, i, suc, fai;
    object true_spell;
    the_spell=handle_true_names(divine_chant);
    tell_room(environment(THOB),
      THOB->query_cap_name()+" divines '"+divine_chant+"!'\n",
      ({THOB}));
    tell_object(THOB,"You divine '"+divine_chant+"!'\n");
    if(the_spell=="incomplete")
    {
	tell_object(THOB,
	  "Absolutely nothing happens.\n");
	tell_room(environment(THOB),
	  "Nothing seems to happen.\n",
	  ({THOB}));
	return 1;
    }
    do_true_name_cost(the_spell, target);
    true_spell=load_object(TRUENAME_DIR+the_spell);
    if(!true_spell||!true_spell->query_true_magick())
    {
	tell_object(THOB,
	  "You feel faint tickling sensation going through you.\n");
	tell_room(environment(THOB),
	  "Nothing seems to happen.\n",
	  ({THOB}));
	return 1;
    }
    tell_object(THOB,
      "Reality ripples from the power of your words!\n");
    words=explode(the_spell,"-");
    test=({});
    for(i=0;i<sizeof(words);i++)
    {
	res=THOB->skill_check("name_of_"+words[i]);
	if(res>0)
	  suc++;
	else
	  fai++;
    }
    if(suc>=fai)
	true_spell->do_success(THOB, target);
    else
	true_spell->do_failure(THOB, target);
    return 1;
}
