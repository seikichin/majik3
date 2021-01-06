// filename: /daemon/time.c
// description : time daemon
// coders      : namhas, waster, aluna

#include <time.h>
int quick_loop(int val, int value, int correct);

#define SUN_RISE	0
#define SUN_LIGHT	1
#define SUN_SET		2
#define SUN_DARK	3

#define MOON_RISE	0
#define MOON_LIGHT	1
#define MOON_SET	2
#define MOON_DARK	3

static int state, moon1_state, moon2_state, moon3_state;

int gtime()
{
    return (time() - BIRTHDAY) / GAME_MIN;
}

int query_month()
{
    return quick_loop(GAME_MONTH,MONTHS,1);
}

int query_year()
{
    return (((time() - BIRTHDAY) / (GAME_YEAR)) + 1);
}

void
tell_outdoors (string str)
{
  object o, *all;

  all = users();

  foreach (o in all) 
    {
      if (ENV(o)->query_outdoors() == 4)
        tell_object (o, str);
    }
}

string query_season()
{
    switch (query_month())
    {
    case 0..1:
	return "spring";
    case 2..3:
	return "summer";
    case 4..5:
	return "autumn";
    case 6..7:
	return "winter";
    default:
	return "error";
    }
}

int query_season_number(string season)
{
    if(!season)
	season=query_season();
    switch (season)
    {
    case "spring":
	return 0;
    case "summer":
	return 1;
    case "autumn":
	return 2;
    case "winter":
	return 3;
    default:
	return -1;
    }
}

int quick_loop(int val, int value, int correct)
{
    int lop;
    lop = ((time() - BIRTHDAY) / val) + correct;

    lop = (lop%value);
    return lop;
}

int query_day()
{
    return quick_loop(GAME_DAY,DAYS,1);
}

int query_hour()
{
    return quick_loop(GAME_HOUR,HOURS,0);
}

int query_minute()
{
    return quick_loop(GAME_MIN,MINUTES,0);
}

string query_month_s()
{
    switch (query_month())
    {
    case 0:
	return "Adian";
    case 1:
	return "Psothion";
    case 2:
	return "Agrazhar";
    case 3:
	return "Xudal";
    case 4:
	return "Plomiba";
    case 5:
	return "Nuzyael";
    case 6:
	return "Garsichian";
    case 7:
	return "Morgat";
    default:
	return "error";
    }
}

int query_eclipse();
int query_sun_vertical_sector();     
int query_sun_horizontal_sector();  
int query_moon1_vertical_sector();
int query_moon2_vertical_sector();
int query_moon3_vertical_sector();
string query_horizontal_desc(int i);

void create()
{
  if (query_sun_vertical_sector() < -1)
    state = SUN_DARK;
  else
    state = SUN_LIGHT;

  if (query_moon1_vertical_sector() < -1)
    state = MOON_DARK;
  else
    state = MOON_LIGHT;

  if (query_moon2_vertical_sector() < -1)
    state = MOON_DARK;
  else
    state = MOON_LIGHT;

  if (query_moon3_vertical_sector() < -1)
    state = MOON_DARK;
  else
    state = MOON_LIGHT;


    call_out("reboot",GAME_MIN); 
}

void reboot()
{
    int sv;

    remove_call_out("reboot");
    call_out("reboot",GAME_HOUR);

    sv = query_sun_vertical_sector();

    if (sv==-1 && state == SUN_LIGHT) {
      tell_outdoors ("The sun slowly disappears in the "+
        query_horizontal_desc(query_sun_horizontal_sector())+".\n");
      state = SUN_SET;
    }

    if (sv<-1 && state == SUN_SET) {
      tell_outdoors ("The night has begun.\n");
      state = SUN_DARK;
    }

    if (sv==-1 && state == SUN_DARK) {
      tell_outdoors ("The sun rises in the "+
        query_horizontal_desc(query_sun_horizontal_sector())+".\n");
      state = SUN_RISE;
    }

    if (sv>-1 && state == SUN_RISE) {
      tell_outdoors ("The day has begun.\n");
      state = SUN_LIGHT;
    }

    query_eclipse();
}

int query_moon1_horizontal_sector()
{
    int tim, tmp;
    tim=gtime();
    tmp=tim/MOON1_TIME_H;
    tim=tim-tmp*MOON1_TIME_H;
    return (HORIZONTAL_SECTORS * tim / MOON1_TIME_H)+1;
}

int query_moon1_vertical_sector()
{
    int tim, tmp;
    tim=gtime();
    tmp=tim/MOON1_TIME_V;
    tim=tim-tmp*MOON1_TIME_V;
    return (2*MOON1_VERSECTORS * tim / MOON1_TIME_V)+1 -
    MOON1_VERSECTORS+MOON1_VERMOD;
}

