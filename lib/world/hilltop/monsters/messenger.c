/*
 * A MAILER DAEMON for Majik's Message Delivery System
 *
 * Coder: Namhas, based on messenger idea by Dragoness
 *
 */

#include <socket.h>

inherit MONSTER;

int number = 0, delay = 60, delivery = 0, home = 0, money = 0;

#define OFFICE	"/world/hilltop/rooms/room3"

#include "../path.h"

string me;
string guser, ghost;

static object kludge;

create_monster ()
{
    set_name (({"a mailer daemon", "mailer daemon", "daemon"}));
    set_short ("a mailer daemon is hopping around here happily");
    set_long ("You see a funny mail daemon who is delivering mail all over "
      + "the world of majik. You can think better description for this funny "
      + "man and then sent it to Namhas using this mailing service. To send mail "
      + "please use command \"send\". You can also \"buy\" a scroll. Other "
      + "commands are not yet available.\n");

    set_race ("greater demon");

    set_gender (1);
    set_levels (([ "fighter" : 23, "caster" : 47 ]));

    add_alignx (0 + random(500));
    add_aligny (0 + random(500));

    call_out ("do_puuh", 3);
    me = capitalize(name);
}

do_puuh ()
{
  object gnome;

  remove_call_out ("do_puuh");
  remove_call_out ("do_puuh");

        gnome = present ("gnome", environment(THOB));
      if (gnome)
        gnome->process();
}

init ()
{
    remove_call_out ("do_move");
    call_out ("do_move", delay);
    remove_call_out ("do_deliver");
    call_out ("do_deliver", 64 + random(64));
    add_action ("do_send", "send");
    add_action ("do_buy", "buy");
}

do_move ()
{
    string *dir, *dest, *inv1, *inv2;
    int i, found;

    remove_call_out ("do_move");
    remove_call_out ("do_move");

    inv1 = all_inventory(environment(THOB));
    inv2 = all_inventory(THOB);

    if (inv2)
    {
	for (int j=0;j<sizeof(inv2);j++)
	{
	    if (inv2[j]->query_status() == 2)
	    {
		for (int k=0;k<sizeof(inv1);k++)
		{
		    if (inv1[k]->query_name() == inv2[j]->query_to())
		    {
                        newmail (inv1[k], inv2[j]);
                        found = 1;
		    }
		}
	    }
            else
            {
              tell_room (environment(), me+" drops "+inv2[j]->short()+".\n");
              inv2[j]->move(environment());
            }
	}
    }

    if (sizeof(inv2) == 0)
      delivery = 0;

    if (delivery)
	delay = 2 + random(8);
    else
	delay = 60 + random(60);

    if (!found)
    {

	dir = environment(THOB)->query_exit_dir();
	dest = environment(THOB)->query_exit_dest();

        if (sizeof(dir) == 0 || !dir) {
          move_player (OFFICE);
          return 1;
        }
        else
	  i = random(sizeof(dir));

        if (!dest[i]->query_no_monster())
	  move_player (dest[i], dir[i]);
    }

    call_out ("do_move", delay);
}

int
do_note (string str)
{
  remove_call_out ("do_note");
  write_file ("/log/messenger", ctime(time()) + " :: " + str + "\n");

  tell_room (environment(), me+" scribes something to his notebook.\n");

  return 1;
}

newmail (object who, object scroll)
{
  do_say ("\aHello, "+capitalize(who->query_name())+"!  I have some mail for you.");
  tell_object (who, me+" gives you "+scroll->short()+".\n");

  message ("action", me+" gives "
    +capitalize(who->query_name())+" "+scroll->short()+".\n",
    environment(who), who);

  scroll->move (who);

  delivery--;

  if (delivery < 0)
    delivery = 0;

  rm (scroll->query_filename() + ".o");

  call_out ("do_note", 4 + random(10), "A scroll for " +
    scroll->query_to()+" delivered"+
    " in "+((time() - scroll->query_date())/60)+" minutes.");
}

