/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:25:40 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/22 15:11:54 by mchetoui         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char			*str;
	int				size;
	static t_list	*head;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (1)
	{
		size = read(fd, str, BUFFER_SIZE);
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
	str = make_str(&head, listchr_len(head));
	return (str);
}