int query_moon2_horizontal_sector()
{
    int tim, tmp;
    tim=gtime();
    tmp=tim/MOON2_TIME_H;
    tim=tim-tmp*MOON2_TIME_H;
    return (HORIZONTAL_SECTORS * tim / MOON2_TIME_H)+1;
}

int query_moon2_vertical_sector()
{
    int tim, tmp;
    tim=gtime();
    tmp=tim/MOON2_TIME_V;
    tim=tim-tmp*MOON2_TIME_V;
    return (2*MOON2_VERSECTORS * tim / MOON2_TIME_V)+1 - 		
    MOON2_VERSECTORS+MOON2_VERMOD;
}

int query_moon3_horizontal_sector()
{
    int tim, tmp;
    tim=gtime();
    tmp=tim/MOON3_TIME_H;
    tim=tim-tmp*MOON3_TIME_H;
    return (HORIZONTAL_SECTORS * tim / MOON3_TIME_H)+1;
}

int query_moon3_vertical_sector()
{
    int tim, tmp;
    tim=gtime();
    tmp=tim/MOON3_TIME_V;
    tim=tim-tmp*MOON3_TIME_V;
    return (2*MOON3_VERSECTORS * tim / MOON3_TIME_V)+1 -		
    MOON3_VERSECTORS+MOON3_VERMOD;
}

int query_sun_horizontal_sector()
{
    int tim, tmp;
    tim=gtime();
    tmp=tim/GAME_DAY;
    tim=tim-tmp*GAME_DAY;
    return ((HORIZONTAL_SECTORS * tim / GAME_DAY)/2)+1;
}

int query_sun_vertical_sector()
{
    int tim, tmp, sector;
    tim=gtime();
    tmp=tim/GAME_DAY;
    tim=tim-tmp*GAME_DAY;
    sector=(2*SUN_VERSECTORS * tim / GAME_DAY)+1-SUN_VERSECTORS;
    if(query_season()=="winter")
	sector=sector-3;
    else
    if(query_season()=="summer")
	sector=sector+3;
    return sector;
}

int check_near(int val1, int val2)
{
    int tmp;
    tmp=val1-val2;
    if(tmp>-2&&tmp<2)
	return 1;
    return 0;
}

static int check_moon1_sun();
static int check_moon2_sun();
static int check_moon3_sun();
static void doEclipse(int Neutral, int Evil, int Good);
int query_eclipse()
{
    int e1, e2, e3;

    e1=check_moon1_sun();
    e2=check_moon2_sun();
    e3=check_moon3_sun();

    if(e1+e2+e3>0)
	doEclipse(e1,e2,e3);
    return e1+e2+e3;
}

static int tell_sky(string message);
static void doEclipse(int Neutral, int Evil, int Good)
{
    string msg;
    int sum;
    sum=Neutral+Evil+Good;
    if(Neutral==2||Evil==2||Good==2)
	msg="The world is cloaked in darkness!\n";
    else
	msg="The world is cloaked in shadows!\n";

    if(Neutral==2)
	msg+=MOON1_NAME+" has fully eclipsed the sun!\n";
    else
    if(Neutral==1)
	msg+=MOON1_NAME+" has partially eclipsed the sun!\n";
    if(Good==2)
	msg+=MOON3_NAME+" has fully eclipsed the sun!\n";
    else
    if(Good==1)
	msg+=MOON3_NAME+" has partially eclipsed the sun!\n";
    if(Evil==2)
	msg+=MOON2_NAME+" has fully eclipsed the sun!\n";
    else
    if(Evil==1)
	msg+=MOON2_NAME+" has partially eclipsed the sun!\n";
    tell_sky(msg);

    if(sum==6)
    {
	"/command/admin/shutdown"->main("Automatic Shutdown");
	return;
    }
}

static int tell_sky(string message)
{
    object e, o, *all;
    all=users();
    foreach (o in all)
    {
	if(o)
	    e=environment(o);
	if(e&&e->query_star_visibility()>0)
	    tell_object(o,message+"\n");
        /* if (e&&e->query_outdoors()==4)
            tell_object(o,message+"\n"); */
    }
    return 1;
}		

static int check_moon1_sun()
{
    int sun_h, sun_v, moon_h, moon_v;

    sun_h=query_sun_horizontal_sector();
    sun_v=query_sun_vertical_sector();

    moon_h=query_moon1_horizontal_sector();
    moon_v=query_moon1_vertical_sector();

    if(sun_h==moon_h && sun_v==moon_v)
	return 2;
    if(check_near(sun_h, moon_h) && check_near (sun_v, moon_v))
	return 1;
    return 0;
}


