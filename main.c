#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

int		main(int argc, char *argv[])
{
	int		fd;
	char	*file_name;
	char	*line;

	file_name = NULL;
	if (argc == 2)
		file_name = argv[1];
	else
		printf("it's more then 1 file as an input!\n");

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);	
	get_next_line(fd, &line);	

	printf("%s\n", line);
	return (0);
}