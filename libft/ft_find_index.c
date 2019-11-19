/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:38:31 by kbelov            #+#    #+#             */
/*   Updated: 2019/03/27 18:59:40 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Finds index of oc occurrence of char c in string s.
** If c is not in s return -1; If error return -2.
*/

#include "libft.h"

int			ft_find_index(char *s, char c, int oc)
{
	int		i;
	int		occu;

	if (!s || !c || !oc)
		return (-2);
	i = 0;
	occu = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (occu == oc)
				return (i);
			occu++;
		}
		i++;
	}
	return (-1);
}
