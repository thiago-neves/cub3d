/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:31 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 14:58:32 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error_message_handler(int error_number)
{
	if (error_number == 1)
		printf("Invalid arguments\n");
	else if (error_number == 2)
		printf("Invalid configuration in .cub file\n");
}
