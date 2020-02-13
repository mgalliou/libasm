/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_create_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:55:57 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/13 17:00:21 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static TEST(when_data_is_not_null)
{
	t_list *lst;
	int    c;

	c = 42;
	lst = ft_create_elem(&c);
	assert_int_equal(42, *(int*)(lst->data));
	assert_null(lst->next);
}

static TEST(when_data_is_null)
{
	t_list *lst;

	lst = ft_create_elem(NULL);
	assert_true((int)lst);
	assert_null(lst->data);
	assert_null(lst->next);
}

TEST_SUITE(suite_ft_create_elem)
{
	RUN_TEST(when_data_is_null);
	RUN_TEST(when_data_is_not_null);
}
