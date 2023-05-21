#ifndef BUILT_IN_H_
#define BUILT_IN_H_

extern char *built_ins[];
extern int (*built_in_func[]) (char **);

int len_built_ins();
int cd(char **args);
int help(char **args);
int exit_shell(char **args);

#endif
