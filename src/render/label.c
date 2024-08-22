void r_DrawLabel(int x, int y, TTF_Font* font, char text[], struct Application* app, SDL_Color color) 
{
  SDL_Surface* label_surface = TTF_RenderText_Solid( font, text, color);

  if (!label_surface)
  {
    printf("Unable to draw \"%s\" due to an error\n", text);
    SDL_FreeSurface(label_surface);
    return;
  }

  SDL_Texture* label_texture = SDL_CreateTextureFromSurface( app->renderer, label_surface);

  SDL_Rect dest = {x, y, label_surface->w, label_surface->h};

  SDL_RenderCopy( app->renderer, label_texture, NULL, &dest); 

  SDL_FreeSurface(label_surface);
  SDL_DestroyTexture(label_texture); 

  return;
}
