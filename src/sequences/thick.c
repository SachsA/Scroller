/*
** thick.c for thick in /home/sachs_a/delivery/c_graphical_programming/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sun Apr  2 10:46:43 2017 Alexandre Sachs
** Last update Jan Apr 2 22:43:02 2017
*/

#include <math.h>
#include "my.h"
#include "text.h"

void		update_param(sfVector2f *tmp, sfVector2f *pos,
			     sfVector2f *param)
{
  tmp->x = pos->x;
  if (param->x == 1)
    {
      if (param->y > 0)
	tmp->y = pos->y + (5 - param->y) * 24;
      else
	tmp->y = pos->y - param->y * 24;
    }
  else
    {
      if (param->y < 0)
	tmp->y = pos->y + 5 * 24;
      else
	tmp->y = pos->y;
    }
}

int		thick(t_my_framebuffer *framebuffer,
		      t_window *my_window)
{
  sfVector2f	param;
  sfVector2f	pos;
  sfVector2f	tmp;
  sfTexture	*image;
  sfSprite	*spriteim;

  param = (sfVector2f){1, 5};
  pos = (sfVector2f){SCREEN_WIDTH / 2 - 192, SCREEN_HEIGHT / 2 - 12};
  image = sfTexture_createFromFile("fonts/font/font4.gif", NULL);
  spriteim = sfSprite_create();
  sfSprite_setTexture(spriteim, image, sfTrue);
  while (sfRenderWindow_isOpen(my_window->window))
    {
      if (!my_event(my_window))
	return (0);
      update_param(&tmp, &pos, &param);
      sfSprite_setPosition(spriteim, tmp);
      print_text2(0, (t_text){my_window->window, spriteim, tmp},
		  "EPITECH OKLM", param);
      my_window_update(framebuffer, my_window);
      if (param.y < -5 || param.y > 5)
	param.x *= -1;
      param.y = param.y - 0.01 * param.x;
    }
  return (free_point(image, spriteim));
}
