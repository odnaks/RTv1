/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strclen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:17:31 by drestles          #+#    #+#             */
/*   Updated: 2019/02/17 18:09:04 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

size_t		strclen(char *line, char c)
{
	size_t len;

	len = 0;
	while (line[len] != c && line[len])
	{
		len++;
	}
	return (len);
}
