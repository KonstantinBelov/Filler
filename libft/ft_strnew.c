/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:02:02 by kbelov            #+#    #+#             */
/*   Updated: 2019/02/17 14:34:37 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	void	*mem;

	mem = (char *)malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, '\0', size + 1);
	return (mem);
}
