/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:47:21 by marvin            #+#    #+#             */
/*   Updated: 2024/08/26 22:47:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    if(str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f' )
        i++;
    if(str[i] == '-')
        sign = -1;
    else if(str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9') 
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

void hexPrint(int num)
{
    char hexDigits [] = "0123456789abcdef";
    if(num >= 16)
        hexPrint(num / 16);
    write(1, &hexDigits[num % 16], 1);
}
int main(int argc, char** argv)
{
    if(argc == 2)
    {
        int num = ft_atoi(argv[1]);
        hexPrint(num);
    }
    write(1, "\n", 1);
}
