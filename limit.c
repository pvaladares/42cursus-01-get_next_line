#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	main(void)
{
	printf("Limit = [%d]\n", STDERR_FILENO);
}
