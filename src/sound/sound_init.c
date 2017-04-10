/*
** sound_init.c for repo in /repo/src/sound
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat Apr 01 11:26:13 2017 Thomas Lombard
** Last update Jan Apr 2 22:43:20 2017
*/

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

void		destruct_sound(t_sound *sound_cloud)
{
  t_sound	*ptr;

  while (sound_cloud)
    {
      ptr = sound_cloud;
      if (sound_cloud->music)
	{
	  sfMusic_stop(sound_cloud->music);
	  sfMusic_destroy(sound_cloud->music);
	}
      sound_cloud = sound_cloud->next;
      free(ptr);
    }
}

static void	print_load_status(t_sound *ret)
{
  int	i;

  i = -1;
  while (ret)
    {
      printf("[MUSIC_LOADER -> Sound[%2d]]: ", ++i);
      if (ret->music)
	printf("\033[32m%-40s... -> Successfully loaded\033[m\n", ret->path);
      else
	printf("\033[31m%-40s... -> Not loaded\033[m\n", ret->path);
      ret = ret->next;
    }
}

t_sound		*load_sound(t_sound *ret, const char *sound)
{
  t_sound	*node;

  if (!(ret = push_list(ret, (void **)&node, sizeof(t_sound))))
    return (NULL);
  strncpy(node->path, sound, PATH_MAX);
  if (!(node->music = sfMusic_createFromFile(node->path)))
    return (ret);
  sfMusic_setLoop(node->music, sfTrue);
  return (ret);
}

t_sound		*init_sound()
{
  t_sound	*ret;

  ret = NULL;
  if (!(ret = load_sound(ret, POKEMON_SONG)) ||
      !(ret = load_sound(ret, MANIAC_SONG)) ||
      !(ret = load_sound(ret, STARS_SONG)) ||
      !(ret = load_sound(ret, KARTON_SONG)))
    return (NULL);
  print_load_status(ret);
  return (ret);
}