static int check_moon2_sun()
{
    int sun_h, sun_v, moon_h, moon_v;

    sun_h=query_sun_horizontal_sector();
    sun_v=query_sun_vertical_sector();

    moon_h=query_moon2_horizontal_sector();
    moon_v=query_moon2_vertical_sector();

    if(sun_h==moon_h && sun_v==moon_v)
	return 2;
    if(check_near(sun_h, moon_h) && check_near (sun_v, moon_v))
	return 1;
    return 0;
}

static int check_moon3_sun()
{
    int sun_h, sun_v, moon_h, moon_v;

    sun_h=query_sun_horizontal_sector();
    sun_v=query_sun_vertical_sector();

    moon_h=query_moon3_horizontal_sector();
    moon_v=query_moon3_vertical_sector();

    if(sun_h==moon_h && sun_v==moon_v)
	return 2;
    if(check_near(sun_h, moon_h) && check_near (sun_v, moon_v))
	return 1;
    return 0;
}

int query_sun_vertical_sector();
int query_moon_phase(int moon_number)
{
    int sector_diff, moon_sector, sun_sector, phase;
    switch (moon_number)
    {
    case 1:
	moon_sector=query_moon1_horizontal_sector();
	break;
    case 2:
	moon_sector=query_moon2_horizontal_sector();
	break;
    case 3:
	moon_sector=query_moon3_horizontal_sector();
	break;
    default:
	return -1;
    }
    sun_sector=query_sun_horizontal_sector();
    sector_diff=sun_sector-moon_sector;
    if (sector_diff<-HORIZONTAL_SECTORS/2)
	sector_diff=sector_diff+HORIZONTAL_SECTORS;
    if (sector_diff>HORIZONTAL_SECTORS/2)
	sector_diff=sector_diff-HORIZONTAL_SECTORS;
    // Negative sector: Moon is growing (waxing?)
    // Positive sector: Moon is becoming smaller (waning?)

    switch (sector_diff)
    {
    case -8..-6:
	phase=3;
	break;
    case -5..-3:
	phase=2;
	break;
    case -2..-1:
	phase=1;
	break;
    case 0:
	phase=0;
	break;
    case 1..2:
	phase=7;
	break;
    case 3..5:
	phase=6;
	break;
    case 6..7:
	phase=5;
	break;
    case 8:
	phase=4;
	break;
    }
    return phase;
}

string query_moon_phase_desc(int phase)
{
    switch (phase)
    {
    case 0:
	return "new";
    case 1:
	return "waxing crescent";
    case 2:
	return "waxing";
    case 3:
	return "waxing gibbous";
    case 4:
	return "full";
    case 5:
	return "waning gibbous";
    case 6:
	return "waning";
    case 7:
	return "waning crescent";
    default:
	return "moonphase error";
    }
}

string query_vertical_desc(int i);
string query_moon_desc(int i);
string query_star_desc()
{
    string msg;
    int i;
    if (query_sun_vertical_sector() < 0)
      msg = "It is night and the sun is not visible. ";
    else
    msg="The sun is "+query_vertical_desc(query_sun_vertical_sector())+". ";
    for (i=1; i<=3;i++)
	msg+=query_moon_desc(i);
    return msg;
}

string query_moon_desc(int moon_number)
{
    string msg, name;
    int v_sec, h_sec, phase;

    switch (moon_number)
    {
    case 1:
	v_sec=query_moon1_vertical_sector();
	h_sec=query_moon1_horizontal_sector();
	name=MOON1_NAME;
	break;
    case 2:
	v_sec=query_moon2_vertical_sector();
	h_sec=query_moon2_horizontal_sector();
	name=MOON2_NAME;
	break;
    case 3:
	v_sec=query_moon3_vertical_sector();
	h_sec=query_moon3_horizontal_sector();
	name=MOON3_NAME;
	break;
    default:
	return "There are not so many moons here in Majik.\n";
    }
    if(v_sec<-2)
	return name+" is not visible.";
    phase=query_moon_phase(moon_number);

    msg=name+"("+query_moon_phase_desc(phase)+") is to the "+
    query_horizontal_desc(h_sec)+
    " and is located "+
    query_vertical_desc(v_sec)+".\n";
    return msg;
}

