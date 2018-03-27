#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

int		main(int argc, char *argv[])
{
	int		fd1;
	int		fd2;
	int 	diff_file_size;
	char	*file_name;
	char	*line;
	char    buff[10];

	if (argc > 0)
	{
		file_name = NULL;
		file_name = argv[1];
		fd1 = open(file_name, O_RDONLY);
		fd2 = open("one_big_fat_line.diff", O_RDONLY);
		diff_file_size = read(fd2, NULL, 10);
		printf("%d\n", diff_file_size);
		//printf("open:%d\n", fd1);
		//printf("closed:%d\n",fd1 );
		//get_next_line(fd1, &line);	

		//fd2 = open(argv[2], O_RDONLY);
		//get_next_line(fd2, &line);
		// get_next_line(fd2, &line);
		//get_next_line(fd1, &line);
		//get_next_line(fd1, &line);
		//get_next_line(fd1, &line);
		//printf("%d\n", get_next_line(fd1, &line));
	}

	return (0);
}
