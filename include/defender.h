/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "time.h"

#ifndef MY_PI
#define MY_PI (3.14159265358979323846)
#endif

typedef struct game {
    sfRenderWindow *window;
    sfShader *shader;
    sfRenderStates state;
    sfEvent event;
    int scene;
    sfFont *font;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfColor clear_color;
    int pause;
    int mob_nb;
} game_t;

typedef struct menu {
    sfSprite *sp_background;
    sfTexture *tx_background;
    sfMusic *main_theme;
} menu_t;

typedef struct targetting {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f text_pos;
    int big;
    int show;
    sfText *str;
    sfFont *font;
    struct targetting *next;
    struct targetting *back;
} targetting_t;

typedef struct list_targetting {
    int length;
    int size;
    sfClock *clock;
    sfTime time;
    float seconds;
    targetting_t *begin;
    targetting_t *end;
} list_targetting_t;

typedef struct spawning {
    sfClock *clock;
    sfTime time;
    float seconds;
    sfClock *clock2;
    sfTime time2;
    float seconds2;
} spawning_t;

typedef struct tuto {
    sfSprite *sprite;
    sfClock *clock;
    sfTime time;
    sfTexture *texture;
    sfVector2f pos, scale;
    sfSprite *snow;
    sfTexture *snow_text;
    char previous;
    int state, life, id, direction, nb;
    sfRectangleShape *life_bar;
    sfRectangleShape *black;
    float seconds, move, increment, speed, save_speed, slow;
    int map_pos, castle, check;
    struct tuto *next;
} tuto_t;

typedef struct support {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite_base;
    sfTexture *texture_base;
    sfVector2f base_pos;
    sfVector2f pos;
    char type;
    int on;
    struct support *next;
} support_t;

typedef struct t_select {
    sfSprite *sprite;
    sfSprite *sprite_a;
    sfTexture *texture;
    sfTexture *texture_a;
    sfVector2f pos, scale;
    sfText *text;
    int type, price;
    int clicked;
    struct t_select *next;
} t_select_t;

typedef struct player {
    sfSprite *sprite_h;
    sfSprite *sprite_m;
    sfTexture *texture_h;
    sfTexture *texture_m;
    sfText *txt_money;
    sfText *txt_life;
    char *strmoney;
    char *strlife;
    int money;
    int life;
} player_t;

typedef struct turret {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *sprite_b;
    sfSprite *zone;
    sfTexture *zone_txt;
    sfTexture *texture_b;
    sfSprite *sprite_c;
    sfTexture *texture_c;
    sfSprite *bullet;
    sfTexture *text_bullet;
    sfVector2f pos;
    sfVector2f pos_c;
    sfVector2f pos_bullet;
    tuto_t *locked;
    list_targetting_t *target;
    sfClock *clock;
    sfTime time;
    sfText *r_speed_txt;
    sfText *name;
    sfText *range_txt;
    sfText *rof_txt;
    sfText *dmg_txt;
    sfText *sell_txt;
    sfText *b_speed_txt;
    char *r_speed_str, *rof_str, *dmg_str, *b_speed_str, *range_str;
    char *strsell;
    float seconds;
    int type, mode, level, xp, dmg, sell;
    int range, shoot, hit, draw_stat;
    float rotate, r_speed, bullet_speed, rate_fire;
    sfVector2f pos_c2;
    struct turret *next;
} turret_t;

typedef struct selected {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *clicked;
    sfSprite *clicked_s;
    sfVector2f pos;
    sfVector2f pos2;
    support_t *sel;
    turret_t *tur;
    char type;
    int on, click;
} selected_t;

typedef struct selected2 {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *clicked;
    sfSprite *clicked_s;
    sfVector2f pos;
    sfVector2f pos2;
    int type;
    int on, click;
    t_select_t *zone;
} selected2_t;

typedef struct map {
    char *map;
    int spawner;
    int castle;
    sfVector2f castle_pos;
    sfVector2f spawner_pos;
    struct support *s_support;
} map_t;

typedef struct utils {
    int id;
    sfVector2f pos;
} utils_t;

typedef struct settings {
    int fps;
} settings_t;

typedef struct waves {
    int round, square, triangle;
    sfClock *clock;
    sfTime time;
    float seconds;
    struct waves *next;
} waves_t;

typedef struct sell {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *clicked;
    sfVector2f pos;
    int clic;
} sell_t;

typedef struct info_text {
    sfText *ground_txt;
    sfText *spawner_txt;
    sfText *castle_txt;
    sfText *title_g;
    sfText *title_s;
    sfText *title_c;
    sfVector2f pos_title;
    sfVector2f pos_txt;
} info_text_t;

typedef struct wave_controll {
    sfClock *clock;
    sfTime time;
    float seconds;
    int nb_waves, go, start;
    int playing, min;
    char *strwave, *base;
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    sfText *text2;
    struct waves *head;
    struct waves *temp;
    struct tuto *round;
    struct tuto *square;
    struct tuto *triangle;
} wave_controll_t;

typedef struct hard_buttons {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture2;
    sfVector2f pos;
} hard_buttons_t;

