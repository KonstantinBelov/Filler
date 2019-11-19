/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:33:20 by kbelov            #+#    #+#             */
/*   Updated: 2019/10/22 19:33:22 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_hhitoa(signed char n)
{
	size_t		len;
	char		*a;
	int			negative;

	if (n == SCHAR_MIN)
		return (ft_strdup("-128"));
	else if (n < SCHAR_MIN)
		return (ft_strdup("127"));
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
	if (negative == 1)
		a[0] = '-';
	return (a);
}
