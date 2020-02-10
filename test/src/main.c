#include "tests.h"
#include "stdio.h"
#include "string.h"

int main()
{
	/*
	int n;
	char str1[5] = "    ";
	char str2[5] = "test";
	char *str3;
	char *str4;
	*/

	RUN_TEST_SUITE(suite_ft_strlen);
	RUN_TEST_SUITE(suite_ft_strcpy);
	RUN_TEST_SUITE(suite_ft_strdup);
	RUN_TEST_SUITE(suite_ft_strchr);

	/*
	n = ft__strlen(str2);
	printf("%d\n", n);

	str3 = ft__strcpy(str1, str2);
	printf("%s\n", str1);

	n = ft__strcmp(str3, "tesv");
	printf("%d %d\n", n, strcmp(str3, "tesv"));

	ft__write(1, str1, ft__strlen(str1));
	printf("\n");

	str4 = ft__strdup(str3);
	printf("%s\n", str4);
	*/
}
