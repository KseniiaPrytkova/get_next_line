# get_next_line

This project is about function, that reads a line ending with a newline character from a file descriptor. The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively. Function get_next_line returns its result without ’\n’.

Calling this function in a loop will then allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

The implementation of this project can be conditionally divided into 2 stages (solely from my point of view):

# 1) read the whole file into a string (how to?)

Initially it was not obvious to me that reading the file into a string can not be done directly (and without using standard functions). What i mean? It is impossible for example to output the whole string directly on the standart output if you are not allowed to use printf(). In this case you need to use putcar() (this fn simply uses system call write(2)) in the loop and output the string character by character (in the context of C language). So.. Due to the fact that it was necessary to come up with an algorithm for the realization of this task (putting the file into the string), I could not find a specific answer in Google (I wanted to find something like step-by-step instruction). For those who will face such a problem in the future and will be confused, I dicided to write my own instruction, perhaps it will make someone happier or at least improve digestion.

## 1.1 main.c
``` C
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

int			main(int argc, char *argv[])
{
	int		fd;
	char	*file_name;
	char	*line;

	file_name = NULL;
	if (argc == 2)
		file_name = argv[1];
	else
		printf("ERROR:there are more than one file as an input!\n");
	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	return (0);
}
```