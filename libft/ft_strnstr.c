/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:08:19 by kbelov            #+#    #+#             */
/*   Updated: 2019/02/28 20:03:47 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			len_needle;

	len_needle = ft_strlen(needle);
	if (*needle == '\0' || needle == haystack)
		return ((char *)haystack);
	while (*haystack != '\0' && len-- >= len_needle)
	{
		if (*needle == *haystack && ft_memcmp(haystack, needle, len_needle)
				== 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
