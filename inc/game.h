#ifndef GAME_H
# define GAME_H
# include "map.h"
# include "colors.h"
# include "../libft/inc/libft.h"
# include <mlx.h>
# include <stdio.h>
# define SIZE 32
# define COLORS "RBKOGYP"
enum e_direction
{
	ST = 0,
	N = 1,
	S = -1,
	E = 2,
	W = -2
};
typedef struct s_font
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	void	*black;
}				t_font;
typedef struct s_pl_sprite
{
	t_list	*up;
	t_list	*up_bak;
	t_list	*down;
	t_list	*down_bak;
	t_list	*left;
	t_list	*left_bak;
	t_list	*right;
	t_list	*right_bak;
	t_list	*panic;
	t_list	*panic_bak;
}				t_pl_sprite;
typedef struct s_sprite
{
	void		*logo;
	void		**wall;
	void		*pacfood;
	void		*portal;
	void		*pacman;
	void		*pixels;
	void		*black;
	t_list		*pac_dying_bak;
	t_list		*pac_dying;
	t_font		score_font;
}				t_sprite;
typedef struct s_legal_actions
{
	int	north;
	int	south;
	int	east;
	int	west;
}				t_legal_actions;
typedef struct s_player
{
	t_vector		pos;
	t_vector		win_pos;
	int				dir;
	int				moving;
	t_pl_sprite		sprites;
	t_legal_actions	legal;
	struct s_player	*next;
}				t_player;
typedef struct s_game
{
	int			width;
	int			height;
	void		*id;
	void		*w_id;
	t_lay		*lay;
	t_lay		lay_bak;
	t_sprite	sprites;
	t_player	*pl;
	t_player	*gh;
	int			next_dir;
	char		**map;
	char		**map_bak;
	int			n_collect_bak;
	int			pac_dying;
	int			panic_mode;
	int			n_frames;
	int			n_moves;
	int			redraw;
	int			g_rate;
}				t_game;
void		init_game(char **map, t_lay lay);
void		ft_newgame(t_game *g, char **m, t_lay *lay);
int			end_game(t_game *g);
int			ft_update(t_game *g);
int			key_hook(int keycode, t_game *g);
t_sprite	ft_initsprites(t_game *g);
int			free_sprites(t_game *g);
void		ft_check_game(t_game *g);
void		ft_newdirection(t_game *g, int direction);
t_player	*ft_plrnew(t_vector pos);
void		ft_plradd_back(t_player **lst, t_player *newnode);
void		ft_playerlist(char **map, t_game *g);
void		ft_free_playerlist(t_game *g);
int			ft_deletefirst_plr(t_game *g);
int			ft_deletelast_plr(t_game *g);
int			ft_delete_player(t_game *g, t_vector old);
void		ft_print_plrs(t_game *g);
void		ft_move(int d, t_game *g, t_player *temp);
int			ft_swap_tile(t_vector old, t_vector nw, t_game *g);
void		ft_redraw_pac(t_game *g);
void		ft_redraw_gh(t_game *g);
void		ft_redraw_pacfood(t_game *g, t_player *pl);
void		ft_redraw_exit(t_game *g, t_player *pl);
void		ft_put_map(t_game *g, int x, int y);
void		ft_put_ghosts(t_game *g);
void		ft_put_pacman(t_game *g);
void		ft_put_font(t_game *g, int digit, int i);
void		ft_anim_pacdeath(t_game *g);
t_list		*ft_load_pacdeath(t_game *g);
t_font		ft_load_score_font(t_game *g);
t_list		*ft_chooseghcolor(t_game *g, int i, int dir);
void		ft_load_ghosts(t_game *g);
void		ft_load_pacmans(t_game *g);
void		free_animation(t_game *g, t_list *start);
void		free_players(t_game *g);
void		ft_free_singlepl(t_game *g, t_player *pl);
void		free_fonts(t_game *g);
void		ft_update_score(t_game *g);
int			ft_checkmvtogh(t_game *g, int d, t_player *pl);
t_player	*ft_getnearestpac(t_game *g, t_player *ghost);
void		ft_update_ghosts(t_game *g);
int			ft_findghost(t_player *pl, t_vector pos);
void		ft_move_ghost(int d, t_game *g, t_player *ghost);
int			ft_choose_dir(t_game *g, t_player *gh, t_player *pac);
int			ft_advanced_dir(t_player *gh, t_player *pac, int *distances);
int			ft_advanced_dir2(int *distances);
void		ft_update_legal(t_game *g, t_player *gh);
void		ft_restrict_legal(t_player *ghost);
int			ft_legal_len(t_player *player);
int			ft_reset(t_game *g);
int			ft_in_legal(t_player *player, int dir);
void		ft_next_dir(t_game *g);
t_list		*ft_load_north(t_game *g, char *path, int i);
t_list		*ft_load_south(t_game *g, char *path, int i);
t_list		*ft_load_east(t_game *g, char *path, int i);
t_list		*ft_load_west(t_game *g, char *path, int i);
t_list		*ft_load_panic(t_game *g, int i);
void		ft_anim_north(t_game *g, t_player *pl);
void		ft_anim_south(t_game *g, t_player *pl);
void		ft_anim_east(t_game *g, t_player *pl);
void		ft_anim_west(t_game *g, t_player *pl);
void		ft_anim_panic(t_game *g, t_player *pl);
void		ft_put_stopped(t_game *g, t_player *pl);
#endif