#ifndef GET_NEXT_LINE_FL_H
# define GET_NEXT_LINE_FL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 17
// # define MAX_FILES 4864

int		get_next_line_fl(const int fd, char **line);

#endif
