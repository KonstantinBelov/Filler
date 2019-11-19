/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:23:17 by kbelov            #+#    #+#             */
/*   Updated: 2019/02/22 15:09:52 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	s2 = (char *)malloc(sizeof(const char) * (len + 1));
	if (!s2)
		return (NULL);
	while (len >= 0)
	{
		s2[len] = s1[len];
		len--;
	}
	return (s2);
}
