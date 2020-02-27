/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** render
*/

#include "defender.h"
#include "utils.h"

void setup(all_t *s_all)
{
    s_all->s_settings.fps = 60;
    sfVideoMode mode = {1920, 1080, 32};
    s_all->s_game.clock = sfClock_create();
    s_all->s_game.clear_color = sfColor_fromRGB(22, 24, 23);
    s_all->s_game.window = sfRenderWindow_create(mode, "MY_DEFENDER",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(s_all->s_game.window,
        s_all->s_settings.fps);
    sfRenderWindow_setPosition(s_all->s_game.window, (sfVector2i){0, 0});
    s_all->s_game.scene = 0, s_all->s_game.pause = 0;
    s_all->s_game.shader = sfShader_createFromFile(NULL, NULL, "utils/light");
    s_all->s_game.state.shader = s_all->s_game.shader;
    s_all->s_game.state.blendMode = sfBlendAdd;
    s_all->s_game.state.transform = sfTransform_Identity;
    s_all->s_game.state.texture = NULL;
    sfShader_setFloatUniform( s_all->s_game.shader, "screenHeight", 1030);
    sfShader_setVec3Uniform( s_all->s_game.shader, "lightAttenuation",
        (sfGlslVec3){0.25, 0.25, 0.25});
    sfShader_setVec3Uniform(s_all->s_game.shader, "lightColor",
        (sfGlslVec3){255, 50, 255});
}

void init_all2(all_t *s_all)
{
    s_all->s_wave_c.round = NULL;
    s_all->s_wave_c.square = NULL;
    s_all->s_wave_c.triangle = NULL;
    s_all->s_wave_c.clock = sfClock_create();
    s_all->s_wave_c.go = 0, s_all->s_wave_c.start = 0;
    s_all->s_selected.tur = NULL, s_all->s_selected.sel = NULL;
    init_sell_button(s_all), init_info_texts(s_all);
}

void create_mob_textures(all_t *s_all)
{
    s_all->s_wave_c.one = sfTexture_createFromFile("sprites/round.png", NULL);
    s_all->s_wave_c.two = sfTexture_createFromFile("sprites/square.png", NULL);
    s_all->s_wave_c.three =
    sfTexture_createFromFile("sprites/triangle.png", NULL);
}

void init_all(all_t *s_all)
{
    s_all->s_game.font = sfFont_createFromFile("font/arial.ttf");
    setup(s_all), parse_map(s_all), init_menu(s_all), list_menu_buttons(s_all);
    init_selected(s_all), init_pause_button(s_all), init_side_menu(s_all);
    s_all->s_map.spawner_pos = get_spawner_position(s_all);
    s_all->s_map.castle_pos = get_castle_position(s_all);
    init_player_infos(s_all);
    generate_round_mobs(s_all), s_all->s_spawning.seconds = 0;
    init_selected_turret(s_all);
    s_all->s_spawning.clock = sfClock_create();
    s_all->s_spawning.clock2 = sfClock_create();
    init_slider_arrow(s_all), s_all->s_selected2.zone = NULL;
    s_all->s_spawning.seconds2 = 0, s_all->s_turret = NULL;
    create_mob_textures(s_all);
    generate_selected_turret(s_all), list_targetting(s_all), parse_wave(s_all);
    init_all2(s_all), randomize(), init_wave_button(s_all);
    init_count_wave_button(s_all);
}