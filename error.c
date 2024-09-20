#include "fdf.h"

void	ft_exit(char *str)
{
	if (errno == 0)
	{
		ft_putstr_fd("\n", 2);
		ft_putendl_fd(str, 2);
	}
	else
		perror(str);
	exit(1);
}
