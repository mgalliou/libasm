#include "tests.h"
#include <string.h>

static TEST(when_str_is_zero_len)
{
	char s[1] = "";

	assert_str_equal(strdup(s), ft_strdup(s));
}

static TEST(when_str_len_is_one)
{
	char s[2] = "1";

	assert_str_equal(strdup(s), ft_strdup(s));
}

static TEST(when_str_is_ten)
{
	char s[11] = "0123456789";

	assert_str_equal(strdup(s), ft_strdup(s));
}


TEST_SUITE(suite_ft_strdup)
{
	RUN_TEST(when_str_is_zero_len);
	RUN_TEST(when_str_len_is_one);
	RUN_TEST(when_str_is_ten);
}
