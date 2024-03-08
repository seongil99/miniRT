/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:23:50 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/08 13:23:51 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdio.h>
# include "structures.h"

void	write_color(t_color3 pixel_color);
void	put_color(t_img *data, int x, int y, t_color3 pixel_color);

#endif
