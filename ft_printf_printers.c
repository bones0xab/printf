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
	if (num == -2147483648‎)
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
	count += ft_putchar((num % 10) + '0');
	return (count);

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


