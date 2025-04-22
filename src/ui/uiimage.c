#include "uiimage.h"

UIImage* CreateUIImage(SDL_Surface image_surface, float x, float y, float w,
                       float h)
{
    UIImage* ui_image = malloc(sizeof(*ui_image));

    ui_image->image =
        r_CreateImage(application.renderer, &image_surface, x, y, w, h);
    return ui_image;
}

void DestroyUIImage(UIImage* ui_image)
{
    r_DestroyImage(ui_image->image);
    free(ui_image);
}
