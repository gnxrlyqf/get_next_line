/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:25:40 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/24 18:57:47 by mchetoui         ###   ########.fr       */
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

void populate_list(t_list **head, char *str)
{
	while (*str)
		if (!add_node(head, *(str++)))
			free_list(head);
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
	ssize_t				size;
	static t_list_fd	*lists;
	t_list				**head;

	size = BUFFER_SIZE - (BUFFER_SIZE - UINT_MAX) * (BUFFER_SIZE >= UINT_MAX);
	str = malloc((size_t)size + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !str)
		return (free(str), NULL);
	head = get_list(&lists, fd);
	while (1)
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size < 0)
			return (free(str), NULL);
		str[size] = 0;
		populate_list(head, str);
		if (contains_nl(str) || size <= 0)
			break ;
	}
	free(str);
	return (make_str(head, listchr_len(*head)));
}
