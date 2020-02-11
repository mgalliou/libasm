/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_isspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:41:23 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/11 17:07:59 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static TEST(when_c_is_space)
{
	assert_true(ft_isspace(' '));
}

static TEST(when_c_is_tab)
{
	assert_true(ft_isspace('\t'));
}

static TEST(when_c_is_newline)
{
	assert_true(ft_isspace('\n'));
}

static TEST(when_c_is_vertical_tab)
{
	assert_true(ft_isspace('\v'));
}

static TEST(when_c_is_form_feed)
{
	assert_true(ft_isspace('\f'));
}

static TEST(when_c_is_carriage_return)
{
	assert_true(ft_isspace('\r'));
}

static TEST(when_c_is_invalid)
{
	int i = -1;

	while (++i < 256)
	{
		if (i != ' ' 
				&& i != '\t'
				&& i != '\n'
				&& i != '\v'
				&& i != '\f'
				&& i != '\r')
		{
			assert_false(ft_isspace(i));
		}
		
	}
}

TEST_SUITE(suite_ft_isspace)
{
	RUN_TEST(when_c_is_space);
	RUN_TEST(when_c_is_tab);
	RUN_TEST(when_c_is_newline);
	RUN_TEST(when_c_is_vertical_tab);
	RUN_TEST(when_c_is_form_feed);
	RUN_TEST(when_c_is_carriage_return);
	RUN_TEST(when_c_is_invalid);
}
