/*
** draw_square.c for draw_square in /home/sachs_a/delivery/
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar 31 21:00:30 2017 Alexandre Sachs
** Last update Fri Mar 31 22:18:42 2017 Alexandre Sachs
*/

#include "my.h"

int	draw_square(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  int	i;
  int	j;

  i = 0;
  while (i < 100)
    {
      j = 0;
      while (j < 100)
	{
	  my_put_pixel(framebuffer, (x + i) % 1920, (y + j) % 1080, color);
	  j++;
	}
      i++;
    }
  return (0);
}
