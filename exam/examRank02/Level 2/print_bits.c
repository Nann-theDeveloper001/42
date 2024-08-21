/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:03:11 by marvin            #+#    #+#             */
/*   Updated: 2024/08/21 11:03:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_bits(unsigned char octet)
{
   int i = 8;
   unsigned char bit;

   while(i--)
   {
    bit = (octet >> i & 1) + '0';
    write(1, &bit, 1);
   }
}