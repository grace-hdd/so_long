#include "include/utils.h"

char *get_next_line(int fd)
{
    static char buffer[BUFSIZ];
    static int pos = 0;
    static int size = 0;
    char *line = NULL;
    int i = 0;
    
    while (1)
    {
        if (pos >= size)
        {
            size = read(fd, buffer, BUFSIZ);
            pos = 0;
            if (size <= 0)
                return (line);
        }
        
        if (buffer[pos] == '\n')
        {
            if (line)
            {
                char *new_line = safe_malloc(i + 2);
                int j = 0;
                while (j < i)
                {
                    new_line[j] = line[j];
                    j++;
                }
                free(line);
                line = new_line;
            }
            else
                line = safe_malloc(i + 2);
            line[i] = '\n';
            line[i + 1] = '\0';
            pos++;
            return (line);
        }
        
        if (line)
        {
            char *new_line = safe_malloc(i + 2);
            int j = 0;
            while (j < i)
            {
                new_line[j] = line[j];
                j++;
            }
            free(line);
            line = new_line;
        }
        else
            line = safe_malloc(i + 2);
        line[i] = buffer[pos];
        i++;
        pos++;
    }
}
