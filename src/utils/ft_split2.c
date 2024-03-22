/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:51:47 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/08 19:10:54 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static void	split_clear(char **l, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(*(l + i));
		i++;
	}
	free(l);
}

static size_t	word_len(char const *s, int (*f)(char c))
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
	{
		if (f(s[len]))
			break ;
		len++;
	}
	return (len);
}

static size_t	worlds_cnt(char const *s, int (*f)(char c))
{
	int		flag;
	size_t	cnt;

	if (!s)
		return (0);
	flag = 1;
	cnt = 0;
	while (*s)
	{
		if (flag && !f(*s))
		{
			cnt++;
			flag = 0;
		}
		else if (f(*s))
		{
			flag = 1;
		}
		s++;
	}
	return (cnt);
}

static int	append_split(char **ret, char const *s, int (*f)(char c))
{
	size_t	len;
	char	*temp;

	len = word_len(s, f);
	temp = ft_calloc2(len + 1, sizeof(char));
	if (!temp)
		return (0);
	ft_strlcpy(temp, s, len + 1);
	*(ret) = temp;
	return (len);
}

char	**ft_split2(char const *s, int (*f)(char c))
{
	char	**ret;
	size_t	len;
	size_t	cnt;
	size_t	i;

	cnt = worlds_cnt(s, f);
	ret = ft_calloc2((cnt + 1), sizeof(char *));
	if (!ret)
		return (0);
	i = 0;
	while (i < cnt)
	{
		while (*s && f(*s))
			s++;
		len = append_split(ret + i, s, f);
		if (!len)
		{
			split_clear(ret, i);
			return (0);
		}
		s += len;
		i++;
	}
	ret[cnt] = 0;
	return (ret);
}
