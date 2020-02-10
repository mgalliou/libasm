#include "tests.h"
#include <string.h>

static TEST(when_str_is_zero_len)
{
	char d1[2] = " ";
	char d2[2] = " ";
	char s[1] = "";

	assert_str_equal(strcpy(d2, s), ft_strcpy(d1, s));
}

static TEST(when_str_len_is_one)
{
	char d1[2] = " ";
	char d2[2] = " ";
	char s[2] = "1";

	assert_str_equal(strcpy(d2, s), ft_strcpy(d1, s));
}

static TEST(when_str_is_ten)
{
	char d1[11] = "          ";
	char d2[11] = "          ";
	char s[11] = "012345";

	assert_str_equal(strcpy(d2, s), ft_strcpy(d1, s));
}

TEST_SUITE(suite_ft_strcpy)
{
	RUN_TEST(when_str_is_zero_len);
	RUN_TEST(when_str_len_is_one);
	RUN_TEST(when_str_is_ten);
}
