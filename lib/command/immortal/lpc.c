int main (string str)
{
  string file, err;
  mixed ret;
  object ob;

  if (!str)
    {
      write ("usage   : lpc <lpc string>\n");
      write ("example : lpc this_player()->query_name()\n");
      return 1;
    }

  file = "/home/" + this_player()->query_name() + "/_lpc.c";
  if(ob = find_object(file)) destruct(ob);
  rm (file);

  write_file (file, "_lpc() { return " + str + "; }\n");

  err = catch(ret = (mixed) call_other(file, "_lpc"));
  if (err) 
    err = replace_string (err, "\n", " ");

  if(ob = find_object(file)) destruct(ob);

  if (err)
    write ("= (error) "+err[1..]+"\n");
  else if (pointerp (ret)) {
    write ("= (array) "+sprintf("%O", ret)+"\n");
  }
  else if (mapp (ret)) {
    write ("= (mapping) "+sprintf("%O", ret)+"\n");
  }
  else if (objectp (ret)) {
    write ("= (object) ");
    write (sprintf("%O", ret));
    write ("\n");
  }
  else if (intp (ret))
    write ("= (int) " + sprintf("%O", ret) + "\n");
  else if (stringp (ret)) {
    write ("= (string) /* strlen() == "+strlen(ret)+" */\n");
    write (sprintf("%O", ret));
    write ("\n");
  }
  else
    write ("= (unknown type) " + sprintf("%O", ret) + "\n");  

  rm (file);

  return 1;
}
