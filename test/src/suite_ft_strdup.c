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
