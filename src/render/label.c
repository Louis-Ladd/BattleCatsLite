#include "SDL_ttf.h"

struct Label {
  char[256] text;
  SDL_Surface *surface;
  SDL_Texture *text;
  SDL_Color color;
};

struct Label *create_label(TTF_Font* font, char[] text, SDL_Renderer* renderer) 
{
  struct Label *label = malloc(sizeof(struct Label));
  Label->surface = TTF_RenderText_Soild(font, text, color);
  Label->text = SDL_CreateTextureFromSurface()
  return label
}