typedef struct hard_arrow {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture2;
    sfTexture *texture3;
    sfTexture *texture4;
    sfVector2f pos;
    int stat;
} hard_arrow_t;

typedef struct node_buttons {
    int who;
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture2;
    sfVector2f pos;
    struct node_buttons *next;
} node_buttons_t;

typedef struct list_buttons {
    int length;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfSprite *black;
    sfTexture *text_black;
    sfColor color;
    node_buttons_t *begin;
    node_buttons_t *end;
} list_buttons_t;

typedef struct side_menu {
    sfSprite *sprite;
    sfTexture *texture2;
    sfTexture *texture;
    sfTexture *texture3;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f pos;
    int slide;
    int draw;
} side_menu_t;

typedef struct buttons_tab {
    char *tab[12];
    char *tab2[12];
    char *tab_f[4];
    sfVector2f *tab_v[4];
} buttons_tab_t;

typedef struct all {
    map_t s_map;
    game_t s_game;
    menu_t s_menu;
    utils_t s_utils;
    player_t s_player;
    spawning_t s_spawning;
    side_menu_t s_side_menu;
    selected_t s_selected;
    info_text_t s_info_text;
    sell_t s_sell;
    hard_buttons_t s_hard_buttons;
    hard_buttons_t s_hard_buttons2;
    hard_arrow_t s_hard_arrow;
    settings_t s_settings;
    buttons_tab_t s_buttons_tab;
    selected2_t s_selected2;
    wave_controll_t s_wave_c;
    tuto_t *s_tuto;
    t_select_t *s_t_select;
    list_buttons_t *s_buttons;
    list_targetting_t *s_targetting;
    turret_t *s_turret;
} all_t;

int message(void);
void init_map(all_t *s_all);
void display_map(all_t *s_all);
int game_loop(all_t *s_all);
void event_controll(all_t *s_all);
void display(all_t *s_all);
void init_all(all_t *s_all);
void generate_round_mobs(all_t *s_all);
void generate_waves(all_t *s_all);
void init_menu(all_t *s_all);
void setup(all_t *all);
void display_menu(all_t *s_all);
void display_round_mobs(all_t *s_all);
void clock_round(all_t *s_all);
void check_destroy_ball(all_t *s_all, int id);
void list_menu_buttons(all_t *s_all);
void display_menu_buttons(all_t *s_all);
void destroy_music(all_t *s_all);
void destroy_regroup(all_t *s_all);
void init_selected(all_t *s_all);
void display_annex(all_t *s_all, tuto_t *temp);
void check_support_hitbox(all_t *s_all);
void init_player_infos(all_t *s_all);
void display_player_info(all_t *s_all);
void menu_press_buttons(all_t *s_all);
void display_info_texts(all_t *s_all);
void init_info_texts(all_t *s_all);
void menu_release_buttons(all_t *s_all);
void init_sell_button(all_t *s_all);
void display_sell_button(all_t *s_all);
void init_sell_button(all_t *s_all);
void init_count_wave_button(all_t *s_all);
void set_txt_sizes(turret_t *new);
void display_count_wave_button(all_t *s_all);
void menu_buttons_hitbox(node_buttons_t *tmp, all_t *s_all);
void init_pause_button(all_t *s_all);
void hitbox_pause_button(all_t *s_all);
void display_pause_button(all_t *s_all);
void release_pause_button(all_t *s_all);
void display_clicked(all_t *s_all);
void click_support(all_t *s_all);
void init_side_menu(all_t *s_all);
void display_side_menu(all_t *s_all, list_targetting_t *s_targetting);
void button_tab_init(char **tab);
void button_tab2_init(char **tab2);
void black_init(all_t *s_all);
int check_sell_hitbox(all_t *s_all);
void click_sell_button(all_t *s_all);
sfVector2f get_spawner_position(all_t *s_all);
sfVector2f get_castle_position(all_t *s_all);
void check_path(all_t *s_all, tuto_t *s_balls);
void move_up(tuto_t *s_balls, int len, all_t *s_all);
void move_down(tuto_t *s_balls, int len, all_t *s_all);
void move_left(tuto_t *s_balls, all_t *s_all);
void move_right(tuto_t *s_balls, all_t *s_all);
int my_if(tuto_t *temp);
void check_path(all_t *s_all, tuto_t *s_balls);
void display_selected_turret(all_t *s_all);
void generate_selected_turret(all_t *s_all);
void init_selected_turret(all_t *s_all);
int check_selected_turret(all_t *s_all, t_select_t *s_turret);
void list_targetting(all_t *s_all);
void display_targetting_buttons(all_t *s_all, list_targetting_t *s_targetting);
void hitbox_change_targetting_next(all_t *s_all);
void hitbox_change_targetting_back(all_t *s_all);
void keep_centered_targetting(list_targetting_t *s_targetting);
void slider_on1(all_t *s_all, list_targetting_t *s_targetting);
void slider_off1(all_t *s_all, list_targetting_t *s_targetting);
void set_show_targetting(list_targetting_t *s_targetting);
void display_slider_arrow(all_t *s_all);
void init_slider_arrow(all_t *s_all);
void hitbox_slider_arrow(all_t *s_all);
void release_slider_arrow(all_t *s_all);
void slider_on(all_t *s_all, list_targetting_t *s_targetting);
void slider_off(all_t *s_all, list_targetting_t *s_targetting);
int my_brick(all_t *s_all);
int check_side_menu(all_t *s_all);
void rotate_turret_maths(all_t *s_all);
int check_pause_button(all_t *s_all);
void turret_shoot(turret_t *tmp, float dif_angle, all_t *s_all);
void find_pos_closest(all_t *s_all, turret_t *turret);
void get_money_by_mobs(all_t *s_all);
void move_mob(tuto_t *mob, sfVector2f scl);
void init_wave_button(all_t *s_all);
void hitbox_wave_button(all_t *s_all);
void release_wave_button(all_t *s_all);
void get_turret_zone(all_t *s_all, t_select_t *temp);
void display_wave_button(all_t *s_all);
tuto_t *destroy_mob_head(tuto_t *s_tuto, tuto_t *temp3, all_t *s_all);
int mob_destroy_animation(tuto_t *s_tuto);
void get_random_position(tuto_t *new);
void restart_tuto_clocks(all_t *s_all);
int calcul_magnitude(tuto_t *tmp, turret_t *turret);
void losing_life(all_t *s_all);
int check_in_range(turret_t *turret, tuto_t *locked);
void lock_target_in_range(turret_t *turret, tuto_t *locked);
void find_pos_last(all_t *s_all, turret_t *turret);
void find_pos_first(all_t *s_all, turret_t *turret);
void find_pos_weak(all_t *s_all, turret_t *tmp);
void find_pos_strong(all_t *s_all, turret_t *turret);
void targetting_selector(all_t *s_all, turret_t *tmp);
void turret_list_targetting(turret_t *tmp, all_t *s_all);
list_targetting_t *push_back_turret_targetting(turret_t *tmp,
    int x, char *tab, int big);
