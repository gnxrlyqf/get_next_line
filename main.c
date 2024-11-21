#include "get_next_line.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	int o = open(av[1], O_RDONLY);
	char *str;

	while (1)
	{
		str = get_next_line(o);
		if (!str)
		{
			free(str);
			break ;
		}
		printf("%s", str);
		free(str);
	}
}
