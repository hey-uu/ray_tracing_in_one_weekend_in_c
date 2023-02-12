cd src;
ls | cut -f 1 -d "." | xargs printf "%s\\\\\n\t\t\t\t\t\t\t\t"> ../script/src_list;

