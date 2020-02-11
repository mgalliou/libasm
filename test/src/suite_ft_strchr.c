#include "tests.h"
#include <string.h>
#include <stdio.h>

static TEST(when_c_is_null)
{
	char s[] = "abcde";
	char c   = '\0';

	assert_ptr_equal(strchr(s, c), ft_strchr(s, c));
}

static TEST(when_c_is_last_char_of_string)
{
	char s[] = "abcde";
	char c   = 'e';

	assert_ptr_equal(strchr(s, c), ft_strchr(s, c));
}

static TEST(when_c_is_in_string)
{
	char s[] = "abcde";
	char c   = 'c';

	assert_ptr_equal(strchr(s, c), ft_strchr(s, c));
}

static TEST(when_c_is_first_char_of_string)
{
	char s[] = "abcde";
	char c   = 'a';

	assert_ptr_equal(strchr(s, c), ft_strchr(s, c));
}


static TEST(when_c_is_not_in_string)
{
	char *s;
	char c   = 'x';

	s = strdup("abcde");
	assert_ptr_equal(strchr(s, c), ft_strchr(s, c));
}

static TEST(when_s_is_empty_and_c_is_null)
{
	char s[] = "";
	char c   = '\0';

	assert_ptr_equal(strchr(s, c), ft_strchr(s, c));
}

static TEST(when_s_is_empty)
{
	char *s;
	char c   = 'a';

	s = strdup("");
	assert_ptr_equal(strchr(s, c), ft_strchr(s, c));
}

TEST_SUITE(suite_ft_strchr)
{
	RUN_TEST(when_s_is_empty);
	RUN_TEST(when_s_is_empty_and_c_is_null);
	RUN_TEST(when_c_is_not_in_string);
	RUN_TEST(when_c_is_first_char_of_string);
	RUN_TEST(when_c_is_in_string);
	RUN_TEST(when_c_is_last_char_of_string);
	RUN_TEST(when_c_is_null);
}
