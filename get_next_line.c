/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:45:21 by jnoh              #+#    #+#             */
/*   Updated: 2022/04/15 15:17:15 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **to_free)
{
	free(*to_free);
	*to_free = 0;
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
	static char	*lastbuffer;
	char		*buffer;
	char		*ret;
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	result = ft_get_line(&buffer, &lastbuffer, &ret, fd);
	ft_free(&buffer);
	if (result == -1)
		ft_free(&lastbuffer);
	else if (result == 0)
	{
		ret = ft_strdup_until_add(lastbuffer, 0, -1);
		if (ret && !ft_strlen(ret))
			ft_free(&ret);
		if (!ft_strlen(lastbuffer))
			ret = 0;
		ft_free(&lastbuffer);
	}
	return (ret);
}
