/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:58:18 by drestles          #+#    #+#             */
/*   Updated: 2019/02/17 18:08:59 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			vec_modul(t_vec3 a)
{
	return (sqrt(vec_sc(a, a)));
}

double			vec_mod_div(t_vec3 a, t_vec3 b)
{
	t_vec3 c;

	c = vec_minus(a, b);
	return (sqrt(vec_sc(c, c)));
}
