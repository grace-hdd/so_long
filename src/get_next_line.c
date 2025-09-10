#include "include/utils.h"
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	static char buffer[BUFSIZ];
	static int pos = 0;
	static int size = 0;
	char *line;
	int i;
	int start;

	line = NULL;
	i = 0;
	start = pos;
	while (1)
	{
		if (pos >= size)
		{
			size = read(fd, buffer, BUFSIZ);
			pos = 0;
			start = 0;
			if (size <= 0)
				return (line);
		}
		if (buffer[pos] == '\n')
		{
			line = safe_malloc(i + 2);
			pos = start;
			while (pos < size && buffer[pos] != '\n')
			{
				line[pos - start] = buffer[pos];
				pos++;
			}
			line[pos - start] = '\n';
			line[pos - start + 1] = '\0';
			pos++;
			return (line);
		}
		pos++;
		i++;
	}
}
