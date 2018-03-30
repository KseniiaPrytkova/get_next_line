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
	int		ret;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if (argc > 0)
	{
		// file_name = NULL;
		// file_name = argv[1];
		// get_next_line(fd1, &line);
		// printf("%s\n", line);
		// close(fd1);
		// get_next_line(fd1, &line);
		// printf("%s\n", line);

		// get_next_line(fd1, &line);
		// get_next_line(fd2, &line);
		// get_next_line(fd2, &line);
		// get_next_line(fd1, &line);
	}
	if (argc == 3)
	{
		while ((ret = get_next_line(fd1, &line)))
		{
			printf("(FD:%i)(ret:%i)line:%s\n", fd1, ret, line);
			ft_strdel(&line);
			while ((ret = get_next_line(fd2, &line)))
			{
				printf("(FD:%i)(ret:%i)line:%s\n", fd2, ret, line);
				ft_strdel(&line);
			}
		}
	}
	// close(fd1);
	// close(fd2);
	ft_strdel(&line);
	ret = get_next_line(fd1, &line);
	ft_strdel(&line);
	ret = get_next_line(fd2, &line);
	printf("====>(FD:%i)(ret:%i)line:%s\n", fd1, ret, line);

	printf("====>(FD:%i)(ret:%i)line:%s\n", fd2, ret, line);

	system("leaks -quiet test");
	return (0);
}
