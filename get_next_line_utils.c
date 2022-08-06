/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:45:28 by jnoh              #+#    #+#             */
/*   Updated: 2022/03/14 13:54:30 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == '\0' && (char)c == 0)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strdup_until_add(char *src, int until, int add)
{
	size_t	len;
	char	*ret;
	size_t	i;

	if (!src)
		return (0);
	len = 0;
	while (src[len] != (char)until)
		len++;
	if (add != -1)
		ret = (char *)malloc((len + 2) * sizeof(char));
	else
		ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	if (add != -1)
		ret[i++] = (char)add;
	ret[i] = 0;
	return (ret);
}

void	ft_strcpy(char *dest, char *src, size_t	len)
{
	size_t	i;

	if (!dest || !src)
		return ;
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*ret;
	size_t	len1;
	size_t	len2;

	if (!s1 && s2)
		return (ft_strdup_until_add(s2, 0, -1));
	if (s1 && !s2)
		return (ft_strdup_until_add(s1, 0, -1));
	if (!s1 && !s2)
	{
		ret = (char *)malloc(1 * sizeof(char));
		if (!ret)
			return (0);
		ret[0] = 0;
		return (ret);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strcpy(ret, s1, len1);
	ft_strcpy(ret + len1, s2, len2);
	ret[len1 + len2] = 0;
	return (ret);
}
