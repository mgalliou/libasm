/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_list_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:42:29 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/14 14:03:16 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "string.h"

static TEST(when_four_mixed_elem)
{
	t_list *lst;

	lst = ft_create_elem("A");
	ft_list_push_front(&lst, "D");
	ft_list_push_front(&lst, "B");
	ft_list_push_front(&lst, "C");
	ft_list_sort(&lst, strcmp);
	assert_not_null(lst);
	assert_str_equal("A", lst->data);
	lst = lst->next;
	assert_str_equal("B", lst->data);
	lst = lst->next;
	assert_str_equal("C", lst->data);
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
}

