/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:42:58 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/21 21:41:42 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	char			c;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int		contains_nl(char *str);
void	add_node(t_list **head, t_list *new);
t_list	*new_node(char c);
char	*make_str(t_list **head, int size);
void	free_list(t_list **lst);
int		listchr_len(t_list *head);

#endif
