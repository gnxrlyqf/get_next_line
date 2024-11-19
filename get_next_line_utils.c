/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:18:46 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/19 20:20:46 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*new;

	new = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!new || !src)
		return (NULL);
	i = -1;
	while (src[++i])
		new[i] = src[i];
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	remlen;
	char	*new;

	if (!len || !ft_strlen(s) || (int)start > ft_strlen(s) - 1)
		return (ft_strdup(""));
	remlen = (size_t)ft_strlen(s) - start;
	remlen = (remlen > len) * len + (remlen <= len) * remlen;
	new = malloc(remlen + 1);
	if (!new)
		return (NULL);
	new[remlen] = 0;
	len = -1;
	while (++len < remlen)
		*(new++) = *(s++ + start);
	return (new - len);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
