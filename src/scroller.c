/*
** scroller.c for scroller in /home/sachs_a/delivery/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar 31 20:24:25 2017 Alexandre Sachs
** Last update Jan Apr 2 22:46:05 2017
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"

void			my_window_update(t_my_framebuffer *framebuffer,
					 t_window *my_window)
{
  sfTexture_updateFromPixels(my_window->texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(my_window->window, my_window->sprite, NULL);
  sfRenderWindow_display(my_window->window);
  clear_buffer(framebuffer);
}

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  int			i;
  t_my_framebuffer	*framebuffer;

  i = -1;
  framebuffer = malloc(sizeof(t_my_framebuffer));
  if (framebuffer == NULL)
    return (0);
  framebuffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
  if (framebuffer->pixels == NULL)
    return (0);
  while (++i < width * height * 4)
    framebuffer->pixels[i] = 0;
  framebuffer->width = SCREEN_WIDTH;
  framebuffer->height = SCREEN_HEIGHT;
  return (framebuffer);
}

sfRenderWindow		*create_window(char *str, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.bitsPerPixel = 32;
  mode.width = width;
  mode.height = height;
  window = sfRenderWindow_create(mode, str, sfResize |
				 sfClose | sfFullscreen, NULL);
  return (window);
}

t_my_framebuffer	set_window(t_my_framebuffer *framebuffer,
				   t_window *my_window)
{
  my_window->window = create_window("SCROLLER : CIPIERRE/LOMBARD/SACHS #2017",
				    SCREEN_WIDTH, SCREEN_HEIGHT);
  sfRenderWindow_setVerticalSyncEnabled(my_window->window, sfTrue);
  framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  my_window->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  my_window->sprite = sfSprite_create();
  sfSprite_setTexture(my_window->sprite, my_window->texture, sfTrue);
  sfRenderWindow_setFramerateLimit((my_window->window), 60);
  return (*framebuffer);
}
