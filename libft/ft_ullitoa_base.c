/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 21:44:00 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/28 21:24:13 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ullitoa_base(unsigned long long value, int base)
{
	char		*digits;
	char		*num;
	intmax_t	n;
	int			i;

	digits = ft_strdup("0123456789ABCDEF");
	if (value == 0)
		return ("0");
	i = 0;
	n = value;
	while (n)
	{
		n /= base;
		i++;
	}
	if (!(num = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num[i] = '\0';
	while (value)
	{
		i--;
		num[i] = digits[value % base];
		value /= base;
	}
	return (num);
}
