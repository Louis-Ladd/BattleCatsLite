#include "uiimage.h"
#include "../application.h"
#include "../log.h"

UIImage* CreateUIImage(SDL_Surface image_surface, float x, float y, float w,
					   float h)
{
	UIImage* ui_image = malloc(sizeof(*ui_image));

	if (!ui_image)
	{
		LOG_ERROR("Failed to allocate memory for UIImage!");
		return NULL;
	}

	ui_image->image =
		r_CreateImage(application.renderer, &image_surface, x, y, w, h);

	if (!ui_image->image)
	{
		LOG_ERROR("Something went wrong creating a UIImage' image!");
	}

	return ui_image;
}

void DestroyUIImage(UIImage* ui_image)
{
	r_DestroyImage(ui_image->image);
	free(ui_image);
}
