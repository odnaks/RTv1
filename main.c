/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:13:26 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 23:16:59 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_main(t_rt *rt)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, W_W, W_H, "RTv1");
	rt->cam.x = 0.0;
	rt->cam.y = 0.0;
	rt->cam.z = 0.0;
	rt->null.x = 0.0;
	rt->null.y = 0.0;
	rt->null.z = 0.0;
	rt->amb = 0.0;



	rt->light.dot.x = 0.00000;
	rt->light.dot.y = 0.00000;
	rt->light.dot.z = 1.500000;
	rt->light.inten = 0.900000;

	rt->rot_xy = 0.0;
	rt->rot_yz = 0.0;
	rt->rot_xz = 0.0;
}

int		main()
{
	t_rt *rt;

	if (!(rt = (t_rt*)malloc(sizeof(t_rt))))
		exit(1);
	init_main(rt);
	rtv1(rt);
	mlx_hook(rt->win_ptr, 2, 0, deal_key, rt);
	mlx_hook(rt->win_ptr, 17, 0, exit_x, rt);
	mlx_loop(rt->mlx_ptr);
	return (0);
}
