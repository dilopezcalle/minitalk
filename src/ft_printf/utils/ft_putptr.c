/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:17:56 by dilopez-          #+#    #+#             */
/*   Updated: 2022/08/10 15:34:15 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putptr(unsigned long int dir)
{
	int	bytes;

	bytes = write(1, "0x", 2);
	bytes += ft_putunsigned_base(dir, "0123456789abcdef");
	return (bytes);
}
