/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:18:46 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/21 20:49:55 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*new_node(char c)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->c = c;
	new->next = NULL;
	return (new);
}

void	add_node(t_list **head, t_list *new)
{
	t_list	*curr;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	free_list(t_list **head)
{
	t_list	*current;
	t_list	*temp;

	if (!head)
		return ;
	current = *head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}

char *make_str(t_list **head, int size)
{
	char *new;
	t_list *curr;
	int i;

	new = malloc(sizeof(char) * (size + 1));
	if (!new || !*head || !size)
		return (NULL);
	new[size] = 0;
	i = size;
	curr = *head;
	while (curr && i)
	{
		*(new++) = curr->c;
		i--;
		curr = curr->next;
	}
	*head = curr;
	return (new - size);
}

int listchr_len(t_list *head)
{
	int len;
	t_list *curr;

	curr = head;
	len = 0;
	while (curr && curr->c != '\n')
	{
		len++;
		curr = curr->next;
	}
	if (curr->next)
		len++;
	return (len);
}
