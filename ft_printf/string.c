/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:47:28 by magostin          #+#    #+#             */
/*   Updated: 2021/05/02 19:38:10 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putstring(char *s, t_pf *printf_s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (i >= printf_s->arg->accu_value && printf_s->arg->accu == 1)
			return ;
		ft_putchar_pf(s[i], printf_s);
		i++;
	}
}

int					ft_countletter(char *s, t_pf *printf_s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (i >= printf_s->arg->accu_value && printf_s->arg->accu == 1)
			return (i);
		i++;
	}
	return (i);
}

void				ft_string_function(char *s, t_pf *printf_s)
{
	int		i;
	t_arg	*arg;

	arg = printf_s->arg;
	if (!s)
		s = "(null)";
	if (arg->width < 0)
	{
		arg->width *= -1;
		arg->flags = '-';
	}
	arg->accu_value = arg->accu == 1 &&
	arg->accu_value < 0 ? (int)ft_strlen(s) : arg->accu_value;
	i = ft_countletter(s, printf_s) - 1;
	if (arg->flags == '-')
		ft_putstring(s, printf_s);
	while (++i < arg->width)
		ft_putchar_pf(arg->flags == '0' ? '0' : ' ', printf_s);
	if (arg->flags != '-')
		ft_putstring(s, printf_s);
}
