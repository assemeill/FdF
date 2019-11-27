/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:39:42 by aszhilki          #+#    #+#             */
/*   Updated: 2019/11/26 13:01:33 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const **s1, char const **s2)
{
	int		n;
	int		i;

	n = 0;	
	i = 0;
	if (!s1 && !s2)
		return (0);
	while (!s1[i++])
		n++;
	i = 0;
	while (!s2[i++])
		n++;
	return (n);
}

char		**ft_arrayjoin(char const **s1, char const **s2)
{
	int		n;
	int 	i;
	char	**str;

	i = 0;	
	n = ft_count(s1, s2);
	if (!(str = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	while (*s1)
	{	
		if (!(str[i] = (char *)malloc(sizeof(char) * (ft_letters_count(*s1) + 1))))
			return (NULL);
		str[i] = ft_strcpy(str[i], *s1);
		s1++;
		i++;
	}
	while (*s2)
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (ft_letters_count(*s2) + 1))))
			return (NULL);
		str[i] = ft_strcpy(str[i], *s2);
		s2++;
		i++;
	}
	return (str);
}

#include <stdio.h>

int		main (void)
{
	char *s1[3] = {"Hello", "World", "!"};
	char *s2[2] = {"1", "2"};
	char **s3;
	s3 = ft_arrayjoin(s1, s2);
	printf("%s\n", s3[3]);
}
