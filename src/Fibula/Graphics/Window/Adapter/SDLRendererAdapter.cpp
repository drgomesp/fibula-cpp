#include "SDLRendererAdapter.hpp"

#include <vector>

#include <SDL2/SDL_image.h>
#include <Fibula/Graphics/TileMap/TileMap.hpp>
#include <Fibula/Graphics/Window/Adapter/SDLWindowAdapter.hpp>
#include <Fibula/Graphics/TileMap/Renderer/OrthogonalRenderer.hpp>

using namespace std;
using namespace Fibula::Graphics::TileMap;
using namespace Fibula::Graphics::Window;
using namespace Fibula::Graphics::Window::Adapter;
using namespace Fibula::Graphics::TileMap::Renderer;

SDLRendererAdapter::SDLRendererAdapter(WindowAdapter *window)
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
    SDL_Surface *surface = IMG_Load(texturePath.c_str());

    if (surface == NULL) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", texturePath.c_str(), IMG_GetError() );
    }

    texture = SDL_CreateTextureFromSurface(this->renderer, surface);

    if( texture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", texturePath.c_str(), SDL_GetError() );
    }

    TileSet tileSet(512, 512, 32, 32, texture);
    TileMapLayer ground("Ground", true, &tileSet);
    TileMapLayer mountains("Mountains", true, &tileSet);

    vector<int> groundData = {
        78,79,78,79,78,79,78,171,172,172,172,172,172,172,172,173,79,95,95,79,79,79,79,79,
        94,95,94,95,94,95,94,171,172,172,172,172,172,172,172,173,79,94,95,95,95,95,95,95,
        78,79,78,79,78,79,78,187,158,172,172,172,172,172,172,173,79,79,94,94,94,95,78,79,
        94,95,94,95,94,95,94,95,187,158,172,172,172,172,159,189,95,95,94,95,94,95,94,95,
        78,79,78,79,78,79,78,79,78,171,172,172,172,172,173,95,78,79,79,79,78,79,78,79,
        94,95,94,95,94,95,94,95,94,171,172,172,172,172,173,79,79,95,95,95,94,95,94,95,
        78,79,78,79,78,79,78,79,78,171,172,172,172,172,173,95,95,79,155,156,157,79,78,79,
        94,95,94,95,94,95,94,95,94,187,28,28,28,28,189,95,94,95,171,172,173,95,94,95,
        78,79,78,79,78,79,78,79,78,110,59,60,60,61,111,79,78,79,187,188,189,79,78,79,
        94,95,94,95,94,95,94,95,94,126,75,76,76,77,127,95,94,95,94,95,94,95,94,95,
        78,79,78,155,156,157,78,79,78,110,75,76,76,77,111,79,78,79,78,79,78,79,78,79,
        94,95,94,171,172,173,94,95,94,126,75,76,76,77,127,95,94,95,94,95,94,95,94,95,
        78,79,78,187,188,189,78,79,78,110,75,76,76,77,111,79,78,79,78,79,78,79,78,79,
        94,95,94,95,94,95,94,95,94,126,75,76,76,77,127,95,94,95,94,95,94,95,94,95,
        78,79,78,79,78,79,78,79,78,110,75,76,76,77,111,79,78,79,78,79,78,79,78,79
    };

    vector<int> mountainsData = {
        -1,-1,-1,-1,-1,-1,-1,-1,16,17,23,23,23,23,24,25,21,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,32,65,38,39,39,40,41,41,37,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,48,65,54,39,35,51,57,57,53,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,48,65,39,50,51,50,51,57,37,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,48,49,39,51,50,50,51,52,53,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,64,65,39,67,66,66,67,68,69,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,80,81,82,190,191,83,83,84,69,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,96,97,98,206,207,99,99,100,85,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    };

    ground.createTilesFromVector(groundData);
    mountains.createTilesFromVector(mountainsData);

    class TileMap tileMap("tileMap", 768, 480);
    tileMap.addLayer(std::make_shared<TileMapLayer>(ground));
    tileMap.addLayer(std::make_shared<TileMapLayer>(mountains));

    SDL_FreeSurface(surface);

    //Clear screen
    SDL_RenderClear(this->renderer);

    OrthogonalRenderer renderer;
//    renderer.render(static_cast<RendererAdapter *>(this->renderer), &tileMap);

    //Update screen
    SDL_RenderPresent(this->renderer);
}

SDLRendererAdapter::~SDLRendererAdapter()
{
    SDL_DestroyRenderer(this->renderer);
}
