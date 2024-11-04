#include "entity_behavior.h"
#include "../application.h"

inline void e_EntityGravity(Entity* entity)
{
    if (entity->position.y <= 700.0f)
    {
        if (entity->velocity.y < 240.8f)
        {
            entity->velocity.y += 19.1f;
        }
    }
    else if (entity->velocity.y > 0)
    {
        entity->velocity.y = 0;
    }
}

#define ENTROPY_CONSTANT 2000.0f

inline void e_ApplyEntropy(Entity* entity)
{
    if (entity->velocity.x > -0.01 && entity->velocity.x < 0.01)
    {
        entity->velocity.x = 0;
        return;
    }
    entity->velocity.x +=
        (entity->velocity.x > 0 ? -ENTROPY_CONSTANT : ENTROPY_CONSTANT) *
        application.delta_time;
}
