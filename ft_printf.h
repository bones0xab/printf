#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_putstr(const char *s);
int	ft_putnbr(int num);
int	ft_strlen(const char *s);
int	ft_printhex(unsigned long num);


#endif
