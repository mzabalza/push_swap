
#include "get_next_line.h"

int main()
{
	char *line;

	while (get_next_line(0, &line))
{
	// process the line here, here we'll just output it
	ft_putendl(line);
	
	// free the line to avoid leaking memory
	ft_strdel(&line);
}
write(1,"adios",5);

	return (1);
}

