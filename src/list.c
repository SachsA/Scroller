/*
** list.c for repo in /scroller/repo/src
**
** Made by Thomas Lombard
** Login   <lombar_e@epitech.net>
**
** Started on  Sat Apr 01 16:17:07 2017 Thomas Lombard
** Last update Jul Apr 1 18:58:31 2017
*/

#include <stdlib.h>
#include "my.h"

void		*push_list(void		*a,
			   void		*n,
			   size_t	size)
{
  t_list	*act;
  t_list	**new;
  t_list	*ret;

  new = (t_list **)n;
  act = (t_list *)a;
  ret = (t_list *)act;
  while (act && act->next)
    act = act->next;
  if (!(*new = calloc(1, size)))
    return (NULL);
  if (!act)
    ret = *new;
  (act) ? act->next = *new : 0;
  if (act)
    (*new)->prev = act;
  return (ret);
}
