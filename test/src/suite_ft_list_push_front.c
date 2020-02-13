/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_list_push_front.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:47:43 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/13 18:15:15 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static TEST(when_push_on_elem)
{
	t_list *lst;
	int    m;
	int    n;
	
	m = 21;
	n = 42;
	lst = ft_create_elem(&m);
	ft_list_push_front(&lst, &n);
	assert_true((int)lst);
	assert_true((int)lst->data);
	assert_int_equal(42, *(int*)(lst->data));
	assert_not_null(lst->next);
	assert_int_equal(21, *(int*)(lst->next->data));
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
}
