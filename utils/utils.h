/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:58:53 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/02 15:52:02 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"
# include "../libft/libft.h"
# include <math.h>

void	*ft_calloc2(size_t cnt, size_t size);
t_vec3	*vec3_new(double x, double y, double z);
void	vec3_del(t_vec3 *vec);
t_vec3	*vec3_add(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_sub(t_vec3 *a, t_vec3 *b);
t_vec3	*vec3_mul(t_vec3 *a, int n);
double	vec3_dot(t_vec3 *a, t_vec3 *b);
double	vec3_len_sq(t_vec3 *a);
double	vec3_len(t_vec3 *a);

#endif
