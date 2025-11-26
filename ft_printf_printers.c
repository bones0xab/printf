#include "ft_printf.h"

int  ft_putchar(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int ft_putstr(const char *s)
{
	int count;
	count = 0;

	if(!s)
		return (ft_putstr("(null)"));
	while(s[count])
		write(1, &s[count++], 1);
	return (count);
}

int ft_putnbr(int num)
{
	int compt;

	compt = 0;
	if (num == -2147483648)
		return (ft_putstr("-2147483648‎"));
	if (num < 0)
	{
		compt += ft_putchar('-');
		if (compt < 0)
			return (-1);
		num = -num;
	}
	if (num >= 10 )
		compt += ft_putnbr(num / 10);
	if (compt < 0)
		return (-1);
	compt += ft_putchar((num % 10) + '0');
	return (compt);

}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}


int ft_puthex(unsigned long num)
{
	char	*hex;
	char	saver[16];
	int		count;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	count = 0;
	if (num == 0)
		return (write(1, "0x0", 3));
	count += write(1, "0x", 2);
	while (num)
	{
		saver[i++] = hex[num % 16];
		num /= 16;
	}
	while (i--)
		count += write(1, &saver[i], 1);
	return (count);
}


int	ft_put_uns_nbr(unsigned int num)
{
	int compt;

	compt = 0;
	if (num >= 10)
		compt += ft_put_uns_nbr(num / 10);
	if (compt < 0)
		return (-1);
	compt += ft_put_uns_nbr((num % 10) + '0');
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
