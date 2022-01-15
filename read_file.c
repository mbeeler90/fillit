
#include "fillit.h"

int shape_recognition(char *shape)
{
	int	i;
	char *temp;

	temp = ft_strchr(shape, '#');
	if (temp == 0)
	{
		ft_putstr_fd(2, "invalid file");
		return (-1);
	}
	
	
}

t_list	*read_file(char **argv, int lstlen)
{
	int		fd;
	int		readed;
	char	buff[BUFF_SIZE + 1];

	readed = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	while (readed > 0)
	{
		readed = read(fd, buff, BUFF_SIZE);
		if (readed < 0)
			return (-1);
		if ((shape_recognition(buff)) == -1);
			return (-1);
	}
	return();
}
