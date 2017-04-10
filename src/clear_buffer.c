/*
** clear_buffer.c for clear_buffer in /home/sachs_a/delivery/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar 31 21:18:21 2017 Alexandre Sachs
** Last update Jan Apr 2 22:43:46 2017
*/

#include "my.h"

int		clear_buffer(t_my_framebuffer *framebuffer)
{
  unsigned int		i;

  i = 0;
  while (i < (framebuffer->height * framebuffer->width * 4))
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  return (0);
}
