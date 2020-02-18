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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "time.h"

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    int scene;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfColor clear_color;
    int pause;
} game_t;

typedef struct menu {
    sfSprite *sp_background;
    sfTexture *tx_background;
    sfMusic *main_theme;
} menu_t;

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
    sfVector2f pos;
    char previous;
    int speed, state, life;
    float seconds;
    int map_pos, increment;
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
    struct support *next;
} support_t;

typedef struct selected {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *clicked;
    sfSprite *clicked_s;
    sfVector2f pos;
    sfVector2f pos2;
    char type;
    int on;
} selected_t;

typedef struct map {
    char *map;
    int spawner;
    int castle;
    sfVector2f castle_pos;
    sfVector2f spawner_pos;
    struct support *s_support;
} map_t;

typedef struct settings {
    int fps;
} settings_t;

typedef struct hard_buttons {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture2;
    sfVector2f pos;
} hard_buttons_t;

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
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f pos;
    int slide;
} side_menu_t;

typedef struct buttons_tab {
        char *tab[12];
        char *tab2[12];
} buttons_tab_t;

typedef struct all {
    map_t s_map;
    game_t s_game;
    menu_t s_menu;
    spawning_t s_spawning;
    side_menu_t s_side_menu;
    selected_t s_selected;
    hard_buttons_t s_hard_buttons;
    settings_t s_settings;
    buttons_tab_t s_buttons_tab;
    tuto_t *s_tuto;
    list_buttons_t *s_buttons;
} all_t;

int message(void);
void init_map(all_t *s_all);
void display_map(all_t *s_all);
int game_loop(all_t *s_all);
void event_controll(all_t *s_all);
void display(all_t *s_all);
void init_all(all_t *s_all);
void generate_round_mobs(all_t *s_all);
void init_menu(all_t *s_all);
void setup(all_t *all);
void display_menu(all_t *s_all);
void display_round_mobs(all_t *s_all);
void clock_round(all_t *s_all);
void check_destroy_ball(all_t *s_all);
void list_menu_buttons(all_t *s_all);
void display_menu_buttons(all_t *s_all);
void destroy_music(all_t *s_all);
void destroy_regroup(all_t *s_all);
void init_selected(all_t *s_all);
void check_support_hitbox(all_t *s_all);
void menu_press_buttons(all_t *s_all);
void menu_release_buttons(all_t *s_all);
void menu_buttons_hitbox(node_buttons_t *tmp, all_t *s_all);
void init_pause_button(all_t *s_all);
void hitbox_pause_button(all_t *s_all);
void display_pause_button(all_t *s_all);
void release_pause_button(all_t *s_all);
void display_clicked(all_t *s_all);
void click_support(all_t *s_all);
void init_side_menu(all_t *s_all);
void display_side_menu(all_t *s_all);
void button_tab_init(char **tab);
void button_tab2_init(char **tab2);
void black_init(all_t *s_all);
sfVector2f get_spawner_position(all_t *s_all);
sfVector2f get_castle_position(all_t *s_all);
void check_path(all_t *s_all, tuto_t *s_balls);
void move_up(tuto_t *s_balls, int len, all_t *s_all);
void move_down(tuto_t *s_balls, int len, all_t *s_all);
void move_left(tuto_t *s_balls, all_t *s_all);
void move_right(tuto_t *s_balls, all_t *s_all);
void check_path(all_t *s_all, tuto_t *s_balls);

int check_selected(all_t *s_all, support_t *s_support);
list_buttons_t *new_list_buttons(void);
int is_empty_list_buttons(list_buttons_t *li);
node_buttons_t *new_node_buttons(all_t *s_all, int y, int who, int i);
list_buttons_t *push_back_buttons(all_t *s_all, int y, int who, int i);
list_buttons_t *pop_front_buttons(list_buttons_t *li);
list_buttons_t *clear_list(list_buttons_t *li);
void general_game_clock(all_t *s_all);

void display_support(all_t *s_all);
support_t *fill_support(support_t *s_support, sfVector2f pos,
                        char *filepath, char type);

#endif /* !DEFENDER_H_ */
