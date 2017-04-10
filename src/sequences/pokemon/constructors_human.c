/*
** constructors_human.c for repo in /src/sequences/pokemon
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Apr 02 19:26:02 2017 Thomas Lombard
** Last update Sun Apr 02 20:55:41 2017 Thomas Lombard
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

static sfVector2i	**get_man_pos()
{
  sfVector2i		**ret;
  int			i;

  ret = calloc(7, sizeof(sfVector2i *));
  i = -1;
  while (++i < 6)
    if (!(ret[i] = calloc(2, sizeof(sfVector2i))))
      return (NULL);
  ret[0][0] = (sfVector2i){6, 60};
  ret[0][1] = (sfVector2i){31, 54};
  ret[1][0] = (sfVector2i){38, 60};
  ret[1][1] = (sfVector2i){43, 54};
  ret[2][0] = (sfVector2i){83, 60};
  ret[2][1] = (sfVector2i){38, 54};
  ret[3][0] = (sfVector2i){122, 60};
  ret[3][1] = (sfVector2i){33, 54};
  ret[4][0] = (sfVector2i){156, 60};
  ret[4][1] = (sfVector2i){46, 54};
  ret[5][0] = (sfVector2i){203, 60};
  ret[5][1] = (sfVector2i){38, 54};
  return (ret);
}

static sfVector2i	**get_woman_pos()
{
  sfVector2i		**ret;
  int			i;

  if (!(ret = calloc(7, sizeof(sfVector2i *))))
    return (NULL);
  i = -1;
  while (++i < 6)
    if (!(ret[i] = calloc(2, sizeof(sfVector2i))))
      return (NULL);
  ret[0][0] = (sfVector2i){3, 4};
  ret[0][1] = (sfVector2i){31, 52};
  ret[1][0] = (sfVector2i){36, 4};
  ret[1][1] = (sfVector2i){39, 52};
  ret[2][0] = (sfVector2i){77, 4};
  ret[2][1] = (sfVector2i){35, 52};
  ret[3][0] = (sfVector2i){114, 4};
  ret[3][1] = (sfVector2i){31, 52};
  ret[4][0] = (sfVector2i){147, 4};
  ret[4][1] = (sfVector2i){39, 52};
  ret[5][0] = (sfVector2i){188, 4};
  ret[5][1] = (sfVector2i){34, 52};
  return (ret);
}

int	create_player_woman(t_player *woman)
{
  if (!(woman->spr = sfSprite_create()))
    return (1);
  if (!(woman->tex = sfTexture_createFromFile(PLAYER_FILE, NULL)))
    return (1);
  sfSprite_setTexture(woman->spr, woman->tex, sfTrue);
  sfSprite_setPosition(woman->spr, (sfVector2f){SCREEN_WIDTH / 2 - 200, 850});
  sfSprite_setScale(woman->spr, (sfVector2f){2.7, 2.7});
  woman->nb = 0;
  woman->n_sprt = 5;
  woman->step = 0;
  woman->steps = 4;
  woman->pos = get_woman_pos();
  return (0);
}

int	create_player_man(t_player *man)
{
  if (!(man->spr = sfSprite_create()))
    return (1);
  if (!(man->tex = sfTexture_createFromFile(PLAYER_FILE, NULL)))
    return (1);
  sfSprite_setTexture(man->spr, man->tex, sfTrue);
  sfSprite_setPosition(man->spr, (sfVector2f){SCREEN_WIDTH / 2 - 100, 875});
  sfSprite_setScale(man->spr, (sfVector2f){3, 3});
  man->nb = 0;
  man->n_sprt = 5;
  man->step = 3;
  man->steps = 5;
  man->pos = get_man_pos();
  return (0);
}
