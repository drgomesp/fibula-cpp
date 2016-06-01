#include "SDLRendererAdapter.hpp"

#include <SDL2/SDL_image.h>
#include <Fibula/Graphics/TileMap/TileMap.hpp>
#include <Fibula/Graphics/TileMap/TileMapLayer.hpp>
#include <Fibula/Graphics/Window/Adapter/SDLWindowAdapter.hpp>

#include <string>

using namespace std;
using namespace Fibula::Graphics::TileMap;
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

    TileSet tileSet(512, 512, 32, 32, texture);
    TileMapLayer ground("Ground", true, &tileSet);
    TileMapLayer mountains("Mountains", true, &tileSet);

    vector<unsigned int> groundData = {
        172,172,172,79,34,34,34,34,34,34,34,34,56,57,54,55,56,147,67,67,68,79,79,171,172,172,173,79,79,55,55,55,
        172,172,172,79,34,34,34,34,34,34,146,79,79,79,79,79,79,79,79,79,79,79,155,142,172,159,189,79,79,55,55,55,
        172,172,172,79,79,34,34,34,34,34,79,79,79,79,79,79,79,79,79,79,79,79,171,172,159,189,79,79,79,55,55,55,
        188,188,188,79,79,79,79,34,34,34,36,172,172,143,142,157,79,79,79,79,79,79,187,159,189,79,79,79,55,55,55,55,
        79,79,79,79,79,79,79,79,34,34,36,172,159,158,172,143,157,79,79,79,79,79,79,79,79,79,39,51,51,51,55,55,
        79,79,79,79,79,79,79,79,79,34,36,172,143,142,172,172,143,157,79,79,79,79,79,79,79,79,79,79,79,79,79,55,
        79,79,79,79,79,79,79,79,79,34,52,172,172,172,172,172,172,143,156,157,79,79,79,79,79,79,79,79,79,79,79,79,
        79,79,79,79,79,79,79,79,79,34,52,172,172,172,172,172,172,159,188,189,79,79,79,79,79,171,172,172,173,79,79,79,
        79,79,79,79,79,79,79,79,79,79,79,188,158,172,172,172,172,173,79,79,79,79,79,79,79,187,158,159,189,79,79,79,
        79,79,79,79,79,79,79,79,79,79,79,79,171,172,172,159,188,189,79,79,79,79,79,79,79,79,171,173,79,79,79,79,
        79,79,79,79,79,79,79,79,79,79,79,79,171,172,172,173,79,79,79,79,79,79,79,79,79,79,171,173,79,79,79,79,
        155,142,157,79,79,79,79,79,79,79,79,79,187,188,188,189,79,79,79,79,79,79,79,79,79,79,171,173,79,79,79,79,
        171,172,173,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,171,173,79,79,79,79,
        171,172,143,156,157,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,187,189,79,79,79,79,
        187,188,158,172,173,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
        79,79,79,188,189,79,79,79,79,79,79,155,156,156,157,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,155,156,
        34,34,79,79,79,79,79,79,79,79,79,171,172,172,173,79,79,79,79,79,79,79,79,79,79,79,79,79,79,155,142,172,
        34,34,34,79,79,79,79,79,79,79,79,171,172,172,173,79,79,79,79,79,79,79,79,79,79,79,79,79,79,171,172,172,
        34,34,34,34,79,79,79,79,79,79,155,172,172,159,189,79,79,79,79,79,79,79,79,79,79,79,79,79,79,171,172,172,
        34,34,34,34,34,34,79,79,79,79,171,172,172,173,79,79,79,79,79,79,79,79,79,79,79,79,79,79,155,142,172,172
    };

    ground.createTilesFromVector(groundData);


    SDL_FreeSurface(loadedSurface);

    //Clear screen
    SDL_RenderClear(this->renderer);

    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0;
    topLeftViewport.y = 0;
    topLeftViewport.w = this->window->getWidth() / 2;
    topLeftViewport.h = this->window->getHeight() / 2;
    SDL_RenderSetViewport(this->renderer, &topLeftViewport);

    //Render texture to screen
    SDL_RenderCopy(this->renderer, texture, NULL, NULL );

    //Update screen
    SDL_RenderPresent(this->renderer);
}

SDLRendererAdapter::~SDLRendererAdapter()
{
    SDL_DestroyRenderer(this->renderer);
}
