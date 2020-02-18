/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_strcmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:22:20 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/18 15:45:15 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>

static TEST(when_last_char_is_different_2)
{
	assert_int_equal(strcmp("abcdz", "abcde"), ft_strcmp("abcdz", "abcde"));
}

static TEST(when_last_char_is_different_1)
{
	assert_int_equal(strcmp("abcde", "abcdz"), ft_strcmp("abcde", "abcdz"));
}


static TEST(when_middle_char_is_different_2)
{
	assert_int_equal(strcmp("abvde", "abcde"), ft_strcmp("abvde", "abcde"));
}

static TEST(when_middle_char_is_different_1)
{
	assert_int_equal(strcmp("abcde", "abvde"), ft_strcmp("abcde", "abvde"));
}

static TEST(when_first_char_is_different_2)
{
	assert_int_equal(strcmp("bbcde", "abcde"), ft_strcmp("bbcde", "abcde"));
}

static TEST(when_first_char_is_different_1)
{
	assert_int_equal(strcmp("abcde", "bbcde"), ft_strcmp("abcde", "bbcde"));
}

static TEST(when_comparing_same_empty_str)
{
	assert_int_equal(strcmp("", ""), ft_strcmp("", ""));
}

static TEST(when_comparing_same_str)
{
	assert_int_equal(strcmp("test", "test"), ft_strcmp("test", "test"));
}

TEST_SUITE(suite_ft_strcmp)
{
	RUN_TEST(when_comparing_same_str);
	RUN_TEST(when_comparing_same_empty_str);
	RUN_TEST(when_first_char_is_different_1);
	RUN_TEST(when_first_char_is_different_2);
	RUN_TEST(when_middle_char_is_different_1);
	RUN_TEST(when_middle_char_is_different_2);
	RUN_TEST(when_last_char_is_different_1);
	RUN_TEST(when_last_char_is_different_2);
}
