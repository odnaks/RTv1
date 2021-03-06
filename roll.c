/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:27:23 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/17 18:08:37 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		calc_res(double k1, double k2, double k3)
{
	double t1;
	double t2;
	double res;
	double desc;

	desc = k2 * k2 - 4.0 * k1 * k3;
	if (desc < 0.0)
		return (-1.0);
	t1 = (-k2 + sqrt(desc)) / (2.0 * k1);
	t2 = (-k2 - sqrt(desc)) / (2.0 * k1);
	res = INFINITY;
	if (t1 >= 0.0 && t1 < INFINITY)
		res = t1;
	if (res >= 0.0)
	{
		if (t2 >= 0.0 && t2 < INFINITY && t2 < res)
			res = t2;
	}
	else
	{
		if (t2 >= 0.0 && t2 < INFINITY)
			res = t2;
	}
	return (res);
}

double		ray_roll(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;
	t_vec3 rotation;

	rotation = rt->dir;
	rt->dir.x = rotation.x * cos(obj->a_xy * 0.5)
	- rotation.y * sin(obj->a_xy * 0.5);
	rt->dir.y = rotation.x * sin(obj->a_xy * 0.5)
	+ rotation.y * cos(obj->a_xy * 0.5);
	obj->b = 1.0;
	k1 = (rt->dir.z * rt->dir.z * obj->a * obj->a)
	+ (rt->dir.x * rt->dir.x * obj->b * obj->b);
	k2 = 2.0 * ((rt->dir.z * obj->oc.z * obj->a * obj->a)
	+ (rt->dir.x * obj->oc.x * obj->b * obj->b));
	k3 = (obj->oc.z * obj->oc.z * obj->a * obj->a)
	+ (obj->oc.x * obj->oc.x * obj->b * obj->b)
	- (obj->a * obj->a * obj->b * obj->b);
	return (calc_res(k1, k2, k3));
}
