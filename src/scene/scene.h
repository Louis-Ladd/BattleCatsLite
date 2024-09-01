#ifndef SCENE_H_
#define SCENE_H_

#include "../entity/entity.h"

typedef struct {
    Entity* entities;
    u16 entity_count;
} Scene;

//void RenderScene(Application* app);

//void CreateScene(Application* app, int scene_number);

#endif