do_buy (str)
{
    object ob;

    string nm = capitalize(THIS->query_name());

    if (!str)
    {
      if (!number)
        do_say ("Sorry, "+nm+"! I have nothing to sell.");
      else if (number == 1)
        do_say ("What you want to buy, "+nm+"? I have one scroll.");
      else
        do_say ("What you want to buy, "+nm+"? I have "+number+" scrolls.");

      return 1;
    }

    if (str == "scroll" && number)
    {
	if (THIS->query_money() < 1)
	{
          do_say ("You don't have enough money, "+nm+"!");
	  return 1;
	}
	write ("You buy a scroll.\n");
	tell_room (environment(), nm + " gives one copper coin to "+me+".\n", ({ THIS }));
	THIS->add_money (-1);
        THOB->add_money (1);
        number--;
	tell_room (environment(), me+" gives "+nm+" a scroll.\n", ({ THIS }));
	ob = clone_object (ITEM_PATH + "scroll");
	ob->move (THIS);
	return 1;
    }
    else
    {
        do_say ("Sorry, "+nm+"! I have no "+pluralize(str)+".");
	return 1;
    }
    return 0;
}

do_send (string str)
{
    object ob;
    string to, scroll;

    string nm = capitalize(THIS->query_name());

    if (!str)
    {
        do_say ("What you want to send, "+nm+"?");
	return 1;
    }

    str = lower_case(str);

    if (sscanf (str, "%s to %s", scroll, to) != 2)
    {
        do_say ("To whom it should be delivered, "+nm+"?");
	write (me+" advices you to type: \"send <scroll> to <player>\"\n");
        write (me+" whispers to you: also internet e-mail supported\n");
	return 1;
    }

    ob = present(scroll, THIS);

    if (ob)
    {
	if (ob->query_name() == "scroll")
	{
	    message ("say", nm + " gives "+ob->short()+" "
	      + "to "+me+".\n", environment(THIS), THIS);
	    write ("You give a scroll to "+me+".\n");
	    if (ob->query_status() == 0)
	    {
              message ("say", me+" looks at "+ob->short()+" in puzzlement.\n", environment(THIS));
              do_say ("It's empty!");
              message ("say", me+" gives "+ob->short()+" to "+nm+".\n", environment(THIS), THIS);
              write ("A mailer daemon gives your scroll back.\n");
              return 1;
	    }
            else if (ob->query_status() != 1)
            {
              message ("say", me+" looks at "+ob->short()+" in puzzlement.\n", environment(THIS));
              do_say ("I can't send that!");
              message ("say", me+" gives "+ob->short()+" to "+nm+".\n", environment(THIS), THIS); 
              write ("A mailer daemon gives your scroll back.\n");
            }
	    else if (ob->query_status() == 1)
	    {
		if (THIS->query_money() < 1)
		{
                    do_say (nm + ", you don't have enough money to send it!");
                    write (me+" gives your scroll back.\n");
                    message ("say", me+" gives "+ob->short()+" to "+nm+".\n", environment(THIS), THIS);
		    return 1;
		}
		else
		{
                    do_say ("This will take one copper coin, "+nm+"!");
                    write ("You give one copper coin to "+me+".\n");
		    THIS->add_money(-1);
                    THOB->add_money(1);
		    message ("say", nm +
		      " gives one copper coin to "+me+".\n",
		      environment(THIS), THIS);
		    ob->move(THOB);
		    message ("say", me+" writes something on the scroll and then puts it in his sack.\n", environment(THIS));
		    ob->set_status (2);
		    ob->set_to (to);
		    ob->set_from (THIS->query_name());
		    delivery++;
		    return 1;
		}
	    }
	}
	else
	{
	    message ("say", me+" refuses to send "+ob->short()+" from "+THIS->query_name()+"\n", environment(THIS), THIS);
	    write ("You can't send that!\n");
	    return 1;
	}
    }
    else
    {
	write ("You don't have such thing!\n");
	return 1;
    }

    message ("say", me+" says '^c1Mail delivery system is still "
      +"under construction.^c0'\n", THIS);
    return 1;
}

whistle (string who)
{
  tell_room (environment(), me+" seems to hear something.\n");
  return 1;
}

