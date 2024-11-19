#include "get_next_line.h"

int main()
{
	int o;

	o = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(o));
	printf("%s", get_next_line(o));
	printf("%s", get_next_line(o));
}