void update_wave_button(all_t *s_all);
targetting_t *new_node_turret_targetting(int x, char *tab, int i);
int is_empty_list_targetting(list_targetting_t *li);
void display_turret_target(all_t *s_all);
void hitbox_change_targetting_next_turret(all_t *s_all,
    list_targetting_t *s_targetting);
void hitbox_change_targetting_back_turret(all_t *s_all,
    list_targetting_t *s_targetting);
void slow_mobs_in_range(turret_t *turret, all_t *s_all);
list_targetting_t *clear_list_target(list_targetting_t *li);
list_targetting_t *pop_front_targetting(list_targetting_t *li);

int check_selected(all_t *s_all, support_t *s_support);
list_buttons_t *new_list_buttons(void);
int is_empty_list_buttons(list_buttons_t *li);
node_buttons_t *new_node_buttons(all_t *s_all, int y, int who, int i);
list_buttons_t *push_back_buttons(all_t *s_all, int y, int who, int i);
list_buttons_t *pop_front_buttons(list_buttons_t *li);
list_buttons_t *clear_list(list_buttons_t *li);
targetting_t *new_node_targetting(int x, char *tab, int i);
list_targetting_t *push_back_targetting(all_t *s_all, int x, char *tab);
void general_game_clock(all_t *s_all);
void check_selected_turret_hitbox(all_t *s_all);
int check_selected_turret(all_t *s_all, t_select_t *s_turret);
void click_selected_turret(all_t *s_all);
void display_clicked_turret(all_t *s_all);
void display_turret(all_t *s_all);
void place_turret(all_t *s_all);
void load_turret(turret_t *new, sfVector2f pos);
void get_turret_type(turret_t *new, all_t *s_all);
void display_turret_stats(all_t *s_all);
void slider_off3(all_t *s_all);

void display_support(all_t *s_all);
support_t *fill_support(support_t *s_support, sfVector2f pos,
                        char *filepath, char type);
turret_t *fill_turret(turret_t *old, sfVector2f pos, int id, all_t *s_all);
turret_t *get_turret(all_t *s_all);
void release_sell_button(all_t *s_all);
void slider_on3(all_t *s_all);

void display_triangle(all_t *s_all);
void display_square(all_t *s_all);
void display_mobs(all_t *s_all);
void display_round(all_t *s_all);
void push_rand_rounds(all_t *s_all);
void push_rand_square(all_t *s_all);
void push_rand_triangle(all_t *s_all);
tuto_t *fill_mobs(tuto_t *s_tuto, all_t *s_all, char *filepath, int id);
tuto_t *destroy_part1(all_t *s_all, tuto_t *temp2, tuto_t *temp3,
                        tuto_t *temp);
void destroy_part2(all_t *s_all, int id, tuto_t *temp);
tuto_t *destroy_part3(all_t *s_all, tuto_t *temp3, tuto_t *temp);
void free_node2(all_t *s_all, tuto_t *temp, int id);
tuto_t *free_node(tuto_t *s_tuto, tuto_t *prev, tuto_t *temp3, all_t *s_all);

#endif /* !DEFENDER_H_ */
