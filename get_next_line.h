/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:42:58 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/23 17:42:41 by mchetoui         ###   ########.fr       */
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
# include <string.h>

typedef struct s_list
{
	char			c;
	struct s_list	*next;
}				t_list;

int		contains_nl(char *str);
t_list	*populate_list(t_list **head, char *str);
char	*get_next_line(int fd);
t_list	*add_node(t_list **head, char c);
void	free_list(t_list **head);
char	*make_str(t_list **head, int size);
int		listchr_len(t_list *head);

#endif
