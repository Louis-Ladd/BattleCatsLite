#include "mouse.h"
#include "../application.h"
#include "../log.h"

#if SDL_VERSION_ATLEAST(2, 0, 22)
// Why the hell doesn't ubuntu's pre-built SDL2 package not have this?
#else
SDL_FORCE_INLINE SDL_bool SDL_PointInFRect(const SDL_FPoint* p,
                                           const SDL_FRect* r)
{
    return ((p->x >= r->x) && (p->x < (r->x + r->w)) && (p->y >= r->y) &&
            (p->y < (r->y + r->h)))
               ? SDL_TRUE
               : SDL_FALSE;
}
#endif

void HandleMouseInput(GenericUIElementList* element_list)
{
    if (application.window_event.type != SDL_MOUSEBUTTONDOWN)
    {
        return;
    }

    LOG("Not implemented %i", element_list->element_count);

    SDL_FPoint mouse_position;

    mouse_position.x = application.window_event.motion.x;
    mouse_position.y = application.window_event.motion.y;
}
