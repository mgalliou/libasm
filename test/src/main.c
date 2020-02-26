#include "tests.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char **argv)
{
	parse_args(argc, argv);
	RUN_TEST_SUITE(suite_ft_strlen);
	RUN_TEST_SUITE(suite_ft_strcpy);
	RUN_TEST_SUITE(suite_ft_strdup);
	RUN_TEST_SUITE(suite_ft_strcmp);
	RUN_TEST_SUITE(suite_ft_strchr);
	RUN_TEST_SUITE(suite_ft_atoi_base);
	RUN_TEST_SUITE(suite_ft_isspace);
	RUN_TEST_SUITE(suite_ft_create_elem);
	RUN_TEST_SUITE(suite_ft_list_push_front);
    RUN_TEST_SUITE(suite_ft_list_size);
    RUN_TEST_SUITE(suite_ft_list_sort);
	RUN_TEST_SUITE(suite_ft_list_remove_if);
	RUN_TEST_SUITE(suite_ft_write_read);
	print_test_results();
}
