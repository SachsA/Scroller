/*
** constructors_pokemon.c for repo in /src/sequences/pokemon
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Apr 02 20:35:24 2017 Thomas Lombard
** Last update Sun Apr 02 21:50:52 2017 Thomas Lombard
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

static sfVector2i	**get_givrali_pos()
{
  sfVector2i		**ret;
  int			i;

  ret = calloc(4, sizeof(sfVector2i *));
  i = -1;
  while (++i < 3)
    if (!(ret[i] = calloc(2, sizeof(sfVector2i))))
      return (NULL);
  ret[0][0] = (sfVector2i){216, 229};
  ret[0][1] = (sfVector2i){22, 24};
  ret[1][0] = (sfVector2i){240, 229};
  ret[1][1] = (sfVector2i){23, 24};
  ret[2][0] = (sfVector2i){264, 229};
  ret[2][1] = (sfVector2i){19, 21};
  return (ret);
}

int	create_player_givrali(t_player *pkmn)
{
  if (!(pkmn->spr = sfSprite_create()))
    return (1);
  if (!(pkmn->tex = sfTexture_createFromFile(POKEMON2_FILE, NULL)))
    return (1);
  sfSprite_setTexture(pkmn->spr, pkmn->tex, sfTrue);
  sfSprite_setPosition(pkmn->spr, (sfVector2f){250, 975});
  sfSprite_setScale(pkmn->spr, (sfVector2f){3, 3});
  pkmn->nb = 1;
  pkmn->n_sprt = 2;
  pkmn->step = 0;
  pkmn->steps = 4;
  if (!(pkmn->pos = get_givrali_pos()))
    return (1);
  return (0);
}
