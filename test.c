#include <stdio.h>
#include <errno.h>

int main()
{
	errno = 12;
	perror("miniRT: ft_calloc2");
	return (0);
}
