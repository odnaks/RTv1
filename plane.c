/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:48:35 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/17 18:08:33 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ray_plane_x(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;
	double t;
	t_vec3 temp_d;

	temp_d = rt->dir;
	rt->dir.x = temp_d.x * cos(obj->a_xy) - temp_d.y * sin(obj->a_xy);
	rt->dir.y = temp_d.x * sin(obj->a_xy) + temp_d.y * cos(obj->a_xy);
	k1 = (rt->dir.x * rt->dir.x);
	k2 = 2.0 * (rt->dir.x * obj->oc.x);
	k3 = (obj->oc.x * obj->oc.x);
	obj->desc = k2 * k2 - 4.000000 * k1 * k3;
	if (obj->desc <= -0.000001)
		return (-1.0);
	t = (-k2) / (2.000000 * k1);
	obj->res = INFINITY;
	if (t >= 0.000000 && t < INFINITY)
		obj->res = t;
	obj->dot.x = rt->cam.x + rt->init.x * (obj->res + 1.0);
	obj->dot.y = rt->cam.y + rt->init.y * obj->res;
	obj->dot.z = rt->cam.z + rt->init.z * obj->res;
	return (obj->res);
}

double		ray_plane_y(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;
	double t;
	t_vec3 temp_d;

	temp_d = rt->dir;
	rt->dir.x = temp_d.x * cos(obj->a_xy) - temp_d.y * sin(obj->a_xy);
	rt->dir.y = temp_d.x * sin(obj->a_xy) + temp_d.y * cos(obj->a_xy);
	k1 = (rt->dir.y * rt->dir.y);
	k2 = 2.0 * (rt->dir.y * obj->oc.y);
	k3 = (obj->oc.y * obj->oc.y);
	obj->desc = k2 * k2 - 4.000000 * k1 * k3;
	if (obj->desc <= -0.000001)
		return (-1.0);
	t = (-k2) / (2.000000 * k1);
	obj->res = INFINITY;
	if (t > 0.000000 && t < INFINITY)
		obj->res = t;
	obj->dot.x = rt->cam.x + rt->init.x * obj->res;
	obj->dot.y = rt->cam.y + rt->init.y * (obj->res + 1.0);
	obj->dot.z = rt->cam.z + rt->init.z * obj->res;
	return (obj->res);
}

double		ray_plane_z(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;
	double t;
	t_vec3 temp_d;

	temp_d = rt->dir;
	rt->dir.x = temp_d.x * cos(obj->a_xy) - temp_d.y * sin(obj->a_xy);
	rt->dir.y = temp_d.x * sin(obj->a_xy) + temp_d.y * cos(obj->a_xy);
	k1 = (rt->dir.z * rt->dir.z);
	k2 = 2.0 * (rt->dir.z * obj->oc.z);
	k3 = (obj->oc.z * obj->oc.z);
	obj->desc = k2 * k2 - 4.000000 * k1 * k3;
	if (obj->desc <= -0.000001)
		return (-1.0);
	t = (-k2) / (2.000000 * k1);
	obj->res = INFINITY;
	if (t > 0.000000 && t < INFINITY)
		obj->res = t;
	obj->dot.x = rt->cam.x + rt->init.x * obj->res;
	obj->dot.y = rt->cam.y + rt->init.y * obj->res;
	obj->dot.z = rt->cam.z + rt->init.z * (obj->res + 1.0);
	return (obj->res);
}
