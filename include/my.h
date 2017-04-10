/*
** my.h for myh in /home/sachs_a/delivery/c_graphical
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Mon Feb 13 18:50:57 2017 Alexandre Sachs
** Last update Sun Apr 02 22:31:36 2017 Thomas Lombard
*/

#ifndef MY_H_
# define MY_H_

# include <linux/limits.h>
# include <SFML/Audio.h>
# include <SFML/Graphics.h>

# define UNUSED __attribute__((unused))
# define NEXT(ptr) (ptr = (ptr && ptr->next) ? ptr->next : ptr)

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define POKEMON_SONG "fonts/music/pokemon.ogg"
# define MANIAC_SONG  "fonts/music/Maniac.ogg"
# define STARS_SONG   "fonts/music/Stars.ogg"
# define KARTON_SONG   "fonts/music/Karton.ogg"

# define DEFAULT_MASK "fonts/picture/mask_wallpaper.jpg"
# define PLAYER_FILE  "fonts/picture/running.png"
# define POKEMON1_FILE "fonts/picture/pokemon1.png"
# define POKEMON2_FILE "fonts/picture/pokemon2.png"
# define NB_PLAYER    5

# define L_IMG	(1 << 0)
# define L_TEX	(1 << 1)
# define L_SPR	(1 << 2)

typedef struct		s_my_framebuffer
{
  sfUint8               *pixels;
  unsigned int          width;
  unsigned int          height;
}			t_my_framebuffer;

typedef struct          s_window
{
  sfRenderWindow        *window;
  sfTexture             *texture;
  sfSprite              *sprite;
  sfEvent               event;
  sfColor               color;
}                       t_window;

typedef struct		s_sprite
{
  sfSprite		*spr;
  sfTexture		*tex;
  sfImage		*img;
}			t_sprite;

typedef struct		s_slide
{
  struct s_slide	*next;
  struct s_slide	*prev;
  sfVector2f		pos;
  sfBool		repeat;
  sfBool		scale;
  sfSprite		*sprite;
}			t_slide;

typedef struct		s_player
{
  sfSprite		*spr;
  sfTexture		*tex;
  sfVector2i		**pos;
  int			nb;
  int			n_sprt;
  int			step;
  int			steps;
}			t_player;

/*
** Generic chained list
*/
typedef struct		s_list
{
  struct s_list		*next;
  struct s_list		*prev;
  char			data[0];
}			t_list;

typedef struct		s_sound
{
  struct s_sound	*next;
  struct s_sound	*prev;
  sfMusic		*music;
  char			path[PATH_MAX + 1];
}			t_sound;

/*
** BASICS
*/
int			main(int, char **);
void			*push_list(void *, void *, size_t);
int			my_event(t_window *);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
int			free_point(sfTexture *, sfSprite *);

/*
** INIT_WINDOW
*/
void			my_window_update(t_my_framebuffer *, t_window *);
t_my_framebuffer	*my_framebuffer_create(int, int);
sfRenderWindow		*create_window(char *, int, int);
t_my_framebuffer	set_window(t_my_framebuffer *, t_window *);
int			my_init_window(t_window *);
int			clear_buffer(t_my_framebuffer *);
int			init_sprite_list(t_slide **);
sfSprite		*sprite_from_file(char*, int, int, t_slide*);

/*
** SQUARE
*/
int			draw_square(t_my_framebuffer *, int, int, sfColor);

/*
** SOUND
*/
t_sound			*init_sound();
void			destruct_sound(t_sound *);

/*
** MASK
*/
int	construct(sfVector2f *, sfVector2i *, t_sprite *, t_sprite *);
int	construct_sprite(t_sprite *, int);
void	opposite(t_sprite *);

/*
** PLAYER
*/
void	destruct_player(t_player player[NB_PLAYER]);
int	init_player(t_player player[NB_PLAYER]);
void	draw_player(sfRenderWindow *, t_player player[NB_PLAYER]);
int	create_player_man(t_player *);
int	create_player_woman(t_player *);
int	create_player_goupix(t_player *goupix);
int	create_player_riolu(t_player *lixy);
int	create_player_givrali(t_player *pkmn);

#endif /* !MY_H_ */
