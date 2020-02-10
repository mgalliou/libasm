#ifndef TESTS_H
# define TESTS_H

# include "../libftest/include/libftest.h"

extern int  ft_strlen(const char *s);
extern char *ft_strcpy(char *dst, const char* src);
extern int  ft_strcmp(const char *s1, const char* s2);
extern int  ft_write(int fildes, const void* buf, size_t nbyte);
extern int  ft_read(int fildes, const void* buf, size_t nbyte);
extern char *ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);

TEST_SUITE(suite_ft_strlen);
TEST_SUITE(suite_ft_strcpy);
TEST_SUITE(suite_ft_strdup);
TEST_SUITE(suite_ft_strchr);

#endif
