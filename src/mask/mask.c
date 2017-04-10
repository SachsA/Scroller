/*
** mask.c for repo in /repo/src/mask
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat Apr 01 23:06:00 2017 Thomas Lombard
** Last update Sun Apr 02 15:26:50 2017 Thomas Lombard
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Image.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void	apply_mask(sfVector2f		pos,
		   sfVector2i		sizeChunk,
		   t_sprite		sprt[2],
		   sfRenderWindow	*win)
{
  int	c;
  sfVector2i	i;

  c = 0;
  i.y = pos.y;
  while (i.y < SCREEN_HEIGHT)
    {
      i.x = pos.x;
      while (i.x < SCREEN_WIDTH)
	{
	  c = (c) ? 0 : 1;
	  sfSprite_setTextureRect(sprt[c].spr, (sfIntRect){i.x, i.y,
				  sizeChunk.x, sizeChunk.y});
	  sfSprite_setPosition(sprt[c].spr, (sfVector2f){i.x, i.y});
	  sfRenderWindow_drawSprite(win, sprt[c].spr, NULL);
	  i.x += sizeChunk.x;
	}
      i.y += sizeChunk.y;
    }
}

static inline void	set_increment(sfVector2f *inc, sfVector2f pos)
{
  if (pos.x <= -99 && pos.x >= -101)
    {
      inc->x = -1;
      inc->y = (rand() % 30 + 1) / 10.0 + 1.0;
    }
  else if (pos.x <= -249 && pos.x >= -251)
    {
      inc->x = 1;
      inc->y = (rand() % 30 + 1) / 10.0 + 1.0;
    }
}

int		mask(UNUSED t_my_framebuffer *buff, t_window *win)
{
  t_sprite	sprt[2];
  sfVector2f	pos;
  sfVector2i	sizeChunk;
  sfVector2f	inc;

  inc = (sfVector2f){1, 1};
  if (construct(&pos, &sizeChunk, &sprt[0], &sprt[1]))
    return (1);
  while (sfRenderWindow_isOpen(win->window))
    {
      if (!my_event(win))
	return (0);
      sfRenderWindow_clear(win->window, sfBlack);
      apply_mask(pos, sizeChunk, sprt, win->window);
      set_increment(&inc, pos);
      pos.x += inc.x;
      pos.y += (pos.y >= 0) ? -sizeChunk.y * 2 : inc.y;
      sfRenderWindow_display(win->window);
    }
  return (0);
}
