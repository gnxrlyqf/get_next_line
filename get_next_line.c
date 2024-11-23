/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:25:40 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/23 04:01:01 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	char			*str;
	int				size;
	static t_list	*head;

	str = malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !str)
		return (free(str), NULL);
	while (1)
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size < 0)
			return (free(str), NULL);
		str[size] = '\0';
		if (!populate_list(&head, str))
		{
			free_list(&head);
			break ;
		}
		if (contains_nl(str) || size <= 0)
			break ;
	}
	free(str);
	return (make_str(&head, listchr_len(head)));
}
