/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addditional_printers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchti <abouchti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:21:16 by abouchti          #+#    #+#             */
/*   Updated: 2025/12/01 21:21:38 by abouchti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_uns_nbr(unsigned int num)
{
	int	compt;

	compt = 0;
	if (num >= 10)
		compt += ft_put_uns_nbr(num / 10);
	if (compt < 0)
		return (-1);
	compt += ft_putchar((num % 10) + '0');
	return (compt);
}

int	ft_print_low_hex(unsigned int num)
{
	char	*hex;
	char	saver[16];
	int		count;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	count = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num)
	{
		saver[i++] = hex[num % 16];
		num /= 16;
	}
	while (i--)
		count += write(1, &saver[i], 1);
	return (count);
}

int	ft_print_up_hex(unsigned int num)
{
	char	*hex;
	char	saver[16];
	int		count;
	int		i;

	hex = "0123456789ABCDEF";
	i = 0;
	count = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num)
	{
		saver[i++] = hex[num % 16];
		num /= 16;
	}
	while (i--)
		count += write(1, &saver[i], 1);
	return (count);
}
