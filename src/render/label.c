#include <SDL2/SDL_ttf.h>
#include "../application/application.c"

const SDL_Color WHITE = { 255, 255, 255}; 

void draw_label(int x, int y, TTF_Font* font, char text[], struct Application* app) 
{
  SDL_Surface* label_surface = TTF_RenderText_Solid( font, text, WHITE);

  SDL_Texture* label_texture = SDL_CreateTextureFromSurface( app->renderer, label_surface);

  SDL_Rect dest = {x, y, label_surface->w, label_surface->h};

  SDL_RenderCopy( app->renderer, label_texture, NULL, &dest); 

  return;
}