do_deliver ()
{
    object *ob, gnome;
    string *dir, user, host;

    int i, j, found;

    ob = all_inventory(THOB);

    remove_call_out ("do_deliver");

    found = 0;

    if (!delivery)
	home++;

	/* here should be code to check saved scrolls for delivery */

	if (home > 3 && !delivery)
	{
	    tell_room (environment(), me+" speeds away!\n");
	    move (OFFICE);
	    tell_room (environment(), me+" arrives from south.\n");
	    home=0;
	    delivery=0;
	    delay=300;
	    number=10;
            gnome = present("gnome", environment());
            if (gnome)
	      {
                gnome->process();
                if (money)
                  {
                tell_room (environment(), me+" gives some money to gnome.\n");
                gnome->add_money (money);
                money=0;
                  }
              }
	    call_out ("do_deliver", 500);
	    return 1;
	}

    for(i=0;i<sizeof(ob);i++)
    {
	if (ob[i]->query_status() == 2)
	{
	    for(j=0;j<sizeof(users());j++)
	    {
		if (users()[j]->query_name() == lower_case(ob[i]->query_to()))
		{
                    if (environment(THOB) != environment(users()[j]))
                    {
		    tell_room (environment(), me+" speeds away!\n");
		    move (environment(users()[j]));
		    dir = environment(THOB)->query_exit_dir();
                    if (sizeof(dir) == 0 || !dir)
                      tell_room (environment(), me+" arrives.\n");
                    else
		    tell_room (environment(), me+" arrives from " + dir[random(sizeof(dir))] + ".\n");
                    }
                    newmail (users()[j], ob[i]);
		    found = 1;
		    call_out ("do_deliver", 200);
		    return 1;
		}
	    }
            if (!found && sscanf (ob[i]->query_to(), "%s@%s", user, host) == 2)
            {
              tell_room (environment(), me+" chants arcane words.\n");
              do_internet_deliver (ob[i], user, host);
              tell_room (environment(), ob[i]->short() +" disappears.\n"); 
            }
            else if (!found)
	    {
                call_out ("do_note", 5 + random(5), "A scroll for "+ob[i]->query_to()+" saved for later delivery.");
                rm (ob[i]->query_filename() + ".o");
		ob[i]->save_scroll();
                destruct(ob[i]);
		delivery--;
	    }
	}
    }
    call_out ("do_deliver", 200);
    return 1;
}

int
do_say (string str)
{
  "/command/mortal/say"->main (str);
  return 1;
}

int
query_number ()
{
  return number;
}

int
query_money ()
{
  return money;
}

int
add_number (int i)
{
  number += i;

  tell_room (environment(), me+" places "+i+" scrolls to his sack.\n");

  if (number > 10)
    number = 10;

  if (number < 0)
    number = 0;

  return number;
}

call_read (object socket, string data, string address)
{
  return;
}

call_close ()
{
  return 1;
}

call_resolve (string address, string resolved, int key)
{
  string ip;
  object sock;

  ip = resolved;
  sock = new(SOCKET, SOCKET_CONNECT, ip + " 25", (: call_read :),
    (: call_close :));
  sock->send ("HELO majik.netti.fi\n");
  sock->send ("MAIL From:"+kludge->query_from()+"@majik.netti.fi\n");
  sock->send ("RCPT To:"+guser+"@"+ghost+"\n");
  sock->send ("DATA\n");
  sock->send (
"Subject: "+kludge->query_subject()+"\n\n"+
"You've received a virtual scroll of mail from Majik - the multi user\n"+
"role playing environment. The scroll contains following text:\n\n"+
kludge->query_message()+"\n"+
"--------------------------------------------------------------------\n"+
"Majik Message Delivery / Majik MURPE - http://majik.netti.fi\n");

  sock->send (".\n");
  sock->send ("QUIT\n");
  call_out ("do_note", 5, "send Internet e-mail to "+guser+"@"+ghost+"");
  destruct(kludge);
}

do_internet_deliver (object ob, string user, string host)
{
  kludge = ob;
  guser = user;
  ghost = host;
  tell_room (environment(), me+" looks around and resolves some arcane forulaes.\n");
  resolve (host, "call_resolve");
  return 1;
}
