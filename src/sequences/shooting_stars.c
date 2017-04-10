/*
** shooting_stars.c for Scroller in /home/invicta/scroller/src/sequences/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Sun Apr  2 10:20:07 2017 Kellian CIPIERRE
** Last update Jan Apr 2 22:40:04 2017
*/

#include <stdlib.h>
#include "my.h"
#include "time.h"

int		init_sprites(sfSprite **sprite, sfSprite **wall,
			      sfVector2f *pos)
{
  sfTexture	*image;

  *pos = (sfVector2f){0, 0};
  if (!(image = sfTexture_createFromFile("fonts/picture/stars6.jpg", NULL)))
    return (0);
  *wall = sfSprite_create();
  sfSprite_setTexture(*wall, image, sfTrue);
  sfSprite_setScale(*wall, (sfVector2f){1.8, 1.8});
  pos->x = SCREEN_WIDTH / 2 - (550 / 2);
  pos->y = SCREEN_HEIGHT / 2 - (524 / 2);
  image = sfTexture_createFromFile("fonts/picture/start.png", NULL);
  *sprite = sfSprite_create();
  sfSprite_setPosition(*sprite, *pos);
  sfSprite_setTexture(*sprite, image, sfTrue);
  free(image);
  return (1);
}

void		update_values(sfVector2f *scale, sfVector2f *pos,
			      sfSprite *sprite)
{
  scale->x *= 1.03;
  scale->y *= 1.03;
  pos->x = SCREEN_WIDTH / 2 - (550 * scale->x / 2);
  pos->y = SCREEN_HEIGHT / 2 - (524 * scale->y / 2);
  sfSprite_setScale(sprite, (sfVector2f){scale->x, scale->y});
  sfSprite_setPosition(sprite, *pos);
}

void		update_scene(t_my_framebuffer *framebuffer,
			     t_window *my_window, sfSprite *wall,
			     sfSprite *sprite)
{
  sfRenderWindow_drawSprite(my_window->window, wall, NULL);
  sfRenderWindow_drawSprite(my_window->window, sprite, NULL);
  my_window_update(framebuffer, my_window);
}

void		free_sprites(sfSprite *sprite, sfSprite *wall)
{
  free(sprite);
  free(wall);
}

int		shooting_stars(t_my_framebuffer *framebuffer,
		       t_window *my_window)
{
  sfSprite	*sprite;
  sfSprite	*wall;
  sfVector2f	scale;
  sfVector2f	pos;
  sfVector2f	move;

  srand(time(NULL));
  if (!init_sprites(&sprite, &wall, &pos))
    return (0);
  while (sfRenderWindow_isOpen(my_window->window))
    {
      move.x = rand() % SCREEN_WIDTH - SCREEN_WIDTH / 2;
      move.y = rand() % SCREEN_WIDTH - SCREEN_HEIGHT / 2;
      sfSprite_setOrigin(sprite, move);
      scale = (sfVector2f){0.01, 0.01};
      while (scale.x < 6)
	{
	  sfRenderWindow_clear(my_window->window, sfBlack);
	  if (!my_event(my_window))
	    return (0);
	  update_values(&scale, &pos, sprite);
	  update_scene(framebuffer, my_window, wall, sprite);
	}
    }
  return (free_sprites(sprite, wall), 0);
}
