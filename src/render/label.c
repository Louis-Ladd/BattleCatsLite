#include "label.h"

Label* r_CreateLabel(SDL_Renderer* renderer, float x, float y, char text[],
                     TTF_Font* font, SDL_Color color) {
    Label* label = malloc(sizeof(*label));

    label->text = malloc((strlen(text) + 1) * sizeof(char));

    strcpy(label->text, text);

    SDL_Surface* label_surface = TTF_RenderText_Solid(font, text, color);

    SDL_Texture* label_texture =
        SDL_CreateTextureFromSurface(renderer, label_surface);

    label->texture = label_texture;

    SDL_FRect text_rect = {x, y, label_surface->w, label_surface->h};

    label->rect = text_rect;

    SDL_FreeSurface(label_surface);

    return label;
}

void r_DrawText(int x, int y, TTF_Font* font, char text[],
                SDL_Renderer* renderer, SDL_Color color) {
    SDL_Surface* label_surface = TTF_RenderText_Solid(font, text, color);

    if (!label_surface) {
        printf("Unable to draw \"%s\" due to an error. ERROR: %s\n", text,
               TTF_GetError());
        SDL_FreeSurface(label_surface);
        return;
    }

    SDL_Texture* label_texture =
        SDL_CreateTextureFromSurface(renderer, label_surface);

    SDL_Rect dest = {x, y, label_surface->w, label_surface->h};

    SDL_RenderCopy(renderer, label_texture, NULL, &dest);

    SDL_FreeSurface(label_surface);
    SDL_DestroyTexture(label_texture);
}

void r_UpdateLabel() { printf("Not Implemented!!!"); }

void r_RenderLabel(SDL_Renderer* renderer, Label* label) {
    SDL_RenderCopyF(renderer, label->texture, NULL, &label->rect);
}

void r_DestroyLabel(Label* label) {
    SDL_DestroyTexture(label->texture);
    free(label->text);
    free(label);
}
