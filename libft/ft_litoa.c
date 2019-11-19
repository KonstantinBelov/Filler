/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:33:40 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/22 19:33:42 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_litoa(long int n)
{
	size_t		len;
	char		*a;
	int			negative;

	if (n == LONG_MIN || n > LONG_MAX)
		return (ft_strdup("-2147483648"));
	else if (n < LONG_MIN)
		return (ft_strdup("2147483647"));
	len = ft_numlen(n);
	negative = 0;
	(n < 0) ? len++ : 1;
	(n < 0) ? negative = 1 : 1;
	(n < 0) ? n *= -1 : 1;
	if ((a = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	a[len] = '\0';
	while (len-- > 0)
	{
		a[len] = n % 10 + '0';
		n = n / 10;
	}
	(negative == 1) ? a[0] = '-' : 1;
	return (a);
}
