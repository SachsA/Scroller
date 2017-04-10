/*
** revert_color.c for repo in /repo/src/mask
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Apr 02 14:35:20 2017 Thomas Lombard
** Last update Sun Apr 02 14:35:29 2017 Thomas Lombard
*/

#include "my.h"

static inline sfColor	revert(sfColor color)
{
  color.r = 255 - color.r;
  color.g = 255 - color.g;
  color.b = 255 - color.b;
  return (color);
}

void		opposite(t_sprite *opp)
{
  sfVector2u	i;
  sfVector2u	size;
  sfColor	color;

  i.y = 0;
  size = sfImage_getSize(opp->img);
  while (i.y < size.y)
    {
      i.x = 0;
      while (i.x < size.x)
	{
	  color = sfImage_getPixel(opp->img, i.x, i.y);
	  color = revert(color);
	  sfImage_setPixel(opp->img, i.x, i.y, color);
	  ++i.x;
	}
      ++i.y;
    }
  opp->tex = sfTexture_createFromImage(opp->img, NULL);
  sfSprite_setTexture(opp->spr, opp->tex, sfTrue);
}
