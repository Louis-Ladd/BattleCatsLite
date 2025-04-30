#include "label.h"
#include "../log.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

Label* r_CreateLabel(SDL_Renderer* renderer, float x, float y, char text[],
                     TTF_Font* font, SDL_Color color)
{
    Label* label = malloc(sizeof(*label));

    if (!label)
    {
        LOG_ERROR("Failed to allocate memory for new label!");
        return NULL;
    }

    label->text = malloc((strlen(text) + 1) * sizeof(char));

    if (!label->text)
    {
        LOG_ERROR("Failed to allocate memory for labels' char buffer!");
        return NULL;
    }

    strcpy(label->text, text);

    SDL_Surface* label_surface = TTF_RenderText_Solid(font, text, color);

    if (!label_surface)
    {
        LOG_ERROR("Unable to create label surface due to %s\n", TTF_GetError());
        return NULL;
    }

    SDL_Texture* label_texture =
        SDL_CreateTextureFromSurface(renderer, label_surface);

    if (!label_texture)
    {
        LOG_ERROR("Unable to create texture for label due to: %s\n",
                  SDL_GetError());
        return NULL;
    }

    label->texture = label_texture;

    SDL_FRect text_rect = {x, y, label_surface->w, label_surface->h};

    label->rect = text_rect;

    SDL_FreeSurface(label_surface);

    return label;
}

void r_DrawText(int x, int y, TTF_Font* font, char text[],
                SDL_Renderer* renderer, SDL_Color color)
{
    SDL_Surface* label_surface = TTF_RenderText_Solid(font, text, color);

    if (!label_surface)
    {
        LOG_ERROR("Unable to draw \"%s\" due to %s\n", text, TTF_GetError());
        SDL_FreeSurface(label_surface);
        return;
    }

    SDL_Texture* label_texture =
        SDL_CreateTextureFromSurface(renderer, label_surface);

    if (!label_surface)
    {
        LOG_ERROR("Unable to create texture for text \"%s\" due to %s\n", text,
                  SDL_GetError());
    }
    SDL_Rect dest = {x, y, label_surface->w, label_surface->h};

    SDL_RenderCopy(renderer, label_texture, NULL, &dest);

    SDL_FreeSurface(label_surface);
    SDL_DestroyTexture(label_texture);
}

void r_UpdateLabel() { printf("Not Implemented!!!"); }

void r_RenderLabel(SDL_Renderer* renderer, Label* label)
{
    SDL_RenderCopyF(renderer, label->texture, NULL, &label->rect);
}

void r_DestroyLabel(Label* label)
{
    SDL_DestroyTexture(label->texture);
    free(label->text);
    free(label);
}
