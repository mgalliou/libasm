/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_atoi_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:56:27 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/11 15:31:54 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static TEST(when_base_is_null)
{
	assert_int_equal(0, ft_atoi_base("10", NULL));
}

static TEST(when_base_len_is_zero)
{
	assert_int_equal(0, ft_atoi_base("10", ""));
}

static TEST(when_base_len_is_one)
{
	assert_int_equal(0, ft_atoi_base("10", "1"));
}

static TEST(when_duplicate_char_in_base_1)
{
	assert_int_equal(0, ft_atoi_base("10", "113456789"));
}

static TEST(when_duplicate_char_in_base_2)
{
	assert_int_equal(0, ft_atoi_base("10", "123455789"));
}

static TEST(when_duplicate_char_in_base_3)
{
	assert_int_equal(0, ft_atoi_base("10", "123456788"));
}

static TEST(when_base_contain_sign_1)
{
	assert_int_equal(0, ft_atoi_base("10", "12345678+"));
}

static TEST(when_base_contain_sign_2)
{
	assert_int_equal(0, ft_atoi_base("10", "-12345678"));
}

static TEST(when_base_contain_sign_3)
{
	assert_int_equal(0, ft_atoi_base("10", "12345+678"));
}

static TEST(when_10_in_base_10)
{
	assert_int_equal(10, ft_atoi_base("10", "0123456789"));
}

static TEST(when_minus_10_in_base_10)
{
	assert_int_equal(-10, ft_atoi_base("-10", "0123456789"));
}

static TEST(when_minus_minus_10_in_base_10)
{
	assert_int_equal(10, ft_atoi_base("--10", "0123456789"));
}

static TEST(when_minus_plus_minus_plus_10_in_base_10)
{
	assert_int_equal(10, ft_atoi_base("-+-+10", "0123456789"));
}

static TEST(when_32_in_base_16)
{
	assert_int_equal(32, ft_atoi_base("20", "0123456789ABCDEF"));
}

TEST_SUITE(suite_ft_atoi_base)
{
	RUN_TEST(when_base_is_null);
	RUN_TEST(when_base_len_is_zero);
	RUN_TEST(when_base_len_is_one);
	RUN_TEST(when_duplicate_char_in_base_1);
	RUN_TEST(when_duplicate_char_in_base_2);
	RUN_TEST(when_duplicate_char_in_base_3);
	RUN_TEST(when_base_contain_sign_1);
	RUN_TEST(when_base_contain_sign_2);
	RUN_TEST(when_base_contain_sign_3);
	RUN_TEST(when_10_in_base_10);
	RUN_TEST(when_minus_10_in_base_10);
	RUN_TEST(when_minus_minus_10_in_base_10);
	RUN_TEST(when_minus_plus_minus_plus_10_in_base_10);
	RUN_TEST(when_32_in_base_16);
}
