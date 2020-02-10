#ifndef TESTS_H
# define TESTS_H

# include "../libftest/include/libftest.h"

extern int  ft__strlen(const char *s);
extern char *ft__strcpy(char *dst, const char* src);
extern int  ft__strcmp(const char *s1, const char* s2);
extern int  ft__write(int fildes, const void* buf, size_t nbyte);
extern int  ft__read(int fildes, const void* buf, size_t nbyte);
extern char *ft__strdup(const char *s1);

TEST_SUITE(suite_ft__strlen);
TEST_SUITE(suite_ft__strcpy);
TEST_SUITE(suite_ft__strdup);

#endif
