#ifndef LEVEL_H_
#define LEVEL_H_

#include "../cats/cat.h"
#include "../entity/entity.h"
#include "../render/image.h"
#include "../render/label.h"
#include "../render/sprite.h"
#include "../scene/scene_manager.h"
#include "SDL2/SDL_image.h"

void create_level_one(SDL_Renderer* renderer, SceneManager* scene_manager);

#endif
