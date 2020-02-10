#include "tests.h"

static TEST(when_string_is_zero_len)
{
	char s[1] = "";
	int  l;

	l = ft_strlen(s);
	assert_int_equal(0 , l);
}

static TEST(when_string_len_is_one)
{
	char s[2] = "1";
	int  l;

	l = ft_strlen(s);
	assert_int_equal(1 , l);
}

static TEST(when_string_len_is_ten)
{
	char s[11] = "0123456789";
	int  l;

	l = ft_strlen(s);
	assert_int_equal(10 , l);
}

TEST_SUITE(suite_ft_strlen)
{
	RUN_TEST(when_string_is_zero_len);
	RUN_TEST(when_string_len_is_one);
	RUN_TEST(when_string_len_is_ten);
}
