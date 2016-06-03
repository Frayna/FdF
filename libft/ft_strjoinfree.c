/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgourran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 22:56:05 by pgourran          #+#    #+#             */
/*   Updated: 2016/05/25 23:24:08 by pgourran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, char mode)
{
	char	*out;

	if ((out = ft_strjoin(s1, s2)) && mode >= 0 && mode <= 3)
	{
		if (mode == 1)
			free(s1);
		if (mode == 2)
			free(s2);
		if (mode == 3)
		{
			free(s1);
			free(s2);
		}
		return (out);
	}
	return (NULL);
}
