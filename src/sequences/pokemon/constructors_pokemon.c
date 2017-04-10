/*
** constructors_pokemon.c for repo in /src/sequences/pokemon
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Apr 02 20:35:24 2017 Thomas Lombard
** Last update Sun Apr 02 21:04:08 2017 Thomas Lombard
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

static sfVector2i	**get_riolu_pos()
{
  sfVector2i		**ret;
  int			i;

  ret = calloc(4, sizeof(sfVector2i *));
  i = -1;
  while (++i < 3)
    if (!(ret[i] = calloc(2, sizeof(sfVector2i))))
      return (NULL);
  ret[0][0] = (sfVector2i){3, 233};
  ret[0][1] = (sfVector2i){17, 21};
  ret[1][0] = (sfVector2i){25, 233};
  ret[1][1] = (sfVector2i){18, 21};
  ret[2][0] = (sfVector2i){49, 233};
  ret[2][1] = (sfVector2i){19, 21};
  return (ret);
}

static sfVector2i	**get_goupix_pos()
{
  sfVector2i		**ret;
  int			i;

  if (!(ret = calloc(4, sizeof(sfVector2i *))))
    return (NULL);
  i = -1;
  while (++i < 3)
    if (!(ret[i] = calloc(2, sizeof(sfVector2i))))
      return (NULL);
  ret[0][0] = (sfVector2i){72, 107};
  ret[0][1] = (sfVector2i){20, 19};
  ret[1][0] = (sfVector2i){96, 107};
  ret[1][1] = (sfVector2i){20, 19};
  ret[2][0] = (sfVector2i){121, 107};
  ret[2][1] = (sfVector2i){20, 19};
  return (ret);
}

int	create_player_goupix(t_player *goupix)
{
  if (!(goupix->spr = sfSprite_create()))
    return (1);
  if (!(goupix->tex = sfTexture_createFromFile(POKEMON1_FILE, NULL)))
    return (1);
  sfSprite_setTexture(goupix->spr, goupix->tex, sfTrue);
  sfSprite_setPosition(goupix->spr, (sfVector2f){SCREEN_WIDTH / 2 - 400, 950});
  sfSprite_setScale(goupix->spr, (sfVector2f){2, 2});
  goupix->nb = 1;
  goupix->n_sprt = 2;
  goupix->step = 0;
  goupix->steps = 4;
  goupix->pos = get_goupix_pos();
  return (0);
}

int	create_player_riolu(t_player *riolu)
{
  if (!(riolu->spr = sfSprite_create()))
    return (1);
  if (!(riolu->tex = sfTexture_createFromFile(POKEMON1_FILE, NULL)))
    return (1);
  sfSprite_setTexture(riolu->spr, riolu->tex, sfTrue);
  sfSprite_setPosition(riolu->spr, (sfVector2f){SCREEN_WIDTH / 2 + 50, 1000});
  sfSprite_setScale(riolu->spr, (sfVector2f){2.7, 2.7});
  riolu->nb = 1;
  riolu->n_sprt = 2;
  riolu->step = 0;
  riolu->steps = 4;
  riolu->pos = get_riolu_pos();
  return (0);
}
