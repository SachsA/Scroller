/*
** sprite_list.c for Scroller in /home/invicta/scroller/src/sequences/pokemon/
**
** Made by Kellian CIPIERRE
** Login   <kellian.cipierre@epitech.eu>
**
** Started on  Sat Apr  1 18:23:26 2017 Kellian CIPIERRE
** Last update Jan Apr 2 22:25:20 2017
*/

#include "my.h"

int		init_sprite_background(t_slide **images)
{
  t_slide	*cursor;

  if (!(*images = push_list(NULL, &cursor, sizeof(t_slide))))
    return (0);
  cursor->repeat = sfFalse;
  cursor->scale = sfFalse;
  cursor->sprite = sprite_from_file("fonts/picture/luna.png",
				    212, 212, cursor);
  cursor->pos = (sfVector2f){200, 10};
  if (!push_list(*images, &cursor, sizeof(t_slide)))
    return (0);
  cursor->repeat = sfTrue;
  cursor->scale = sfTrue;
  cursor->sprite = sprite_from_file("fonts/picture/nuages1.png",
				    1920, 160, cursor);
  cursor->pos = (sfVector2f){0, 200};
  if (!push_list(*images, &cursor, sizeof(t_slide)))
    return (0);
  cursor->repeat = sfTrue;
  cursor->scale = sfTrue;
  cursor->sprite = sprite_from_file("fonts/picture/montagnes.png",
				    1920, 292, cursor);
  cursor->pos = (sfVector2f){0, 530};
  return (1);
}

int		init_sprite_middleground(t_slide **images)
{
  t_slide	*cursor;

  if (!push_list(*images, &cursor, sizeof(t_slide)))
    return (0);
  cursor->repeat = sfTrue;
  cursor->scale = sfFalse;
  cursor->sprite = sprite_from_file("fonts/picture/herbe0.png",
				    1280, 8, cursor);
  cursor->pos = (sfVector2f){0, 960};
  if (!push_list(*images, &cursor, sizeof(t_slide)))
    return (0);
  cursor->repeat = sfTrue;
  cursor->scale = sfFalse;
  cursor->sprite = sprite_from_file("fonts/picture/herbe1.png",
				    1280, 12, cursor);
  cursor->pos = (sfVector2f){0, 968};
  if (!push_list(*images, &cursor, sizeof(t_slide)))
    return (0);
  cursor->repeat = sfTrue;
  cursor->scale = sfFalse;
  cursor->sprite = sprite_from_file("fonts/picture/grass4.png",
				    1280, 50, cursor);
  cursor->pos = (sfVector2f){0, 968};
  return (1);
}

int		init_sprite_middleground2(t_slide **images)
{
  t_slide	*cursor;

  if (!push_list(*images, &cursor, sizeof(t_slide)))
    return (0);
  cursor->repeat = sfTrue;
  cursor->scale = sfFalse;
  cursor->sprite = sprite_from_file("fonts/picture/herbe2.png",
				    1280, 28, cursor);
  cursor->pos = (sfVector2f){0, 980};
  if (!push_list(*images, &cursor, sizeof(t_slide)))
    return (0);
  cursor->repeat = sfTrue;
  cursor->scale = sfFalse;
  cursor->sprite = sprite_from_file("fonts/picture/grass4.png",
				    1280, 50, cursor);
  cursor->pos = (sfVector2f){0, 980};
  return (1);
}

int		init_sprite_foreground(t_slide **images)
{
  t_slide	*cursor;

  if (!push_list(*images, &cursor, sizeof(t_slide)))
    return (0);
  cursor->repeat = sfTrue;
  cursor->scale = sfFalse;
  cursor->sprite = sprite_from_file("fonts/picture/herbe3.png",
				   1280, 28, cursor);
  cursor->pos = (sfVector2f){0, 1008};
  if (!push_list(*images, &cursor, sizeof(t_slide)))
    return (0);
  cursor->repeat = sfTrue;
  cursor->scale = sfFalse;
  cursor->sprite = sprite_from_file("fonts/picture/herbe4.png",
				   1280, 44, cursor);
  cursor->pos = (sfVector2f){0, 1036};
  return (1);
}

int		init_sprite_list(t_slide **images)
{
  if (!init_sprite_background(images))
    return (0);
  if (!init_sprite_middleground(images))
    return (0);
  if (!init_sprite_middleground2(images))
    return (0);
  if (!init_sprite_foreground(images))
    return (0);
  return (1);
}
