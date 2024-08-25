/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:27:23 by marvin            #+#    #+#             */
/*   Updated: 2024/08/23 11:27:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int main(int argc, char** argv)
{
    int i = 0;
    if(argc == 2)
    {
        while(argv[1][i] != '\0')
        {
            if(argv[1][i] >= 33 &&  argv[1][i] <= 126 && argv[1][i+1] != ' ')
                write(1, &argv[1][i], 1);
            if(argv[1][i] >= 33 &&  argv[1][i] <= 126 && argv[1][i+1] == ' ')
            {
                write(1, &argv[1][i], 1);
                write(1, &argv[1][i+1], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}