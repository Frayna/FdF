/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgourran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:20:26 by pgourran          #+#    #+#             */
/*   Updated: 2015/12/03 18:15:17 by pgourran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *tmp;

	if (*alst)
	{
		ptr = *alst;
		tmp = ptr->next;
		del(ptr->content, ptr->content_size);
		free(*alst);
		*alst = NULL;
	}
}
