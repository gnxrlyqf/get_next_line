/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:42:58 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/20 18:35:34 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	char			c;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);
void	add_node(t_list **head, char c);
char	*make_str(t_list *head, int start, int size);
void	free_list(t_list **lst);
int		listchr_len(t_list *head, int start);
void print_list(t_list *head);

#endif
