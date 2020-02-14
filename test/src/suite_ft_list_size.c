/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_list_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:03:27 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/14 11:29:10 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static TEST(when_list_is_empty)
{
	t_list *lst;

	lst = NULL;
	assert_int_equal(0, ft_list_size(lst));
}

static TEST(when_list_len_is_one)
{
	t_list *lst;

	lst = ft_create_elem("test");
	assert_int_equal(1, ft_list_size(lst));
}

static TEST(when_list_len_is_two)
{
	t_list *lst;

	lst = ft_create_elem("test1");
	ft_list_push_front(&lst, "test2");
	assert_int_equal(2, ft_list_size(lst));
}

static TEST(when_list_len_is_ten)
{
	t_list *lst;

	lst = ft_create_elem("test1");
	ft_list_push_front(&lst, "test2");
	ft_list_push_front(&lst, "test3");
	ft_list_push_front(&lst, "test4");
	ft_list_push_front(&lst, "test5");
	ft_list_push_front(&lst, "test6");
	ft_list_push_front(&lst, "test7");
	ft_list_push_front(&lst, "test8");
	ft_list_push_front(&lst, "test9");
	ft_list_push_front(&lst, "test10");
	assert_int_equal(10, ft_list_size(lst));
}

TEST_SUITE(suite_ft_list_size)
{
	RUN_TEST(when_list_is_empty);
	RUN_TEST(when_list_len_is_one);
	RUN_TEST(when_list_len_is_two);
	RUN_TEST(when_list_len_is_ten);
}
