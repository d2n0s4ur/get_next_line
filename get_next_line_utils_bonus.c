/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:45:28 by jnoh              #+#    #+#             */
/*   Updated: 2022/04/11 16:22:21 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strcat(char *s1, char *s2)
{
	char		*ret;
	long long	len1;
	long long	len2;

	len1 = 0;
	while (s1 && s1[len1])
		len1++;
	len2 = 0;
	while (s2 && s2[len2])
		len2++;
	ret = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!ret)
		return (0);
	ret[len1 + len2] = 0;
	while (--len2 >= 0)
		ret[len1 + len2] = s2[len2];
	while (--len1 >= 0)
		ret[len1] = s1[len1];
	return (ret);
}

void	ft_free(char **to_free)
{
	if (!(*to_free))
		return ;
	free(*to_free);
	*to_free = 0;
	return ;
}

void	ft_deletenode(t_list **lst, int fd)
{
	t_list	*tmp;
	t_list	*do_free;

	tmp = *lst;
	if (tmp->fd == fd)
	{
		do_free = tmp;
		*lst = tmp->next;
		ft_free(&(do_free->lastbuffer));
		free(do_free);
		return ;
	}
	while (tmp->next)
	{
		if (tmp->next->fd == fd)
		{
			do_free = tmp->next;
			tmp->next = tmp->next->next;
			ft_free(&(do_free->lastbuffer));
			free(do_free);
			return ;
		}
		else
			tmp = tmp->next;
	}
}
