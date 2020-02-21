#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_LEN  256
#define NBRS_LEN 10

extern int  ft_strlen(const char *s);
extern int  ft_strcmp(const char *s1, const char* s2);
extern int  ft_write(int fildes, const void* buf, size_t nbyte);
extern int  ft_read(int fildes, const void* buf, size_t nbyte);
extern char *ft_strdup(const char *s1);

extern int  ft_atoi_base(char *str, char *base);
extern int  ft_isspace(int c);

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

extern t_list *ft_create_elem(void *data);
extern void   ft_list_push_front(t_list **begin_list, void *data);
extern int    ft_list_size(t_list *begin_list);
extern void   ft_list_sort(t_list **begin_list, int(*cmp)());
extern void   ft_list_remove_if(t_list **begin_list,
								void*data_ref,
								int(*cmp)(),
								void(*free_fct)(void*));

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

static void print_list(t_list *lst)
{
	ft_putstr("==========\n");
	while (lst)
	{
		ft_putstr(lst->data);
		ft_putstr("\n");
		lst = lst->next;
	}
	ft_putstr("==========\n");
}

int main(void)
{
	char buf[BUF_LEN];
	char buf2[BUF_LEN];
	int  n;
	char *c;
	t_list *lst;

	ft_putstr("Write a number and a base to test ft_atoi_base:\n");
	bzero(buf, BUF_LEN);
	ft_read(0, buf, BUF_LEN - 1);
	c = strrchr(buf, '\n');
	remove_newline(buf);
	bzero(buf2, BUF_LEN);
	ft_read(0, buf2, BUF_LEN - 1);
	remove_newline(buf2);
	n = ft_atoi_base(buf, buf2);
	printf("ft_atoi_base returned: %d\n", n);

	ft_putstr("Choose number of elem in the list:\n");
	bzero(buf, BUF_LEN);
	ft_read(0, buf, BUF_LEN - 1);
	remove_newline(buf);
	n = ft_atoi_base(buf, "0123456789");
	printf("Write %d string(s) to create a list with:\n", n);
	lst = NULL;
	while (n--)
	{
		bzero(buf, BUF_LEN);
		ft_read(0, buf, BUF_LEN - 1);
		remove_newline(buf);
		ft_list_push_front(&lst, ft_strdup(buf));
	}
	n = ft_list_size(lst);
	printf("\nft_list_size returned: \"%d\"\n", n);
	ft_list_sort(&lst, ft_strcmp);
	ft_putstr("the list after ft_list_sort is called:\n");
	print_list(lst);
	ft_putstr("\nWrite a string you want to remove from the list:\n");
	bzero(buf, BUF_LEN);
	ft_read(0, buf, BUF_LEN - 1);
	remove_newline(buf);
	ft_list_remove_if(&lst, buf, strcmp, free);
	ft_putstr("the list after ft_list_remove_if is called:\n");
	print_list(lst);
}
