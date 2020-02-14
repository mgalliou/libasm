#ifndef TESTS_H
# define TESTS_H

# include "../libftest/include/libftest.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

extern int  ft_strlen(const char *s);
extern char *ft_strcpy(char *dst, const char* src);
extern int  ft_strcmp(const char *s1, const char* s2);
extern int  ft_write(int fildes, const void* buf, size_t nbyte);
extern int  ft_read(int fildes, const void* buf, size_t nbyte);
extern char *ft_strdup(const char *s1);
extern char *ft_strchr(const char *s, int c);
extern int  ft_atoi_base(char *str, char *base);
extern int  ft_isspace(int c);

extern t_list *ft_create_elem(void *data);
extern void   ft_list_push_front(t_list **begin_list, void *data);
extern int    ft_list_size(t_list *begin_list);
extern void   ft_list_sort(t_list **begin_list, int(*cmp)());

TEST_SUITE(suite_ft_strlen);
TEST_SUITE(suite_ft_strcpy);
TEST_SUITE(suite_ft_strdup);
TEST_SUITE(suite_ft_strchr);
TEST_SUITE(suite_ft_atoi_base);
TEST_SUITE(suite_ft_isspace);
TEST_SUITE(suite_ft_create_elem);
TEST_SUITE(suite_ft_list_push_front);
TEST_SUITE(suite_ft_list_size);
TEST_SUITE(suite_ft_list_sort);

#endif
