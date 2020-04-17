/**
 * @file shell.c
 * 
 * @brief simple shell in C that reads, parses, executes
 * some commands using fork() & execvp().
 * 
 * @author a-qxin
 * 
 */

#include <stdio.h> // printf, gets
#include <sys/types.h> // pid_t

#define BUFF 1024
#define CMD_LEN 64

/**
 *  parses input into tokens; replaces whitespaces with 0
 *  saves address to argv[] at non-whitespace char, 
 *  skips to whitespace and repeat.
 *  @param line user input to parse
 *  @param argv list of parsed arg tokens to create
 */

void parse(char *line, char **argv)
{
    while (*line != '\0') {         // if not end of line
        while (*line == ' ' || *line == '\t' || *line == '\n')
            *line++ = '\0';         // replace white spaces with 0
        *argv++ = line;             // save arg position
        while (*line != '\0' && *line != ' '
            && *line != '\t' && *line != '\n')
            line++;                 // skip arg until...
    }
    *argv = '\0';                   // mark arg list end
}

/**
 *  forks() child process then calls execvp() to execute
 *  each command in argv.
 *  @param argv list of parsed arg tokens from parse()
 */

void execute(char **argv){
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {       // fork a child
        printf("error: forking child failed\n");
        exit(1);
    }
    else if (pid == 0) {            // for child
        if (execvp(*argv, argv) < 0) { // execute the command!
            printf("error: exec failed\n");
            exit(1);
        }
    }
    else {                          // for parent
        while (wait(&status) != pid) // wait child fin after ea cmd
            ;
        // printf("Child %d, exited with %d\n", pid, status);
    }
}

int main(int argc, char **argv)
{
    char line[BUFF];                // input line; 1024 byte buffer
    char *arg[CMD_LEN];             // cmd line arg input

    // assignment-specific: custom prompt prefix argv[1]
    // default (no arg) use '>'
    if (argv[1] == '\0')
        argv[1] = ">";

    while (1) {  
        printf("%s ",argv[1]);      // display prompt
        gets(line);                 // read in
        parse(line, arg);
        if (arg[0] == '\0')         // error and exit on empty input
        {
            // printf("error: empty line. no input detected.\n");
            continue;
        }
        if (strcmp(arg[0], "exit") == 0) { // compare strings to see if "exit"
            exit(0);
        }
        execute(arg);
    }
    return 0;
}
