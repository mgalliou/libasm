/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_list_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:42:29 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/21 11:39:16 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "string.h"

static int cmp_int(void *a, void *b)
{
	return (*(int*)a - *(int*)b);
}

static TEST(when_multiple_mix_elem)
{
	int a = 98;
	int b = 12;
	int c = 12;
	int d = 45;
	int e = 1;
	int f = -1;
	int g = 232;
	int h = 34;
	int i = 23;
	t_list *lst;

	lst = ft_create_elem(&i);
	ft_list_push_front(&lst, &h);
	ft_list_push_front(&lst, &g);
	ft_list_push_front(&lst, &f);
	ft_list_push_front(&lst, &e);
	ft_list_push_front(&lst, &d);
	ft_list_push_front(&lst, &c);
	ft_list_push_front(&lst, &b);
	ft_list_push_front(&lst, &a);
	ft_list_sort(&lst, &cmp_int);
	assert_not_null(lst);
	assert_int_equal(f, *(int*)lst->data);
	lst = lst->next;
	assert_int_equal(e, *(int*)lst->data);
	lst = lst->next;
	assert_int_equal(b, *(int*)lst->data);
	lst = lst->next;
	assert_int_equal(c, *(int*)lst->data);
	lst = lst->next;
	assert_int_equal(i, *(int*)lst->data);
	lst = lst->next;
	assert_int_equal(h, *(int*)lst->data);
	lst = lst->next;
	assert_int_equal(d, *(int*)lst->data);
	lst = lst->next;
	assert_int_equal(a, *(int*)lst->data);
	lst = lst->next;
	assert_int_equal(g, *(int*)lst->data);
	lst = lst->next;
}

static TEST(when_four_mixed_elem)
{
	t_list *lst;

	lst = ft_create_elem("A");
	ft_list_push_front(&lst, "D");
	ft_list_push_front(&lst, "B");
	ft_list_push_front(&lst, "B");
	ft_list_sort(&lst, strcmp);
	assert_not_null(lst);
	assert_str_equal("A", lst->data);
	lst = lst->next;
	assert_str_equal("B", lst->data);
	lst = lst->next;
	assert_str_equal("B", lst->data);
	lst = lst->next;
	assert_str_equal("D", lst->data);
	assert_null(lst->next);
}

static TEST(when_tree_elem_in_reverse_order)
{
	t_list *lst;

	lst = ft_create_elem("A");
	ft_list_push_front(&lst, "B");
	ft_list_push_front(&lst, "C");
	ft_list_sort(&lst, strcmp);
	assert_not_null(lst);
	assert_str_equal("A", lst->data);
	lst = lst->next;
	assert_str_equal("B", lst->data);
	lst = lst->next;
	assert_str_equal("C", lst->data);
	assert_null(lst->next);
}


static TEST(when_two_elem_in_reverse_order)
{
	t_list *lst;

	lst = ft_create_elem("A");
	ft_list_push_front(&lst, "B");
	ft_list_sort(&lst, strcmp);
	assert_not_null(lst);
	assert_str_equal("A", lst->data);
	lst = lst->next;
	assert_str_equal("B", lst->data);
}

static TEST(when_cmp_function_is_null)
{
	t_list *lst;

	lst = ft_create_elem("A");
	ft_list_push_front(&lst, "B");
	ft_list_push_front(&lst, "C");
	ft_list_sort(&lst, NULL);
	assert_not_null(lst);
	assert_str_equal("C", lst->data);
}

static TEST(when_list_is_empty)
{
	t_list *lst;

	lst = NULL;
	ft_list_sort(&lst, strcmp);
	assert_null(lst);
}

TEST_SUITE(suite_ft_list_sort)
{
	RUN_TEST(when_list_is_empty);
	RUN_TEST(when_cmp_function_is_null);
	RUN_TEST(when_two_elem_in_reverse_order);
	RUN_TEST(when_tree_elem_in_reverse_order);
	RUN_TEST(when_four_mixed_elem);
	RUN_TEST(when_multiple_mix_elem);
}

