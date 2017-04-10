/*
** destruct_player.c for repo in /src/sequences/pokemon
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Apr 02 19:52:53 2017 Thomas Lombard
** Last update Sun Apr 02 22:14:35 2017 Thomas Lombard
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "my.h"

/*
** Karton text mask
*/

static void	destruct_pos(t_player *player)
{
  int		i;

  i = -1;
  while (player->pos[++i])
    free(player->pos[i]);
  free(player->pos);
}

void	destruct_player(UNUSED t_player player[NB_PLAYER])
{
  int	i;

  i = -1;
  while (++i < NB_PLAYER)
    {
      destruct_pos(&player[i]);
      sfTexture_destroy(player[i].tex);
      sfSprite_destroy(player[i].spr);
    }
  return ;
}
