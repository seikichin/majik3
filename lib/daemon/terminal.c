// file name   : /daemon/terminal.c
// description : terminal daemon, called from receive_message() function
// coder       : namhas

static mapping term_info;

void
create ()
{
  term_info = ([ "ansi" : // standard ansi capatible terminal (8/16 color)
              ([
                 "^c0" : "\e[0m",    "^c1" : "\e[1m",    "^c2" : "\e[3m",
                 "^c3" : "\e[4m",    "^c4" : "\e[5m",    "^c5" : "\e[7m",
                 "^c6" : "\e[8m",
                 "^cl" : "\e[30m",   "^cr" : "\e[31m",   "^cg" : "\e[32m",
                 "^cy" : "\e[33m",   "^cb" : "\e[34m",   "^cp" : "\e[35m",
                 "^cc" : "\e[36m",   "^cw" : "\e[37m",
                 "^cL" : "\e[1;30m", "^cR" : "\e[1;31m", "^cG" : "\e[1;32m",
                 "^cY" : "\e[1;33m", "^cB" : "\e[1;34m", "^cP" : "\e[1;35m",
                 "^cC" : "\e[1;36m", "^cW" : "\e[1;37m",
                 "^bl" : "\e[40m",   "^br" : "\e[41m",   "^bg" : "\e[42m",
                 "^by" : "\e[43m",   "^bb" : "\e[44m",   "^bp" : "\e[45m",
                 "^bc" : "\e[46m",   "^bw" : "\e[47m",
              ]),
                "xterm" : // xterm terminal emulation support
              ([
                 "^c0" : "\e[0m",    "^c1" : "\e[1m",    "^c2" : "\e[3m", 
                 "^c3" : "\e[4m",    "^c4" : "\e[5m$<2>","^c5" : "\e[7m",
                 "^c6" : "\e[8m",
                 "^cl" : "\e[30m",   "^cr" : "\e[31m",   "^cg" : "\e[32m",
                 "^cy" : "\e[33m",   "^cb" : "\e[34m",   "^cp" : "\e[35m",
                 "^cc" : "\e[36m",   "^cw" : "\e[37m",
                 "^cL" : "\e[1;30m", "^cR" : "\e[1;31m", "^cG" : "\e[1;32m",
                 "^cY" : "\e[1;33m", "^cB" : "\e[1;34m", "^cP" : "\e[1;35m",
                 "^cC" : "\e[1;36m", "^cW" : "\e[1;37m",
                 "^bl" : "\e[40m",   "^br" : "\e[41m",   "^bg" : "\e[42m", 
                 "^by" : "\e[43m",   "^bb" : "\e[44m",   "^bp" : "\e[45m",
                 "^bc" : "\e[46m",   "^bw" : "\e[47m",
              ]),
                "html" : // 256 color html
              ([
                 "^c0" : "#efefef",  "^c1" : "#ffffff",  "^c2" : "",
                 "^c3" : "",         "^c4" : "",         "^c5" : "",
                 "^c6" : "#000000",
                 "^cl" : "#000000",  "^cr" : "#ee0000",  "^cg" : "#007000",
                 "^cy" : "#eedd00",  "^cb" : "#0000ed",  "^cp" : "#700070",
                 "^cc" : "#00ef00",  "^cw" : "#efefef",
                 "^cL" : "#000000",  "^cR" : "#ff0000",  "^cG" : "#008000",
                 "^cY" : "#ffff00",  "^cB" : "#0000ff",  "^cP" : "#800080",
                 "^cC" : "#00ff00",  "^cW" : "#ffffff",
                 "^bl" : "",         "^br" : "",         "^bg" : "",
                 "^by" : "",         "^bb" : "",         "^bp" : "",
                 "^bc" : "",         "^bw" : "",
              ]),
                "vt100" : // standard vt100 terminal type
              ([
                 "^c0" : "\e[0m",    "^c1" : "\e[1m",    "^c2" : "\e[3m",
                 "^c3" : "\e[4m",    "^c4" : "",         "^c5" : "\e[7m",
                 "^c6" : "\e[8m",
                 "^cl" : "",         "^cr" : "",         "^cg" : "",
                 "^cy" : "",         "^cb" : "",         "^cp" : "",
                 "^cc" : "",         "^cw" : "",
                 "^cL" : "\e[1m",    "^cR" : "\e[1m",    "^cG" : "\e[1m",
                 "^cY" : "\e[1m",    "^cB" : "\e[1m",    "^cP" : "\e[1m",
                 "^cC" : "\e[1m",    "^cW" : "\e[1m",
                 "^bl" : "\e[7m",    "^br" : "\e[7m",    "^bg" : "\e[7m",
                 "^by" : "\e[7m",    "^bb" : "\e[7m",    "^bp" : "\e[7m",
                 "^bc" : "\e[7m",    "^bw" : "\e[7m",
              ]),
                "unknown" : // unknown terminal type, no colors
              ([
                 "^c0" : "",         "^c1" : "",         "^c2" : "",
                 "^c3" : "",         "^c4" : "",         "^c5" : "",
                 "^c6" : "",
                 "^cl" : "",         "^cr" : "",         "^cg" : "",
                 "^cy" : "",         "^cb" : "",         "^cp" : "",
                 "^cc" : "",         "^cw" : "",
                 "^cL" : "",         "^cR" : "",         "^cG" : "",
                 "^cY" : "",         "^cB" : "",         "^cP" : "",
                 "^cC" : "",         "^cW" : "",
                 "^bl" : "",         "^br" : "",         "^bg" : "",
                 "^by" : "",         "^bb" : "",         "^bp" : "",
                 "^bc" : "",         "^bw" : "",
              ]) ]);
}

mapping
query_term_info (string type)
{
  return (term_info[type] ? term_info[type] : term_info["unknown"]);
}

string *
query_terms ()
{
  return keys(term_info);
}

int
query_term_support (string str)
{
  return (term_info[str] ? 1 : 0);
}
