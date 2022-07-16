/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:24:19 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/07 17:35:37 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (((char *)p) && i < count * size)
	{
		((char *)p)[i] = 0;
		i++;
	}
	return (p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	int		dst_s;
	int		i;

	s_len = ft_strlen(src);
	dst_s = (int)dstsize;
	i = 0;
	if (dst_s)
	{
		while (src[i] && --dst_s)
		{
			*dst++ = src[i++];
		}
		*dst = '\0';
	}
	return (s_len);
}

char	*ft_strchr(const char *s, int c)
{	
	if (c != 0)
	{
		while (*s)
		{
			if (*s == (char )c)
				return ((char *)s);
			s++;
		}
		return (NULL);
	}
	return ((char *)(s + ft_strlen(s)));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	str = (char *)s1;
	if (!str)
		return (NULL);
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	if (str[i] == '\0')
		return (ft_calloc(1, 1));
	j = ft_strlen(str) - 1;
	while (ft_strchr(set, str[j]))
		j--;
	j += 1;
	res = (char *)malloc((j - i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &str[i], (j - i + 1));
	return (res);
}
