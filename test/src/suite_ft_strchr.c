#include "tests.h"
#include <string.h>
#include <stdio.h>

static TEST(when_not_found)
{
	const char s[] = "0123456789";
	
	assert_str_equal(strchr(s, '2'), ft_strchr(s, 10));
}

TEST_SUITE(suite_ft_strchr)
{
	RUN_TEST(when_not_found);
}
