/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 21:44:00 by kbelov            #+#    #+#             */
/*   Updated: 2019/06/03 23:06:42 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	char	*digits;
	char	*num;
	int		n;
	int		i;
	int		sign;

	digits = ft_strdup("0123456789ABCDEF");
	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	if (value == 0)
		return (ft_strdup("0"));
	i = ft_itoa_base2(&sign, &value, &n, &base);
	if (!(num = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num[i] = '\0';
	while (value)
	{
		i--;
		num[i] = digits[value % base];
		value /= base;
	}
	(sign == -1) ? i-- : 1;
	(sign == -1) ? num[i] = '-' : 1;
	return (num);
}

int		ft_itoa_base2(int *sign, int *value, int *n, int *base)
{
	int i;

	i = 0;
	*sign = 1;
	(*value < 0) ? *sign = -1 : 1;
	(*value < 0) ? i++ : 1;
	(*value < 0) ? *value *= -1 : 1;
	*n = *value;
	while (*n)
	{
		*n /= *base;
		i++;
	}
	return (i);
}
