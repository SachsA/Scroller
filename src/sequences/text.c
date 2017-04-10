/*
** text.c for text in /home/sachs_a/delivery/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sat Apr  1 13:42:54 2017 Alexandre Sachs
** Last update Jan Apr 2 22:42:37 2017
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "text.h"

static t_letter		gl_lettre[] =
  {
    {0, 0, ' '},
    {1, 0, '!'},
    {2, 0, '"'},
    {3, 0, 0},
    {4, 0, 0},
    {5, 0, '%'},
    {6, 0, 0},
    {7, 0, '\''},
    {8, 0, '('},
    {9, 0, ')'},
    {0, 1, 0},
    {1, 1, '+'},
    {2, 1, ','},
    {3, 1, '_'},
    {4, 1, '.'},
    {5, 1, '/'},
    {6, 1, '0'},
    {7, 1, '1'},
    {8, 1, '2'},
    {9, 1, '3'},
    {0, 2, '4'},
    {1, 2, '5'},
    {2, 2, '6'},
    {3, 2, '7'},
    {4, 2, '8'},
    {5, 2, '9'},
    {6, 2, ':'},
    {7, 2, ';'},
    {8, 2, 0},
    {9, 2, '='},
    {0, 3, 0},
    {1, 3, '?'},
    {2, 3, '`'},
    {3, 3, 'A'},
    {4, 3, 'B'},
    {5, 3, 'C'},
    {6, 3, 'D'},
    {7, 3, 'E'},
    {8, 3, 'F'},
    {9, 3, 'G'},
    {0, 4, 'H'},
    {1, 4, 'I'},
    {2, 4, 'J'},
    {3, 4, 'K'},
    {4, 4, 'L'},
    {5, 4, 'M'},
    {6, 4, 'N'},
    {7, 4, 'O'},
    {8, 4, 'P'},
    {9, 4, 'Q'},
    {0, 5, 'R'},
    {1, 5, 'S'},
    {2, 5, 'T'},
    {3, 5, 'U'},
    {4, 5, 'V'},
    {5, 5, 'W'},
    {6, 5, 'X'},
    {7, 5, 'Y'},
    {8, 5, 'Z'},
    {9, 5, 0},
    {0, 6, 0},
    {1, 6, 0},
    {2, 6, 0},
    {3, 6, '-'},
    {4, 6, -1},
  };

sfVector2f		move_forward(sfVector2f pos, float direction,
				     float distance)
{
  sfVector2f		pos_final;

  direction = (direction * M_PI)/180;
  pos_final.x = pos.x + (distance * cosf(direction));
  pos_final.y = pos.y + (distance * sinf(direction));
  return (pos_final);
}

int			print_text2(int rota, t_text text,
				    char *str, sfVector2f param)
{
  int			i;
  int			j;

  i = 0;
  sfSprite_setRotation(text.font, rota);
  while (str[i] != '\0')
    {
      j = 0;
      while (gl_lettre[j].letter != -1 && gl_lettre[j].letter != str[i])
	j++;
      if (gl_lettre[i].letter != -1)
	{
	  sfSprite_setTextureRect(text.font, (sfIntRect){gl_lettre[j].x * 32,
		gl_lettre[j].y * 24 + 4, 32, 24});
	  sfSprite_setPosition(text.font, text.pos);
	  sfSprite_setScale(text.font, (sfVector2f){1, param.y});
	  sfRenderWindow_drawSprite(text.win, text.font, NULL);
	}
      i++;
      text.pos = move_forward(text.pos, rota, 32);
    }
  return (0);
}

int			print_text(int rota, t_text text, char *str)
{
  int			i;
  int			j;

  i = 0;
  sfRenderWindow_clear(text.win, sfBlack);
  sfSprite_setRotation(text.font, rota);
  while (str[i] != '\0')
    {
      j = 0;
      while (gl_lettre[j].letter != -1 && gl_lettre[j].letter != str[i])
	j++;
      if (gl_lettre[i].letter != -1)
	{
	  sfSprite_setTextureRect(text.font, (sfIntRect){gl_lettre[j].x * 32,
		gl_lettre[j].y * 24 + 4, 32, 24});
	  sfSprite_setPosition(text.font, text.pos);
	  sfRenderWindow_drawSprite(text.win, text.font, NULL);
	}
      i++;
      text.pos = move_forward(text.pos, rota, 32);
    }
  return (0);
}

int			text(t_my_framebuffer *framebuffer,
			     t_window *my_window)
{
  sfVector2f		pos;
  sfVector2f		move;
  sfTexture		*image;
  sfSprite		*spriteim;
  int			rot;

  rot = 0;
  pos = (sfVector2f){50, 50};
  move = (sfVector2f){5, 3};
  if (!(image = sfTexture_createFromFile("fonts/font/font4.gif", NULL)))
    return (0);
  spriteim = sfSprite_create();
  sfSprite_setTexture(spriteim, image, sfTrue);
  while (sfRenderWindow_isOpen(my_window->window))
    {
      if (!my_event(my_window))
	return (0);
      print_text(rot, (t_text){my_window->window, spriteim, pos},
		 "LOVE KARTON");
      my_window_update(framebuffer, my_window);
      pos.x = (pos.x >= SCREEN_WIDTH) ? 0 : pos.x + move.x;
      pos.y = (pos.y >= SCREEN_HEIGHT) ? 0 : pos.y + move.y;
      rot = (rot == 360) ? 0 : rot + 1;
    }
  return (free_point(image, spriteim));
}
