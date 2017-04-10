/*
** main.c for main in /home/sachs_a/delivery/c_graphical_programming/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Fri Mar 31 20:24:11 2017 Alexandre Sachs
** Last update Jan Apr 2 22:44:21 2017
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "fn_ptr.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

void			init_fnptr(t_fnptr *fn_tab, t_sound *sound_cloud)
{
  fn_tab[0].seq = "pokemon";
  fn_tab[0].p = &scroller;
  fn_tab[0].sound = sound_cloud->music;
  NEXT(sound_cloud);
  fn_tab[2].seq = "slider";
  fn_tab[2].p = &slider;
  fn_tab[2].sound = sound_cloud->music;
  NEXT(sound_cloud);
  NEXT(sound_cloud);
  fn_tab[4].seq = "stars";
  fn_tab[4].p = &shooting_stars;
  fn_tab[4].sound = sound_cloud->music;
  fn_tab[1].seq = "text";
  fn_tab[1].p = &text;
  fn_tab[1].sound = sound_cloud->music;
  fn_tab[3].seq = "mask";
  fn_tab[3].p = &mask;
  fn_tab[3].sound = sound_cloud->music;
  fn_tab[5].seq = "thick";
  fn_tab[5].p = &thick;
  fn_tab[5].sound = NULL;
}

int			exec_seq(t_my_framebuffer *framebuffer,
				 t_window *window, char *seq,
				 t_sound *sound_cloud)
{
  int			i;
  t_fnptr		fn_tab[NB_SEQ];

  init_fnptr(fn_tab, sound_cloud);
  i = 0;
  while (i < NB_SEQ && strcmp(fn_tab[i].seq, seq) != 0)
    i++;
  if (i == NB_SEQ)
    return (0);
  if (fn_tab[i].sound)
    sfMusic_play(fn_tab[i].sound);
  fn_tab[i].p(framebuffer, window);
  return (1);
}

int			main(int ac, char **av)
{
  t_window		my_window;
  t_my_framebuffer	framebuffer;
  t_sound		*sound_cloud;

  if (ac != 2)
    return (84);
  sound_cloud = init_sound();
  framebuffer = set_window(&framebuffer, &my_window);
  if (!exec_seq(&framebuffer, &my_window, av[1], sound_cloud))
    fprintf(stderr, "%s : mauvais parametre\n", av[1]);
  free(framebuffer.pixels);
  sfRenderWindow_destroy(my_window.window);
  destruct_sound(sound_cloud);
  return (0);
}
