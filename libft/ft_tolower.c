/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:26:48 by aszhilki          #+#    #+#             */
/*   Updated: 2019/09/24 13:15:29 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int arg)
{
	if (arg != '\0')
	{
		if (arg >= 65 && arg <= 90)
			arg = arg + 32;
	}
	return (arg);
}
