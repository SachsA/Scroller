/*
** pokemon.c for Scroller in /home/invicta/scroller/src/sequences/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Sat Apr  1 11:53:31 2017 Kellian CIPIERRE
** Last update Jan Apr 2 22:28:45 2017
*/

#include <stdlib.h>
#include "my.h"

sfSprite			*sprite_from_file(char *file, int x, int y,
						  t_slide *slide)
{
  sfTexture			*image;
  sfSprite			*sprite_image;

  if ((image = sfTexture_createFromFile(file, NULL)) == NULL)
    return (NULL);
  sfTexture_setRepeated(image, sfTrue);
  sprite_image = sfSprite_create();
  sfSprite_setTexture(sprite_image, image, sfTrue);
  if (slide->scale == sfTrue)
    sfSprite_setScale(sprite_image, (sfVector2f){1.5, 1.5});
  if (slide->repeat == sfTrue)
    sfSprite_setTextureRect(sprite_image, (sfIntRect){x, 0, x * 10, y});
  sfSprite_setOrigin(sprite_image, (sfVector2f){x, 0});
  return (sprite_image);
}

void				my_sprite_update(t_window *my_window,
						 t_slide *images)
{
  sfRenderWindow_clear(my_window->window, sfBlue);
  while (images != NULL)
    {
      if ((images->pos.x = (images->pos.x + 500 /
			    (2 * (SCREEN_HEIGHT - images->pos.y)))) > 1280)
	images->pos.x = 0;
      sfSprite_setPosition(images->sprite, images->pos);
      sfRenderWindow_drawSprite(my_window->window, images->sprite, NULL);
      images = images->next;
    }
}

void				destroy_list(t_slide *images)
{
  while (images != NULL)
    {
      sfSprite_destroy(images->sprite);
      free(images->prev);
      images = images->next;
    }
  free(images);
}

int				scroller(t_my_framebuffer *framebuffer,
					 t_window *my_window)
{
  t_slide			*images;
  t_player			player[NB_PLAYER + 1];

  if (init_player(player))
    return (0);
  if (init_sprite_list(&images) == 0)
    return (0);
  while (sfRenderWindow_isOpen(my_window->window))
    {
      if (!my_event(my_window))
	return (0);
      my_sprite_update(my_window, images);
      draw_player(my_window->window, player);
      my_window_update(framebuffer, my_window);
    }
  destroy_list(images);
  destruct_player(player);
  return (0);
}
