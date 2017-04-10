/*
** text.h for texth in /home/sachs_a/delivery/c_graphical_programming/scroller
** 
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
** 
** Started on  Sat Apr  1 15:28:10 2017 Alexandre Sachs
** Last update Sun Apr  2 14:02:11 2017 Alexandre Sachs
*/

#ifndef TEXT_H_
# define TEXT_H_

typedef struct		s_letter
{
  int			x;
  int			y;
  char			letter;
}			t_letter;

typedef struct		s_text
{
  sfRenderWindow	*win;
  sfSprite		*font;
  sfVector2f		pos;
}			t_text;

int			print_text2(int, t_text, char *, sfVector2f);
sfVector2f		move_forward(sfVector2f, float, float);
int			text(t_my_framebuffer *, t_window *);
int			print_text(int, t_text, char *);

#endif /* !TEXT_H_ */
