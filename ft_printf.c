#include "ft_printf.h"


static int convert(va_list args, const char s)
{
	int print;

	print = 0;

	if (s == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (s == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (s == 'p')
		print += ft_puthex((unsigned long)va_arg(args, void *));
	else if (s == 'd' || s == 'i')
		print += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		print += ft_put_uns_nbr(va_arg(args, unsigned int));
	else if (s == 'x')
		print += ft_print_low_hex(va_arg(args, unsigned int));
	else if (s == 'X')
		print += ft_print_up_hex(va_arg(args, unsigned int));
	else if (s == '%')
		print += write(1, "%", 1);
	return (print);

}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	va_start(args, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1])
			{
				count += convert(args, str[i +1]);
				i++;
			}
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
