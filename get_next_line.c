/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:25:40 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/20 20:17:48 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (!*str && c)
		return (NULL);
	return (str);
}

void populate_list(t_list **head, char *str)
{
	int i;

	i = 0;
	while (str[i])
		add_node(head, str[i++]);
}

char *get_next_line(int fd)
{
	char str[BUFFER_SIZE];
	int size;
	static int cursor;
	static t_list *head;
	char *out;

	size = read(fd, str, BUFFER_SIZE);
	str[size] = 0;
	populate_list(&head, str);
	while (size > 0)
	{
		size = read(fd, str, BUFFER_SIZE);
		str[size] = 0;
		populate_list(&head, str);
	}
	size = listchr_len(head, cursor);
	out = make_str(head, cursor, size);
	if (!out)
		free_list(&head);
	cursor += size;
	return (out);
}
