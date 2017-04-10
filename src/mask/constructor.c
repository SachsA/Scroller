/*
** constructor.c for repo in /repo/src/mask
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Apr 02 14:33:26 2017 Thomas Lombard
** Last update Sun Apr 02 15:26:12 2017 Thomas Lombard
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Image.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

static void	print_load_status(t_sprite *sprt, const char *file, int ld)
{
  static int	i = -1;

  printf("[IMAGE_LOAD   -> Image[%2d]]: %-40s\n", ++i, file);
  printf("\t\tSprite  : %s\n", ((sprt->spr) ?
				"\033[32mSuccessfully created\033[m" :
				(ld & L_SPR) ? "\033[31mNot created\033[m" :
				"\033[33mNot created but Ok\033[m"));
  printf("\t\tTexture : %s\n", ((sprt->tex) ?
				"\033[32mSuccessfully created\033[m" :
                                (ld & L_TEX) ? "\033[31mNot created\033[m" :
				"\033[33mNot created but Ok\033[m"));
  printf("\t\tImage   : %s\n", ((sprt->img) ?
				"\033[32mSuccessfully created\033[m" :
                                (ld & L_IMG) ? "\033[31mNot created\033[m" :
				"\033[33mNot created but Ok\033[m"));
}

int	construct_sprite(t_sprite *s, int ld)
{
  if (ld & L_SPR && !(s->spr = sfSprite_create()))
    return (1);
  if (ld & L_TEX && !(s->tex = sfTexture_createFromFile(DEFAULT_MASK, NULL)))
    return (1);
  if (ld & L_IMG && !(s->img = sfImage_createFromFile(DEFAULT_MASK)))
    return (1);
  if (s->tex)
    sfSprite_setTexture(s->spr, s->tex, sfTrue);
  print_load_status(s, DEFAULT_MASK, ld);
  return (0);
}

int	construct(sfVector2f *pos, sfVector2i *sizeChunk,
		  t_sprite *sprt, t_sprite *opp)
{
  *pos = (sfVector2f){-200, -100};
  *sizeChunk = (sfVector2i){200, 200};
  memset(sprt, 0, sizeof(t_sprite));
  memset(opp, 0, sizeof(t_sprite));
  if (construct_sprite(sprt, L_IMG | L_TEX | L_SPR) ||
      construct_sprite(opp, L_IMG | L_SPR))
    return (1);
  opposite(opp);
  return (0);
}
