#include "stdio.h"

extern int ft__strlen(const char *s);

int main()
{
	int n;

	n = ft__strlen("test");
	printf("%d", n);
}
