/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:22:25 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/18 14:28:08 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>

static TEST(when_str_is_zero_len)
{
	const char s[] = "";

	assert_str_equal(strdup(s), ft_strdup(s));
}

static TEST(when_str_len_is_one)
{
	const char s[] = "1";

	assert_str_equal(strdup(s), ft_strdup(s));
}

static TEST(when_str_is_ten)
{
	const char s[] = "0123456789";

	assert_str_equal(strdup(s), ft_strdup(s));
}


TEST_SUITE(suite_ft_strdup)
{
	RUN_TEST(when_str_is_zero_len);
	RUN_TEST(when_str_len_is_one);
	RUN_TEST(when_str_is_ten);
}
