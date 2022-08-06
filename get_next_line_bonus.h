/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:45:46 by jnoh              #+#    #+#             */
/*   Updated: 2022/07/03 13:44:11 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE=42
# endif

typedef struct s_list
{
	char			*lastbuffer;
	int				fd;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_update_lastbuffer(int fd, t_list *lst, char *lastbuffer);
char	*ft_getnode(int fd, t_list **lst);
int		ft_get_line(char **buffer, char **lastbuffer, char **ret, int fd);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strdup_until_add(char *src, int until, int add);
char	*ft_strcat(char *s1, char *s2);
void	ft_free(char **to_free);
void	ft_deletenode(t_list **lst, int fd);

#endif