string query_vertical_desc(int vertical_sector)
{
    switch (vertical_sector)
    {
    case -2:
	return "below horizon";
    case -1:
	return "just below horizon";
    case 0:
	return "at the horizon";
    case 1:
	return "just above horizon";
    case 2..3:
	return "above horizon";
    case 4..5:
	return "well above horizon";
    case 6..7:
	return "almost middle sky";
    case 8..10:
	return "middle sky";
    case 11..12:
	return "above middle sky";
    case 13..14:
	return "well above middle sky";
    case 15..16:
	return "almost directly above you";
    case 17..18:
	return "directly above you";
    default:
	return "well below horizon";
    }
}

string query_horizontal_desc(int horizontal_sector)
{
    if(horizontal_sector<0||horizontal_sector>HORIZONTAL_SECTORS)
	return "nowhere around here";
    switch (horizontal_sector)
    {
    case 0:
    case 16:
	return "east";
    case 1:
	// return "east-southeast";
    case 2:
	return "southeast";
    case 3:
	// return "south-southeast";
    case 4:
	return "south";
    case 5:
	// return "south-southwest";
    case 6:
	return "southwest";
    case 7:
	// return "west-southwest";
    case 8:
	return "west";
    case 9:
	// return "west-northwest";
    case 10:
	return "northwest";
    case 11:
	// return "north-northwest";
    case 12:
	return "north";
    case 13:
	// return "north-northeast";
    case 14:
	return "northeast";
    case 15:
	// return "east-northeast";
    }
}

int query_sun_light()
{
    int sun_v, ecl;
    ecl=query_eclipse();
    sun_v=query_sun_vertical_sector();
    switch (sun_v)
    {
    case -1:
	sun_v=1;
	break;
    case 0:
	sun_v=2;
	break;
    case 1..MAXVERSECTOR:
	sun_v=3;
	break;
    default:
	return 0;
    }
    sun_v=sun_v-ecl;
    if(sun_v<0)
	sun_v=0;
    return sun_v;
}

int query_moon_light()
{
    int illumination;

    illumination=0;
    if(query_moon1_vertical_sector()>0)
	illumination++;
    if(query_moon2_vertical_sector()>0)
	illumination++;
    if(query_moon3_vertical_sector()>0)
	illumination++;
    return illumination;
}

int query_sky_light(int *weather_zone)
{
    int cloud_level, illumination;
    illumination=query_sun_light();
    if(!illumination)
	illumination=query_moon_light();
    illumination=illumination+1; // The everpresent stars
    cloud_level=WEATHER_D->query_cloud_cover(weather_zone);
    illumination=illumination-cloud_level;
    if(illumination<0)
	illumination=0;
    return illumination;
}

string describe_moons()
{
    string msg;

    msg = "";

    if (query_moon1_vertical_sector() > -1)
      {
        msg += "A "+query_moon_phase_desc(query_moon_phase(1))+
          " bright white moon hangs in the "+
          query_horizontal_desc(query_moon1_horizontal_sector())+
          "ern sky "+query_vertical_desc(query_moon1_vertical_sector())+". ";
      }
    if (query_moon2_vertical_sector() > -1)
      {
        msg += "A mysterious "+query_moon_phase_desc(query_moon_phase(2))+
          " red moon hangs in the "+
          query_horizontal_desc(query_moon2_horizontal_sector())+
          "ern sky "+query_vertical_desc(query_moon2_vertical_sector())+". ";
      }
    if (query_moon3_vertical_sector() > -1)
      {
        msg += "A sinister "+query_moon_phase_desc(query_moon_phase(3))+
          " black moon hangs in the "+
          query_horizontal_desc(query_moon3_horizontal_sector())+
          "ern sky "+query_vertical_desc(query_moon3_vertical_sector())+". ";
      }

    return msg;
}

string describe_sun()
{
    string msg;

    if (query_sun_vertical_sector() < 0)
      msg = "It is night and the sun is not visible. ";
    else
      {
        msg="The sun is to the "+
        query_horizontal_desc(query_sun_horizontal_sector())+
        " and "+query_vertical_desc(query_sun_vertical_sector())+". ";
      }

    return msg;
}

string describe_sky()
{
    string msg;
    msg=describe_sun()+
    describe_moons();

    return msg;
}

string query_time_of_day()
{
    int sv, sh;
    string msg;
    msg="It is ";
    sv=query_sun_vertical_sector();
    sh=query_sun_horizontal_sector();
    if(sv>3)
    {
	msg+= "day-time.";
	return msg;
    }
    if(sv<-5)
    {
	msg+="night.";
	return msg;
    }
    if (sh<HORIZONTAL_SECTORS/2)
    {
	msg+="morning.";
	return msg;
    }
    else
	return msg+"evening.";
}
string query_author() { return "aluna";}
