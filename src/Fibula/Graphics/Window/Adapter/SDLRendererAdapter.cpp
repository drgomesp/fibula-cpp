#include "SDLRendererAdapter.hpp"

#include <SDL2/SDL_image.h>
#include <Fibula/Graphics/Window/Adapter/SDLWindowAdapter.hpp>

#include <string>

using namespace std;
using namespace Fibula::Graphics::Window;
using namespace Fibula::Graphics::Window::Adapter;

SDLRendererAdapter::SDLRendererAdapter(WindowAdapterInterface *window)
    : window(window)
{
    SDLWindowAdapter *sdlAdapter = dynamic_cast<SDLWindowAdapter *>(window);

    if (NULL == sdlAdapter) {
        throw runtime_error("Failed to retrieve window implementation from adapter");
    }

    this->renderer = SDL_CreateRenderer(sdlAdapter->getWindowImpl(), -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    if (!IMG_Init(IMG_INIT_PNG)) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }

    std::string texturePath = "../../resources/mountain_landscape.png";
    SDL_Texture *texture;
    SDL_Surface *loadedSurface = IMG_Load(texturePath.c_str());

    if (loadedSurface == NULL) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", texturePath.c_str(), IMG_GetError() );
    }

    texture = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);

    if( texture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", texturePath.c_str(), SDL_GetError() );
    }

    SDL_FreeSurface(loadedSurface);

    //Clear screen
    SDL_RenderClear(this->renderer);

    //Render texture to screen
    SDL_RenderCopy(this->renderer, texture, NULL, NULL );

    //Update screen
    SDL_RenderPresent(this->renderer);
}

SDLRendererAdapter::~SDLRendererAdapter()
{
    SDL_DestroyRenderer(this->renderer);
}
