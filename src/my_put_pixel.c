/*
** my_put_pixel.c for scroller in /home/sachs_a/delivery/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar 31 20:28:01 2017 Alexandre Sachs
** Last update Jan Apr 2 22:44:57 2017
*/

#include <SFML/Graphics.h>
#include "my.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y,
		     sfColor color)
{
  if ((unsigned int) x <= framebuffer->width &&
      (unsigned int) y <= framebuffer->height && x >= 0 && y >= 0)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
