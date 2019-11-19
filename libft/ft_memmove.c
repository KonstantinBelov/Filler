/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:58:56 by kbelov            #+#    #+#             */
/*   Updated: 2019/02/22 15:01:10 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*psrc;
	char		*pdst;

	psrc = (char *)src;
	pdst = (char *)dst;
	if (psrc == pdst || len == 0)
		return (dst);
	while (len > 0)
	{
		if (pdst < psrc)
		{
			*pdst = *psrc;
			psrc++;
			pdst++;
			len--;
		}
		else
		{
			len--;
			pdst[len] = psrc[len];
		}
	}
	return (dst);
}
