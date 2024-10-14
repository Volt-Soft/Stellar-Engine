#include "include/tmx.h"

#ifdef _WIN32
    #include <C:/SDL2/include/SDL.h>
    #include <C:/SDL2/include/SDL_events.h>
    #include <C:/SDL2_image/include/SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_events.h>
    #include <SDL2/SDL_image.h>
#endif

// Global declarations
tmx_map *map;
SDL_TimerID timer_id;
SDL_Renderer *ren;
SDL_Window *win;

void stellarCleanup() {
    tmx_map_free(map);
    SDL_RemoveTimer(timer_id);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
