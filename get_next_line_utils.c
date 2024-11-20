/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchetoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:18:46 by mchetoui          #+#    #+#             */
/*   Updated: 2024/11/20 20:19:15 by mchetoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_node(t_list **head, char c)
{
	t_list	*curr;
	static t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ; 
	new->c = c;
	new->next = NULL;
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

char *make_str(t_list *head, int start, int size)
{
	char *new;
	t_list *curr;
	int i;

	new = malloc(size + 1);
	if (!new || !head || !size)
		return (NULL);
	new[size] = 0;
	i = 0;
	curr = head;
	while (curr && size)
	{
		if (i++ >= start)
		{
			*(new++) = curr->c;
			size--;
		}
		curr = curr->next;
	}
	return (new - (i - start));
}

int listchr_len(t_list *head, int start)
{
	int len;
	int i;
	t_list *curr;

	curr = head;
	i = 0;
	len = 0;
	while (curr && i++ < start)
		curr = curr->next;
	while (curr && curr->c != '\n')
	{
		len++;
		curr = curr->next;
	}
	if (curr->next)
		len++;
	return (len);
}
