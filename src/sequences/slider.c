/*
** slider.c for slider in /home/sachs_a/deliv
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sat Apr  1 22:28:46 2017 Alexandre Sachs
** Last update Sun Apr  2 22:49:32 2017 Alexandre Sachs
*/

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "slider.h"

sfSprite	*init_sprite()
{
  sfTexture	*image;
  sfSprite	*spriteim;

  if ((image = sfTexture_createFromFile("fonts/pnb/title.png", NULL)) == NULL)
    return (NULL);
  spriteim = sfSprite_create();
  sfSprite_setTexture(spriteim, image, sfTrue);
  free(image);
  return (spriteim);
}

void		cut_draw_texture(t_window *my_window, t_incre incre,
				 sfSprite *spriteim, sfSprite *spriteim2)
{
  sfVector2f	pos;

  sfRenderWindow_clear(my_window->window, sfBlack);
  pos = (sfVector2f){SCREEN_WIDTH / 2 - 150,
		     SCREEN_HEIGHT / 4 + 106 - incre.j};
  while (pos.y++ < ((SCREEN_HEIGHT * 3) / 4) + incre.i)
    {
      sfSprite_setTextureRect(spriteim, (sfIntRect){0, incre.i, 266, 1});
      sfSprite_setPosition(spriteim, pos);
      sfRenderWindow_drawSprite(my_window->window, spriteim, NULL);
    }
  sfSprite_setTextureRect(spriteim, (sfIntRect){0, incre.i, 266, incre.j});
  sfSprite_setTextureRect(spriteim2, (sfIntRect){0, 0, 266, incre.i});
  sfSprite_setPosition(spriteim2, (sfVector2f){SCREEN_WIDTH / 2 - 150
	, SCREEN_HEIGHT / 4});
  sfSprite_setPosition(spriteim, pos);
  sfRenderWindow_drawSprite(my_window->window, spriteim, NULL);
  sfRenderWindow_drawSprite(my_window->window, spriteim2, NULL);
}

int		slider(t_my_framebuffer *framebuffer,
		       t_window *my_window)
{
  t_incre	incre;
  sfSprite	*spriteim;
  sfSprite	*spriteim2;

  incre.i = 106;
  incre.j = 1;
  incre.k = 1;
  if (!(spriteim = init_sprite()) || !(spriteim2 = init_sprite()))
    return (0);
  while (sfRenderWindow_isOpen(my_window->window))
    {
      if (!my_event(my_window))
        return (0);
      cut_draw_texture(my_window, incre, spriteim, spriteim2);
      if (incre.i < 0 || incre.i > 106)
	incre.k *= -1;
      incre.i -= incre.k;
      incre.j += incre.k;
      my_window_update(framebuffer, my_window);
      usleep(10000);
    }
  sfSprite_destroy(spriteim);
  sfSprite_destroy(spriteim2);
  return (0);
}
