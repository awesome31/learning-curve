# Introduction to Linux and CLI

## Introduction

### What is Unix?

Unix was an operating system based on the Unix philosophy. The Unix philosophy is to write one program that does one thing and does it well. Each program's output can be the input to another program.

### What is Linux?

Linux is a UNIX-inspired operating system. It's not a fork of the UNIX codebase but a new codebase that is based on the UNIX philosophy with a lot of additional features. Linux is free and open source, and many companies offer Linux-based services. There are a lot of distros of Linux. Each distro uses the Linux kernel, but each distro also has its own set of applications and software packages.

## The CLI

### List of Commands You Should Know

1. `pwd`: Print working directory
2. `ls`: List the contents of the current directory
3. `cd`: Change the current directory
4. `cat`: Display the contents of a file
5. `cp`: Copy a file
6. `mv`: Move a file
7. `rm`: Remove a file
8. `mkdir`: Create a directory
9. `rmdir`: Remove a directory
10. `echo`: Display a message
11. `which`: Find the location of a command
12. `!!`: Repeat the last command
13. `printenv`: Display environment variables
14. `ps`: Display processes

### Anatomy of CLI

1. **Shell**: This is most probably Bash or Zsh.
2. **Emulator app**: This is the app that runs the shell. Examples are Warp, Terminal, and iTerm.
3. **Filesystem**: You are always somewhere inside a file system inside a Linux operating system.

### CLI Directories and Arguments

1. `~`: This is the home directory of the current user.
2. `.`: This is the current directory.
3. `..`: This is the parent directory.

Arguments are inputs that we can pass to the command-line program. They are separated by spaces.

### Flags

A flag is a boolean value that can be passed to a command. A flag takes no argument, and its only purpose is to modify the behavior of the command. Flags are separated by spaces. We can create hidden files with the `.` keyword. The order in which the flag is written sometimes matters.

### CLI Search

Up and down arrows to search through history. Tab completions have to be provided by the program itself. Do not assume that the shell will provide you with tab completions. We can do `CTRL+R` to search through the history.

### Bash History / ZSH History

We can see the Bash/Zsh history by checking the `.zsh_history` or `.bash_history` file in the home directory.

## Environments and Processes

### Environment Variables

Environment variables store configuration settings for the shell and programs. Common environment variables include:

- `PATH`: Directories where executables are searched.
- `HOME`: User’s home directory.
- `USER`: Current logged-in user.
- `SHELL`: Default shell in use.
- `EDITOR`: Preferred text editor.

### Managing Processes

A process is an instance of a running program. Key process management commands:

- `ps`: Display currently running processes.
- `top`: Display system-wide process statistics.
- `htop`: Interactive process viewer.
- `kill <PID>`: Terminate a process.
- `pkill <name>`: Kill processes by name.
- `jobs`: List background jobs.
- `bg`: Resume a process in the background.
- `fg`: Bring a process to the foreground.
- `nohup <command>`: Run a command immune to hangups.

### Customizing the Environment

- `.bashrc`, `.bash_profile`, `.zshrc`: Configuration files for shell settings.
- `export VAR=value`: Set environment variables for the session.
- `alias ll='ls -lah'`: Create command aliases.

## SSH (Secure Shell)

### Introduction to SSH

SSH is a protocol for securely connecting to remote systems over a network. It encrypts all communications, making remote access safe.

### Setting Up SSH Keys

1. Generate an SSH key pair:
   ```bash
   ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
   ```
2. Copy the public key to a remote server:
   ```bash
   ssh-copy-id user@remote-server
   ```
3. Connect to the server:
   ```bash
   ssh user@remote-server
   ```
