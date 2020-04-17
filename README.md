# simple-c-shell

Simple Linux shell in C that reads, parses, then executes simple shell commands.

`fork()` creates new processes, `execvp()` executes commands.

#### CLONE

Clone this repo to your local machine using 
```
git clone https://github.com/a-qxin/csc415.git
```

#### SETUP/RUN

```
gcc -o shell shell.c

./shell
```
Use like any shell.

Examples: ```ls```, ```pwd```, ```mkdir <new folder name>```

CTRL-C to quit.

---

##### RESOURCES USED

[vim/C basics](http://www.cs.cornell.edu/courses/cs113/2006fa/Write_Your_First_C_Program.html)

[print in c](https://www.tutorialspoint.com/cprogramming/c_input_output.htm)

[argc, argv, etc](https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean)

[fgets()](https://www.geeksforgeeks.org/fgets-gets-c-language/)

[fgets() 2](https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm)
 
[shell in C using fork() and execvp()](https://danrl.com/blog/2018/how-to-write-a-tiny-shell-in-c/)

[shell in C using fork() and execvp() 2](https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/)

[POSIX exec function family](https://pubs.opengroup.org/onlinepubs/9699919799/)

[(char*)0 vs. NULL](https://stackoverflow.com/questions/37099570/execv-what-is-char-0-in-c?noredirect=1&lq=1)

[execvp()](http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html)

[exit status 256](https://stackoverflow.com/questions/3736320/executing-shell-script-with-system-returns-256-what-does-that-mean)

[exit status 256 with WEXITSTATUS](https://stackoverflow.com/questions/808541/any-benefit-in-using-wexitstatus-macro-in-c-over-division-by-256-on-exit-statu)

[documentation, as always](https://developer.lsst.io/cpp/api-docs.html)

[markdown cheatsheet for readme formatting](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)