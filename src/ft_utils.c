/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 07:59:48 by dilopez-          #+#    #+#             */
/*   Updated: 2022/08/11 08:58:44 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

int	ft_atoi(const char *str)
{
	int	negative;
	int	number;
	int	i;

	negative = 0;
	number = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((int)str[i] >= '0' && (int)str[i] <= '9')
	{
		number = number * 10;
		number += str[i] - '0';
		i++;
	}
	if (negative == 1)
		number = -number;
	return (number);
}