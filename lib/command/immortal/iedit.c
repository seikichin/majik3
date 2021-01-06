/*
 * Item Editor v1.0                     (c) Dazzt
 * 
 * 
 * */


int main (string str)
{
	object ob;
	
	if (!str)
	{
		notify_fail("usage: iedit <filename.c>");
		return 0;
	}
	
	if (str[<2..<1] != ".c")
		str += ".c";

	ob = clone_object("/obj/iedit_ob");
	ob->main(str);
	return 1;
}
