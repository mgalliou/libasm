/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_list_push_front.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:47:43 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/14 11:27:18 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static TEST(when_push_on_two_len_list)
{
	t_list *lst;
	
	lst = ft_create_elem("A");
	ft_list_push_front(&lst, "B");
	ft_list_push_front(&lst, "C");
	assert_true((int)lst);
	assert_str_equal("C", lst->data);
	lst = lst->next;
	assert_str_equal("B", lst->data);
	lst = lst->next;
	assert_str_equal("A", lst->data);
	assert_null(lst->next);
}

static TEST(when_push_on_elem)
{
	t_list *lst;
	lst = ft_create_elem("A");
	ft_list_push_front(&lst, "B");
	assert_true((int)lst);
	assert_str_equal("B", lst->data);
	assert_not_null(lst->next);
	assert_str_equal("A", lst->next->data);
}

static TEST(when_push_on_null_ptr)
{
	t_list *lst;
	int    n;
	
	lst = NULL;
	n = 42;
	ft_list_push_front(&lst, &n);
	assert_true((int)lst);
	assert_true((int)lst->data);
	assert_int_equal(42, *(int*)(lst->data));
	assert_null(lst->next);

}

TEST_SUITE(suite_ft_list_push_front)
{
	RUN_TEST(when_push_on_null_ptr);
	RUN_TEST(when_push_on_elem);
	RUN_TEST(when_push_on_two_len_list);
}
