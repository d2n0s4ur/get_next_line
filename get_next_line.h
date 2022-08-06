/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:45:46 by jnoh              #+#    #+#             */
/*   Updated: 2022/07/03 13:44:12 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE=42
# endif

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup_until_add(char *src, int until, int add);
void	ft_strcpy(char *dest, char *src, size_t	len);
char	*ft_strcat(char *s1, char *s2);
char	*get_next_line(int fd);
void	ft_free(char **to_free);
int		ft_get_line(char **buffer, char **lastbuffer, char **ret, int fd);

#endif