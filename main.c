#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int		main(int argc, char *argv[])
{
	int		fd1;
	int		fd2;
	char	*file_name;
	char	*line;

	if (argc > 0)
	{
		file_name = NULL;
		file_name = argv[1];
		fd1 = open(file_name, O_RDONLY);
		get_next_line(fd1, &line);
		write(1, line, strlen(line));
		write(fd2, "\n", 1);
		if (line)
			write(1, line, strlen(line));
		close(fd1);

		// get_next_line(fd1, &line);

		// close(fd1);
		// if (close(fd1) == -1)
		// {
		// 	ft_putstr("close() error");
		// 	return (0);
		// }


		// get_next_line(fd1, &line);
		// fd2 = open(argv[2], O_RDONLY);
		// get_next_line(fd2, &line);
		// get_next_line(fd2, &line);
		// get_next_line(fd1, &line);
		//printf("%s\n", line);
	}

	return (0);
}
