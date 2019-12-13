/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:30:21 by kbelov            #+#    #+#             */
/*   Updated: 2019/04/08 13:04:53 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else if (a > b)
		return (b);
	else
		return (-1);
}
