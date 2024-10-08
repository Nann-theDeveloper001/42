/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:05:41 by marvin            #+#    #+#             */
/*   Updated: 2024/08/27 18:05:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
   if(begin_list == NULL || *begin_list == NULL)
            return;
    t_list *current = *begin_list;
    if(cmp(current->data, data_ref) == 0)
    {
        *begin_list = current->next;
        free(current);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else //must add the else to pass the Moulinette
    {
        current = *begin_list;
        ft_list_remove_if(&current->next, data_ref, cmp);
    }
}