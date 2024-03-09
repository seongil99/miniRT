/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyoon <seonyoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:23:09 by seonyoon          #+#    #+#             */
/*   Updated: 2024/03/09 17:39:01 by seonyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structures.h"

# define AMBIENT_STR "A"
# define CAM_STR "C"
# define LIGHT_STR "L"
# define SPHERE_STR "sp"
# define PLAIN_STR "pl"
# define CYLINDER_STR "cy"

# define ERR_OUT_OF_RANGE "Out of range\n"
# define ERR_NUM_TOO_LONG "Number too long\n"
# define ERR_WRONG_VALUE "Wrong value\n"
# define ERR_WRONG_ARGS "Wrong arguments\n"
# define ERR_IDENTIFIER "Identifier error\n"


t_scene		*read_rt_file(char *filename);
void		parse_ambient(t_scene *scene, char **split);
void		parse_camera(t_scene *scene, char **split);
void		parse_light(t_scene *scene, char **split);
void		parse_sphere(t_scene *scene, char **split);
void		parse_plain(t_scene *scene, char **split);
void		parse_cylinder(t_scene *scene, char **split);
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

#endif
