#include <skill.h>

mapping allskill;


create()
{
    f_create_skillmap();
}

get()
{
    return 1;
}


init()
{
    add_action("cmd_path","path");
    add_action("cmd_child","child");
    add_action("cmd_tree","tree");
}
f_find_parent(skillname)
{
    int i;
    string *key, *val;
    return allskill[skillname];
    key=keys(allskill);
    val=values(allskill);
    i=member_array(skillname,key);
    if(i>=0)
	return val[i];
    return "";
}
cmd_path(skill_name)
{
    string parent;
    if(!skill_name)
    {
	write("You need to give a skill name as an argument.\n");
	return 1;
    }
    write(skill_name+"\n");
    parent=f_find_parent(skill_name);
    while(parent!="")
    {
	write(parent+"\n");
	parent=f_find_parent(parent);
    }
    return 1;
}

cmd_tree(skill_name)
{
    if(!skill_name)
    {
	write("You need to give a skill name as an argument.\n");
	return 1;
    }
    f_print_tree(skill_name,1);
    return 1;
}

f_find_skill(skill_name)
{
    return load_object(SKILLDIR+skill_name);
}

f_dumpit()
{
    int i;
    string *key, *val;
    key=keys(allskill);
    val=values(allskill);
    for(i=0;i<sizeof(key);i++)
	write(key[i]+":"+val[i]+"\n");
}

f_remove_c(skill_name)
{
    int i;
    string tmp;
    i=sscanf(skill_name,"%s.c",tmp);
    if(i)
	return tmp;
    return skill_name;
}

f_create_skillmap()
{
    string *dir, parent;
    int i;
    object o;
    allskill=([]);
    dir=get_dir(SKILLDIR);
    for(i=0;i<sizeof(dir);i++)
    {
	o=f_find_skill(dir[i]);
	if(o)
	{
	    parent=o->query_parent_skill();
	    if(parent)
		allskill[f_remove_c(dir[i])]=parent;
	}
    }
}

f_find_children(skill_name)
{
    int i;
    string *child, *key, *val, tmp;
    child=({});
    key=keys(allskill);
    val=values(allskill);

    for (i=0; i<sizeof(key); i++)
    {
	if(val[i]==skill_name)
	{
	    sscanf(key[i],"%s.c",tmp);
	    if(tmp)
		child+=({key[i]});
	    else
		child+=({key[i]});
	}
    }
    return child;
}

f_print_tree(skill_name, depth)
{
    string *child;
    int i;
    child=f_find_children(skill_name);
    for (i=0; i<depth; i++)
	write("-");
    write(skill_name+"\n");
    if(sizeof(child)>0&&depth<6)
	for (i=0;i < sizeof(child); i++)
	{
	    f_print_tree(child[i],depth+1);
	}
    return 1;
}

cmd_child(skill_name)
{
    int i;
    string *child;
    if(!skill_name)
    {
	write("You need to give a skill as an argument.\n");
	return 1;
    }
    child=f_find_children(skill_name);
    if(sizeof(child)<1)
    {
	write(skill_name+" has no children.\n");
	return 1;
    }
    write("The children of "+skill_name+" are:\n");
    for (i=0;i<sizeof(child);i++)
	write(child[i]+"\n");
    return 1;
}


cmd_skill_child(skill_name)
{
    string *dir, *child;
    int i;
    object o;
    dir=get_dir(SKILLDIR);
    child=({});
    if(!f_find_skill(skill_name))
    {
	write("No such skill.\n");
	return 1;
    }
    for (i=0;i<sizeof(dir);i++)
    {
	o=f_find_skill(dir[i]);
	if(o&&o->query_parent_skill()==skill_name)
	    child+=({dir[i]});
    }
    return child;
}
