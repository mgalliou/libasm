/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_list_remove_if.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:08:55 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/18 11:51:43 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <string.h>

static TEST(when_remove_last_elem_of_three_elem_list)
{
	t_list *lst;
	char   *s1;
	char   *s2;
	char   *s3;

	s1 = ft_strdup("C");
	s2 = ft_strdup("B");
	s3 = ft_strdup("A");
	lst = ft_create_elem(s1);
	ft_list_push_front(&lst, s2);
	ft_list_push_front(&lst, s3);
	ft_list_remove_if(&lst, "C", strcmp, free);  
	assert_true((int)lst);
	assert_str_equal("A", lst->data);
	assert_true((int)lst->next);
	lst = lst->next;
	assert_str_equal("B", lst->data);
	assert_null(lst->next);
}

static TEST(when_remove_middle_elem_of_three_elem_list)
{
	t_list *lst;
	char   *s1;
	char   *s2;
	char   *s3;

	s1 = ft_strdup("C");
	s2 = ft_strdup("B");
	s3 = ft_strdup("A");
	lst = ft_create_elem(s1);
	ft_list_push_front(&lst, s2);
	ft_list_push_front(&lst, s3);
	ft_list_remove_if(&lst, "B", strcmp, free);  
	assert_true((int)lst);
	assert_str_equal("A", lst->data);
	assert_true((int)lst->next);
	lst = lst->next;
	assert_str_equal("C", lst->data);
	assert_null(lst->next);
}

static TEST(when_remove_first_elem_of_three_elem_list)
{
	t_list *lst;
	char   *s1;
	char   *s2;
	char   *s3;

	s1 = ft_strdup("C");
	s2 = ft_strdup("B");
	s3 = ft_strdup("A");
	lst = ft_create_elem(s1);
	ft_list_push_front(&lst, s2);
	ft_list_push_front(&lst, s3);
	ft_list_remove_if(&lst, s3, strcmp, free);  
	assert_true((int)lst);
	assert_str_equal("B", lst->data);
	assert_true((int)lst->next);
	lst = lst->next;
	assert_str_equal("C", lst->data);
	assert_null(lst->next);
}

static TEST(when_remove_all_elems_of_two_elem_list)
{
	t_list *lst;
	char   *s1;
	char   *s2;

	s1 = ft_strdup("A");
	s2 = ft_strdup("A");
	lst = ft_create_elem(s1);
	ft_list_push_front(&lst, s2);
	ft_list_remove_if(&lst, s1, strcmp, free);  
	assert_null(lst);
}

static TEST(when_remove_last_elem_of_two_elem_list)
{
	t_list *lst;
	char   *s1;
	char   *s2;

	s1 = ft_strdup("B");
	s2 = ft_strdup("A");
	lst = ft_create_elem(s1);
	ft_list_push_front(&lst, s2);
	ft_list_remove_if(&lst, s1, strcmp, free);  
	assert_true((int)lst);
	assert_str_equal("A", lst->data);
	assert_null(lst->next);
}

static TEST(when_remove_first_elem_of_two_elem_list)
{
	t_list *lst;
	char   *s1;
	char   *s2;

	s1 = ft_strdup("B");
	s2 = ft_strdup("A");
	lst = ft_create_elem(s1);
	ft_list_push_front(&lst, s2);
	ft_list_remove_if(&lst, s2, strcmp, free);  
	assert_true((int)lst);
	assert_str_equal("B", lst->data);
	assert_null(lst->next);
}

static TEST(when_remove_on_elem_list)
{
	t_list *lst;
	char   *s;

	s = ft_strdup("A");
	lst = ft_create_elem(s);
	ft_list_remove_if(&lst, s, strcmp, free);  
	assert_null(lst);
}

static TEST(when_free_fct_is_null)
{
	t_list *lst;

	lst = ft_create_elem("A");
	ft_list_remove_if(&lst, "A", strcmp, NULL);
	assert_not_null(lst);
	assert_str_equal("A", lst->data);
	assert_null(lst->next);
}

static TEST(when_cmp_is_null)
{
	t_list *lst;

	lst = ft_create_elem("A");
	ft_list_remove_if(&lst, "A", NULL, free);
	assert_not_null(lst);
	assert_str_equal("A", lst->data);
	assert_null(lst->next);
}

static TEST(when_begin_list_is_null)
{
	ft_list_remove_if(NULL, "A", strcmp, free);
}

TEST_SUITE(suite_ft_list_remove_if)
{
	RUN_TEST(when_begin_list_is_null);
	RUN_TEST(when_cmp_is_null);
	RUN_TEST(when_free_fct_is_null);
	RUN_TEST(when_remove_on_elem_list);
	RUN_TEST(when_remove_first_elem_of_two_elem_list);
	RUN_TEST(when_remove_last_elem_of_two_elem_list);
	RUN_TEST(when_remove_all_elems_of_two_elem_list);
	RUN_TEST(when_remove_first_elem_of_three_elem_list);
	RUN_TEST(when_remove_middle_elem_of_three_elem_list);
	RUN_TEST(when_remove_last_elem_of_three_elem_list);
}
