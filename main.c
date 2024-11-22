#include "get_next_line_bonus.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	int o1 = open("test1.txt", O_RDONLY);
	int o2 = open("test2.txt", O_RDONLY);
	char *str;

	printf("%s", get_next_line(o1));
	printf("%s", get_next_line(o2));
	printf("%s", get_next_line(o1));
	printf("%s", get_next_line(o2));
	printf("%s", get_next_line(o1));
	printf("%s", get_next_line(o2));
	printf("%s", get_next_line(o1));
	printf("%s", get_next_line(o2));
	printf("%s", get_next_line(o1));
	printf("%s", get_next_line(o2));
}
