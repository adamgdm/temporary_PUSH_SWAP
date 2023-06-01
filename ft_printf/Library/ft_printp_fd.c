/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:10:17 by agoujdam          #+#    #+#             */
/*   Updated: 2023/06/01 05:56:28 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printp_fd(void *c, int fd)
{
	int	count;

	count = 0;
	count += ft_putstr_fd("0x", fd);
	count += ft_puthex_fd((unsigned long int)c, fd, 'x');
	return (count);
}
