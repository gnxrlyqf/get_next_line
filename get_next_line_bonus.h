/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:42:58 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/24 18:58:26 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	char			c;
	struct s_list	*next;
}				t_list;

typedef struct s_list_fd
{
	int					fd;
	t_list				*head;
	struct s_list_fd	*next;
}				t_list_fd;

int			contains_nl(char *str);
void		populate_list(t_list **head, char *str);
t_list_fd	*add_node_fd(t_list_fd **head, int fd);
t_list		**get_list(t_list_fd **lists, int fd);
char		*get_next_line(int fd);
t_list		*add_node(t_list **head, char c);
void		free_list(t_list **head);
char		*make_str(t_list **head, int size);
int			listchr_len(t_list *head);

#endif
