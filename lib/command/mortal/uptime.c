#include "/home/mordoc/include/time.c"

int main () {
    write("Majik has been running for ");
    write(format_time(uptime())+".\n");
    return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "Tells how long Majik has been running.";
}

query_see_also()
{
  return "cpu(1)";
}
query_position()
{
  return POS_RESTING;
}

