/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:45:21 by jnoh              #+#    #+#             */
/*   Updated: 2022/04/15 15:17:49 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		if (!(tmp->next))
			break ;
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	ft_update_lastbuffer(int fd, t_list *lst, char *lastbuffer)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			tmp->lastbuffer = lastbuffer;
			return ;
		}
		tmp = tmp->next;
	}
	return ;
}

char	*ft_getnode(int fd, t_list **lst)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp->lastbuffer);
		tmp = tmp->next;
	}
	if (!(*lst) || !tmp)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (0);
		new->fd = fd;
		new->lastbuffer = 0;
		new->next = 0;
		ft_lstadd_back(lst, new);
		return (new->lastbuffer);
	}
	return (0);
}

int	ft_get_line(char **buffer, char **lastbuffer, char **ret, int fd)
{
	int		read_size;
	char	*tmp;

	while (1)
	{
		if (ft_strchr(*lastbuffer, '\n'))
		{
			*ret = ft_strdup_until_add(*lastbuffer, '\n', '\n');
			tmp = *lastbuffer;
			*lastbuffer = ft_strdup_until_add(ft_strchr(tmp, '\n') + 1, 0, -1);
			ft_free(&tmp);
			return (1);
		}
		read_size = read(fd, *buffer, BUFFER_SIZE);
		if (read_size < 0 || (read_size == 0 && !ft_strchr(*lastbuffer, '\n')))
		{
			*ret = 0;
			return (read_size);
		}
		(*buffer)[read_size] = 0;
		tmp = *lastbuffer;
		*lastbuffer = ft_strcat(tmp, *buffer);
		ft_free(&tmp);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*buffer;
	char			*ret;
	char			*lastbuffer;
	int				result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(buffer))
		return (0);
	lastbuffer = ft_getnode(fd, &list);
	result = ft_get_line(&buffer, &lastbuffer, &ret, fd);
	ft_free(&buffer);
	if (result == 0)
	{
		ret = ft_strdup_until_add(lastbuffer, 0, -1);
		if ((ret && !ret[0]) || !lastbuffer || !lastbuffer[0])
			ft_free(&ret);
	}
	ft_update_lastbuffer(fd, list, lastbuffer);
	if (result <= 0)
		ft_deletenode(&list, fd);
	return (ret);
}
