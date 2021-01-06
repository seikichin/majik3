/*      exits.c, shows all obvius exits in room and the files they are
	connected to. If the file doesnt exist or its unreadable for some
	reason it will be marked as bad.

	CODER Zimbe
*/

int main() {
    string *dests, *dirs;
    int i;

    dests=ENV(THIS)->query_exit_dest();
    dirs=ENV(THIS)->query_exit_dir();

    message("normal","^cb"+sprintf("%-10s %-58s %s\n\n","File",
	"Exit","Status")+"^c0",THIS);

    for(i=0;i<sizeof(dests);i++) {
	message("normal","^cw^c1"+sprintf("%-10s %-62s",dirs[i],
	    dests[i]+"^c0"),THIS);
	if(file_size(dests[i]+".c")>0)
	    message("normal","^c1[^cgO^cw^c1]\n^c0",THIS);
	else if(file_size(dests[i]+".c")==-1)
	    message("normal","^c1[^crB^cw^c1]\n^c0",THIS);
	else if(file_size(dests[i]+".c")==-2)
	    message("normal","^c1[^cyD^cw^c1]\n^c0",THIS);
    }
    message("normal","\nFile ok : ^c1[^cgO^cw^c1]^c0, Bad or not " +
      "readable : ^c1[^crB^cw^c1]^c0, Dir : ^c1[^cyD^cw^c1]^c0\n\n",THIS);
    return 1;
}
