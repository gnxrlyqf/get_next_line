/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:25:40 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/21 22:19:50 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int contains_nl(char *str)
{
	while (*str)
		if (*(str++) == '\n')
			return (1);
	return (0);
}

void populate_list(t_list **head, char *str)
{
	t_list *new;
	
	while (*str)
	{
		new = new_node(*(str++));
		if (!new)
			return ;
		add_node(head, new); 
	}
}

void print_list(t_list *head)
{
	t_list *curr;

	curr = head;
	while (curr)
	{
		printf("%c", curr->c);
		curr = curr->next;
	}
}

char *get_next_line(int fd)
{
	char *str;
	int size;
	static t_list *head;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (1)
	{
		size = read(fd, str, BUFFER_SIZE);
		str[size] = '\0';
		populate_list(&head, str);
		if (contains_nl(str) || size <= 0)
			break ;
	}
	free(str);
	str = make_str(&head, listchr_len(head));
	if (!str && head)
		free_list(&head);
	return (str);
}
