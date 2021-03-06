/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_functions_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:54:14 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/26 21:36:35 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			countdgt_d_i(int nb)
{
	int				digit;
	unsigned int	nbr;

	digit = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nbr = (unsigned int)(nb * -1);
	else
		nbr = (unsigned int)nb;
	if (nbr <= 9)
		return (++digit);
	while (nbr > 0)
	{
		nbr /= 10;
		digit++;
	}
	return (digit);
}

int			countdgt_u(unsigned int nb)
{
	int				digit;
	unsigned int	nbr;

	digit = 0;
	if (nb == 0)
		return (1);
	nbr = (unsigned int)nb;
	if (nbr <= 9)
		return (++digit);
	while (nbr > 0)
	{
		nbr /= 10;
		digit++;
	}
	return (digit);
}

void		ft_itoa_custom_u(unsigned int n, char *arr)
{
	unsigned int		nb;
	int					sign;
	int					len;

	sign = 0;
	len = countdgt_u(n);
	nb = (unsigned int)n;
	while (len-- > sign)
	{
		arr[len] = nb % 10 + '0';
		nb = nb / 10;
	}
}

int			countdgt_base(unsigned long long nb, char *base)
{
	int digit;
	int i;

	i = ft_strlen(base);
	digit = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= i;
		digit++;
	}
	return (digit);
}

void		ft_putnbr_base(int n, char *base, char *str)
{
	unsigned int	nb;
	int				a;
	static int		i = 0;
	int				y;

	y = 0;
	if (i != 0)
		i = y;
	a = ft_strlen(base);
	nb = (unsigned int)n;
	if (nb >= a)
		ft_putnbr_base((nb / a), base, str);
	str[i++] = base[nb % a];
}
