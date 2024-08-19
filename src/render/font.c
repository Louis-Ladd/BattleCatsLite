#include "SDL.h"
#include "SDL_ttf.h"

struct Label {
  SDL_Surface *text;
  TTF_Font* font;
  SDL_Color color;
  SDL_Texture* label_texture;
};

struct Label *Create_Label()
{
  sruct Label* text_label = malloc(sizeof(struct Label));
}
