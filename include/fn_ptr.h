/*
** fn_ptr.h for Scroller in /home/invicta/scroller/include/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Sat Apr  1 10:51:38 2017 Kellian CIPIERRE
** Last update Sun Apr  2 10:48:58 2017 Alexandre Sachs
*/

#ifndef FN_PTR_H_
# define FN_PTR_H_

# include <SFML/Audio.h>
# include "my.h"

# define NB_SEQ 6

typedef struct		s_fn_ptr
{
  char			*seq;
  int			(*p)(t_my_framebuffer*, t_window*);
  sfMusic		*sound;
}			t_fnptr;

int			scroller(t_my_framebuffer*, t_window*);
int			slider(t_my_framebuffer *, t_window *);
int			text(t_my_framebuffer *, t_window *);
int			thick(t_my_framebuffer *, t_window *);
int			mask(t_my_framebuffer *, t_window *);
int			shooting_stars(t_my_framebuffer*, t_window*);

#endif	/* FN_PTR_H_ */
