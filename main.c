#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_LEN 256

extern int  ft_strlen(const char *s);
extern char *ft_strcpy(char *dst, const char* src);
extern int  ft_strcmp(const char *s1, const char* s2);
extern int  ft_write(int fildes, const void* buf, size_t nbyte);
extern int  ft_read(int fildes, const void* buf, size_t nbyte);
extern char *ft_strdup(const char *s1);

static void remove_newline(char *s)
{
	char *c;

	c = strrchr(s, '\n');
	if (c)
		*c = 0;
}

static void ft_putstr(char *s)
{
	ft_write(0, s, ft_strlen(s));
}

int main(void)
{
	char buf[BUF_LEN];
	char buf2[BUF_LEN];
	char *s1;
	char *s2;
	int  n;

	ft_putstr("Write a string to test ft_strlen:\n");
	bzero(buf, BUF_LEN);
	ft_read(0, buf, BUF_LEN - 1);
	remove_newline(buf);
	printf("ft_strlen returned: %d\n", ft_strlen(buf));

	ft_putstr("\nWrite a string to test ft_strcpy:\n");
	bzero(buf, BUF_LEN);
	ft_read(0, buf, BUF_LEN - 1);
	remove_newline(buf);
 	s1 = ft_strcpy(buf2, buf);
	printf("ft_strcopy return: \"%s\"\n", s1);

	ft_putstr("\nWrite two strings to test ft_strcmp:\n");
	bzero(buf, BUF_LEN);
	ft_read(0, buf, BUF_LEN - 1);
	remove_newline(buf);
	bzero(buf2, BUF_LEN);
	ft_read(0, buf2, BUF_LEN - 1);
	remove_newline(buf2);
	n = ft_strcmp(buf, buf2);
	printf("ft_strcmp returned: \"%d\"\n", n);

	ft_putstr("\nWrite a string to test ft_strdup:\n");
	bzero(buf, BUF_LEN);
	ft_read(0, buf, BUF_LEN - 1);
	remove_newline(buf);
 	s1 = ft_strdup(buf);
	printf("ft_strdup returned: \"%s\"\n", s1);
	free(s1);
}
