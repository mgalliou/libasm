/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_ft_write_read.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:43:31 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/26 12:58:15 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <unistd.h>

TEST(when_read_fd_is_invalid)
{
	int ret;
	char buf[1];

	ret = read(-1, &buf, 1);
	assert_int_equal(-1, ret);
}

TEST(when_write_fd_is_invalid)
{
	int ret;
	char buf[1];

	ret = write(-1, &buf, 1);
	assert_int_equal(-1, ret);
}

TEST_SUITE(suite_ft_write_read)
{
	RUN_TEST(when_write_fd_is_invalid);
	RUN_TEST(when_read_fd_is_invalid);
}
