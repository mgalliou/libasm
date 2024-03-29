/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_atoi_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:56:27 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/19 17:09:13 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static TEST(when_multiple_tests)
{
	assert_int_equal(5, ft_atoi_base("101", "01"));
	assert_int_equal(0, ft_atoi_base("10111", "0\v541"));
	assert_int_equal(493, ft_atoi_base(" 755x+", "01234567"));
}

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
	assert_int_equal(0, ft_atoi_base("10", "0113456789"));
}

static TEST(when_duplicate_char_in_base_2)
{
	assert_int_equal(0, ft_atoi_base("10", "0123455789"));
}

static TEST(when_duplicate_char_in_base_3)
{
	assert_int_equal(0, ft_atoi_base("10", "0123456788"));
}

static TEST(when_base_contain_sign_1)
{
	assert_int_equal(0, ft_atoi_base("10", "012345678+"));
}

static TEST(when_base_contain_sign_2)
{
	assert_int_equal(0, ft_atoi_base("10", "-012345678"));
}

static TEST(when_base_contain_sign_3)
{
	assert_int_equal(0, ft_atoi_base("10", "012345+678"));
}

static TEST(when_10_in_base_10)
{
	assert_int_equal(10, ft_atoi_base("10", "0123456789"));
}

static TEST(when_minus_10_in_base_10)
{
	assert_int_equal(-10, ft_atoi_base("-10", "0123456789"));
}

static TEST(when_minus_100_in_base_10)
{
	assert_int_equal(-111, ft_atoi_base("-111", "0123456789"));
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

static TEST(when_spaces_before_number_skip_them)
{
	assert_int_equal(10, ft_atoi_base(" \t\r\v\f\n10", "0123456789"));
}

static TEST(when_123456789_in_base_10)
{
	assert_int_equal(123456789, ft_atoi_base("123456789", "0123456789"));
}

static TEST(when_intmax_in_base_10)
{
	assert_int_equal(2147483647, ft_atoi_base("2147483647", "0123456789"));
}

static TEST(when_intmin_in_base_10)
{
	assert_int_equal(-2147483648, ft_atoi_base("-2147483648", "0123456789"));
}

static TEST(when_intmax_in_base_16)
{
	assert_int_equal(2147483647, ft_atoi_base("7FFFFFFF", "0123456789ABCDEF"));
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
    RUN_TEST(when_minus_100_in_base_10);
	RUN_TEST(when_minus_minus_10_in_base_10);
	RUN_TEST(when_minus_plus_minus_plus_10_in_base_10);
	RUN_TEST(when_32_in_base_16);
	RUN_TEST(when_spaces_before_number_skip_them);
    RUN_TEST(when_123456789_in_base_10);
    RUN_TEST(when_intmax_in_base_10);
	RUN_TEST(when_intmin_in_base_10);
	RUN_TEST(when_intmax_in_base_16);
	RUN_TEST(when_multiple_tests);
}
