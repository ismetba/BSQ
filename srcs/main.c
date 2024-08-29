#include "../includes/file_ops.h"
#include <unistd.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	char **map = read_file(argv[1]);

	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[j])
			j++;
		write(1, map[i], j);
		write(1, "\n", 1);
		i++;
	}
}
