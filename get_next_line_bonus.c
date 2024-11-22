/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:25:40 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/22 15:12:27 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	contains_nl(char *str)
{
	while (*str)
		if (*(str++) == '\n')
			return (1);
	return (0);
}

t_list	*populate_list(t_list **head, char *str)
{
	while (*str)
		if (!add_node(head, *(str++)))
			return (NULL);
	return (*head);
}

t_list_fd	*add_node_fd(t_list_fd **head, int fd)
{
	t_list_fd	*curr;
	t_list_fd	*new;

	new = malloc(sizeof(t_list_fd));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->head = NULL;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (new);
}

t_list	**get_list(t_list_fd **lists, int fd)
{
	t_list_fd	*curr;

	curr = *lists;
	while (curr)
	{
		if (curr->fd == fd)
			break ;
		curr = curr->next;
	}
	if (!curr)
		curr = add_node_fd(lists, fd);
	return (&(curr->head));
}

char	*get_next_line(int fd)
{
	char				*str;
	int					size;
	static t_list_fd	*lists;
	t_list				**head;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	head = get_list(&lists, fd);
	while (1)
	{
		size = read(fd, str, BUFFER_SIZE);
		str[size] = '\0';
		if (!populate_list(head, str))
		{
			free_list(head);
			break ;
		}
		if (contains_nl(str) || size <= 0)
			break ;
	}
	free(str);
	str = make_str(head, listchr_len(*head));
	return (str);
}
