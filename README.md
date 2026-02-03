# Project Overview

You are tasked with writing your own Unix shell called hsh that behaves like /bin/sh. The shell must:
Work interactively (user types commands) and non-interactively (commands piped in).
Execute commands found in the PATH.
Handle errors in the same way sh does, but print the program name as argv[0].
Avoid memory leaks and follow Betty style.
Use only the allowed functions and system calls.

# Learning Objectives

By the end, you should be able to explain:

> Unix history & creators:

> Original Unix: Ken Thompson and Dennis Ritchie.

> First Unix shell: Ken Thompson.

> B language: Ken Thompson (predecessor of C).

# Shell concepts:

What a shell is and how it works.

PID (process ID) and PPID (parent process ID).

Environment manipulation.

Difference between function and system call.

How to create and manage processes (fork, execve, wait).

How PATH is used to locate executables.

EOF (end-of-file) concept.

# C programming / process control:

> main prototypes:

int main(void);
int main(int argc, char *argv[]);
int main(int argc, char *argv[], char *envp[]);


System calls for process creation and execution.

Suspending execution until a child process terminates (wait, waitpid).

How to execute another program (execve).

# Technical Requirements

Editors: vi, vim, or emacs.

Compiler: gcc on Ubuntu 20.04, options -Wall -Werror -Wextra -pedantic -std=gnu89.

File rules: Each file must end with a newline, no more than 5 functions per file, header guards in headers.

Code style: Betty style enforced with betty-style.pl and betty-doc.pl.

Memory: No memory leaks.

# Allowed Functions / System Calls

Here are the key ones you’ll likely use frequently:

Process creation / execution: fork, execve, wait, waitpid, _exit.

File and directory operations: open, close, opendir, readdir, getcwd, chdir, stat, lstat.

I/O: read, write, printf, fprintf, putchar, getline.

String manipulation: functions from string.h, strtok.

Signals: signal, kill.

