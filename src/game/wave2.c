/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** wave2
*/

#include "defender.h"

void get_random_position(tuto_t *new)
{
    int x = rand() % 42;
    int y = rand() % 42;
    int x_neg = (rand() % 2);
    int y_neg = (rand() % 2);
    if (x_neg == 0 && y_neg == 0) {
        new->pos.x = x, new->pos.y = y;
    } if (x_neg == 1 && y_neg == 1) {
        new->pos.x = (x * -1), new->pos.y = (y * -1);
    } if (x_neg == 1 && y_neg == 0) {
        new->pos.x = (x * -1), new->pos.y = y;
    } if (x_neg == 0 && y_neg == 1) {
        new->pos.x = x, new->pos.y = (y * -1);
    }
}

void init_shader_mob(tuto_t *new, all_t *s_all)
{
    sfShader_setVec2Uniform(new->shader, "lightpos",
        (sfGlslVec2){new->pos.x, new->pos.y});
    sfShader_setFloatUniform(new->shader, "screenHeight", 
        sfRenderWindow_getSize(s_all->s_game.window).y);
    if (new->id == 1) { sfShader_setVec3Uniform(new->shader, "lightColor",
        (sfGlslVec3){50, 255, 50});
        sfShader_setVec3Uniform(new->shader, "lightAttenuation",
        (sfGlslVec3){4.5, 4.5, 4.5});
    } if (new->id == 2) { sfShader_setVec3Uniform(new->shader, "lightColor",
        (sfGlslVec3){255, 50, 50});
        sfShader_setVec3Uniform(new->shader, "lightAttenuation",
        (sfGlslVec3){1.5, 1.5, 1.5});
    } if (new->id == 3) { sfShader_setVec3Uniform(new->shader, "lightColor",
        (sfGlslVec3){255, 255, 50});
        sfShader_setVec3Uniform(new->shader, "lightAttenuation",
        (sfGlslVec3){5.5, 5.5, 5.5});
    }
}