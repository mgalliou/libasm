#include "stdio.h"
#include "string.h"

extern int 	ft__strlen(const char *s);
extern char	*ft__strcpy(char *dst, const char* src);
extern int	ft__strcmp(const char *s1, const char* s2);

int main()
{
	int n;
	char str1[5] = "    ";
	char str2[5] = "test";
	char *str3;

	n = ft__strlen(str2);
	printf("%d\n", n);

	str3 = ft__strcpy(str1, str2);
	printf("%s\n", str1);

	n = ft__strcmp(str3, "tesv");
	printf("%d %d\n", n, strcmp(str3, "text"));
}
