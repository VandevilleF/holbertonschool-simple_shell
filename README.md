## Simple Shell

Description : Simple shell is a simplified version of the shell Linux.
## Description

This project is part of the formation of Holberton School. <br>
It's a simplified shell Linux


## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


## Requirements

- Ubuntu 20
- GCC


## Usage/Examples
Type a command on terminal; in interactive mode…
```code
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

```
…or in non-interactive mode :
```code
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
![Logo](https://github.com/VandevilleF/holbertonschool-simple_shell/blob/main/HBTN_Flowchart/Flow-chart_SimpleShell.png)

## AUTHORS

• Florian Vandeville @Florian Vandeville <br>
• Florent Fouquet @florent1711