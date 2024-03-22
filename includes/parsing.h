/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:23:09 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/21 12:49:21 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structures.h"

# define FILE_EXTENSION ".rt"

# define AMBIENT_STR "A"
# define CAM_STR "C"
# define LIGHT_STR "L"
# define SPHERE_STR "sp"
# define PLAIN_STR "pl"
# define CYLINDER_STR "cy"

# define ERR_OUT_OF_RANGE "Out of range\n"
# define ERR_NUM_TOO_LONG "Number too long\n"
# define ERR_WRONG_VALUE "Wrong value\n"
# define ERR_IDENTIFIER "Identifier error\n"
# define ERR_TOO_MANY_AMBIENT "Too many A\n"
# define ERR_TOO_MANY_CAMERA "Too many C\n"
# define ERR_WRONG_FILENANME "Wrong file name\n"

typedef struct s_parse_data
{
	int	num_ambient;
	int	num_camera;
	int	num_light;
	int	num_sphere;
	int	num_plain;
	int	num_cylinder;
}	t_parse_data;

void		read_rt_file(t_scene *scene, char *filename);
void		parse_ambient(t_scene *scene, char **split, t_parse_data *data);
void		parse_camera(t_scene *scene, char **split, t_parse_data *data);
void		parse_light(t_scene *scene, char **split, t_parse_data *data);
void		parse_sphere(t_scene *scene, char **split, t_parse_data *data);
void		parse_plain(t_scene *scene, char **split, t_parse_data *data);
void		parse_cylinder(t_scene *scene, char **split, t_parse_data *data);
t_color3	parse_color(char *str);
t_point3	parse_crd(char *str);
t_vec3		parse_nvec(char *str);
void		split_clear(char **sp);
int			split_size(char **split);
int			is_double(const char *s);
int			is_comma(char c);
int			is_dot(char c);
double		ft_atof(const char *s);
int			ft_atoi2(const char *str);
int			count_commma(char *str);

#endif
