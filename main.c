#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int o = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(o));
	printf("%s", get_next_line(o));
	printf("%s", get_next_line(o));
	printf("%s", get_next_line(o));
	printf("%s", get_next_line(o));
	printf("%s", get_next_line(o));
	printf("%s", get_next_line(o));
	printf("%s", get_next_line(o));
}
