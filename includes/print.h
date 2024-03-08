#ifndef PRINT_H
# define PRINT_H

# include <stdio.h>
# include "structures.h"

void	write_color(t_color3 pixel_color);
void	put_color(t_img *data, int x, int y, t_color3 pixel_color);

#endif
