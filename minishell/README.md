# minishell
To-do list.
Vita:

Arch:
- norm (for now skip init.c, ft_cd.c, file_manager1.c, free_utils1.c)

(old)To-do list:
1) Divide on logical groups/tokens (lexer thing);
2) Check for errors in logical groups (for example syntax error, ”/’/) missing);
3) Check tokens and word expansion (“...”, $VAR) (parser thing);
4) Run command (execution thing):  
	4.1) If not a built-in command, we run the child process and execute command;  
	4.2) If it is a built-in command, we don’t run the child process but execute it in the parent one.  
5) ???
6) Profit. 

Types of tokens:
1) separator (all that is true for is_space());
2) word/command (for example ls, cat e.t.c. “” counts as an empty string);
3) field (‘...’);
4) expandable field (“...”);
5) redirection:  
	5.1) < should redirect input;  
	5.2) > should redirect output;  
	5.3) << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history;  
	5.4) >> should redirect output in append mode.  
6) pipe (|);
7) braces ((, ));
8) dollar sign (to handle env variables ($VAR) and $? for expanding the exit status of the most recently executed foreground pipeline);
9) if-and (&&) (bonus part);
10) if-or (||) (bonus part).

Things to handle:
1) Display a prompt when waiting for a new command;
2) Have a working history;
3) Search and launch the right executable (based on the PATH variable or using a relative or an absolute path); 
4) Avoid using more than one global variable to indicate a received signal
5) ctrl-C displays a new prompt on a new line; 
6) ctrl-D exits the shell;
7) ctrl-\ does nothing;
8) Wildcards * (bonus part);

Built-ins:
1) echo with option -n;
2) cd with only a relative or absolute path;
3) pwd with no options;
4) export with no options;
5) unset with no options;
6) env with no options or arguments;
7) exit with no options.