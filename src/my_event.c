/*
** my_event.c for my_event in /home/sachs_a/delivery/c_graphical_programming/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Sat Apr  1 18:33:22 2017 Alexandre Sachs
** Last update Jan Apr 2 22:44:40 2017
*/

#include "my.h"

int		my_event(t_window *my_window)
{
  sfEvent	event;

  while (sfRenderWindow_pollEvent(my_window->window, &event))
    {
      if ((event.type == sfEvtClosed) ||
	  (sfKeyboard_isKeyPressed(sfKeyEscape)))
	{
	  sfRenderWindow_close(my_window->window);
	  return (0);
	}
    }
  return (1);
}
