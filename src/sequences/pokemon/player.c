/*
** player.c for repo in /src/sequences/pokemon
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sun Apr 02 17:32:13 2017 Thomas Lombard
** Last update Sun Apr 02 21:43:41 2017 Thomas Lombard
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my.h"

int	init_player(t_player player[NB_PLAYER])
{
  create_player_woman(&player[0]);
  create_player_man(&player[1]);
  create_player_goupix(&player[2]);
  create_player_riolu(&player[3]);
  create_player_givrali(&player[4]);
  return (0);
}

void			draw_player(sfRenderWindow *win,
				    t_player player[NB_PLAYER])
{
  sfIntRect		rect;
  int			i;

  i = -1;
  while (++i < NB_PLAYER)
    {
      ++player[i].step;
      if (player[i].step == player[i].steps)
	{
	  player[i].step = 0;
	  player[i].nb += ((player[i].nb == player[i].n_sprt)
			   ? -player[i].n_sprt : 1);
	}
        rect.top = player[i].pos[player[i].nb][0].y;
        rect.left = player[i].pos[player[i].nb][0].x;
        rect.height = player[i].pos[player[i].nb][1].y;
        rect.width = player[i].pos[player[i].nb][1].x;
        sfSprite_setTextureRect(player[i].spr, rect);
        sfRenderWindow_drawSprite(win, player[i].spr, NULL);
    }
}
