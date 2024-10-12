#include <stdio.h>

#include "include/tmx.h"

#if _WIN32
    #include <SDL2>

#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_events.h>
    #include <SDL2/SDL_image.h>
#endif

void stellarCleanup() {
  tmx_map_free(map);

	SDL_RemoveTimer(timer_id);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
