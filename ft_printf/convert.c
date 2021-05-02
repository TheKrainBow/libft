/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:47:41 by magostin          #+#    #+#             */
/*   Updated: 2021/05/02 19:37:37 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_hx_recu(unsigned long long int n, char *s,
int b_s, t_pf *printf_s)
{
	if (n == 0)
		return ;
	ft_hx_recu(n / b_s, s, b_s, printf_s);
	ft_putchar_pf((s[n % b_s]), printf_s);
}

void				ft_puthexa(unsigned long long int n, char *s,
int b_s, t_pf *printf_s)
{
	t_arg		*arg;

	arg = printf_s->arg;
	if (n == 0)
	{
		if (arg->accu == 1 && arg->accu_value == 0 && (arg->width == 0 ||
		(arg->width != 0 && arg->type == 'p' && arg->flags != '-')))
			return ;
		ft_putchar_pf(arg->accu == 1 &&
		arg->accu_value == 0 ? ' ' : '0', printf_s);
		return ;
	}
	else
		ft_hx_recu(n, s, b_s, printf_s);
}

void				nbr_recu(long long int n, char *s, int b_s, t_pf *printf_s)
{
	if (n == 0)
		return ;
	nbr_recu(n / b_s, s, b_s, printf_s);
	ft_putchar_pf(s[n % b_s], printf_s);
}

void				ft_putnbrbase(long long int n, char *base, t_pf *printf_s)
{
	int				b_size;
	long long int	number;
	t_arg			*arg;

	arg = printf_s->arg;
	number = n;
	if (n == LLONG_MIN)
	{
		ft_putstring("9223372036854775808", printf_s);
		return ;
	}
	if (n < 0)
		number = -number;
	b_size = ft_strlen(base);
	if (n == 0)
	{
		if (arg->accu == 1 && arg->accu_value == 0 && arg->width == 0)
			return ;
		ft_putchar_pf(arg->accu == 1 &&
		arg->accu_value == 0 ? ' ' : '0', printf_s);
		return ;
	}
	else
		nbr_recu(number, base, b_size, printf_s);
}

int					ft_sizenbr(long long int n, int base_size)
{
	int			size_nbr;

	size_nbr = 1;
	if (n == LLONG_MIN)
		return (19);
	n = n < 0 ? -n : n;
	while ((n = n / base_size) > 0)
		size_nbr++;
	return (size_nbr);
}
