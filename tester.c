#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
int	main()
{
	char	str[10];
	int		fd = open("file.txt", O_RDONLY);
	printf("%ld\n", read(fd, str, 10));
	printf("%ld\n", read(fd, str, 10));
	printf("%ld\n", read(fd, str, 10));
	close(fd);
}