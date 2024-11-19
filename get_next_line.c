/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:25:40 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/19 20:47:33 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char str[BUFFER_SIZE];
	int size;
	static unsigned int i;
	int len;
	char *out;

	if (!i)
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		str[size] = 0;
	}
	len = 0;
	while (str[i + len] && str[i + len] != '\n')
		len++;
	out = ft_substr(str, i, ++len);
	i += len;
	return (out);
}
