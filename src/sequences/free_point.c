/*
** free_point.c for free_point in /home/sachs_a/delivery/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sun Apr  2 19:28:32 2017 Alexandre Sachs
** Last update Jan Apr 2 22:46:32 2017
*/

#include <stdlib.h>
#include "my.h"

int	free_point(sfTexture *image, sfSprite *sprite)
{
  sfTexture_destroy(image);
  sfSprite_destroy(sprite);
  return (0);
}
