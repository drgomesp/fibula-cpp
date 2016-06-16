#include <memory>

#include "Kernel.hpp"

#include <Fibula/Core/KernelAwareListener.hpp>
#include <Fibula/Graphics/TileMap/Layer.hpp>
#include <Fibula/Graphics/TileMap/IsometricMap.hpp>
#include <Fibula/Graphics/TileMap/OrthogonalMap.hpp>

using namespace std;
using namespace Game::Core;
using namespace Fibula::Core;
using namespace Fibula::Graphics;

using OrthogonalMap = Fibula::Graphics::TileMap::OrthogonalMap;
using IsometricMap = Fibula::Graphics::TileMap::IsometricMap;
using Projection = Fibula::Graphics::TileMap::Projection;
using Layer = Fibula::Graphics::TileMap::Layer;
using TileSet = Fibula::Graphics::TileMap::TileSet;
using EngineKernel = Fibula::Core::Kernel;

void Game::Core::Kernel::registerListeners()
{
    Fibula::Core::Kernel::registerListeners();
}

void Game::Core::Kernel::bootstrap()
{
    // Initialize the engine kernel
    EngineKernel::bootstrap();

//    auto tileSet1 = make_shared<TileSet>("resources/mountain_landscape.png", 32, 32);
//    auto tileMap1 = make_shared<OrthogonalMap>("Demo TileMap", 5, 5, 32, 32);
//
//    auto ground1 = make_shared<Layer>("Ground", 5, 5, true, 1.0f, tileSet1);
//    auto mountains1 = make_shared<Layer>("Mountains", 5, 5, true, 1.0f, tileSet1);
//
//    /* Comes from Tiled Map Editor */
//    vector<unsigned int> groundData = {79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79};
//    vector<unsigned int> mountainsData = {0, 0, 0, 0, 0, 0, 60, 61, 62, 0, 0, 76, 77, 78, 0, 0, 92, 93, 94, 0, 0, 0, 0, 0, 0};
//
//    tileMap1->loadLayer(ground1, groundData);
//    tileMap1->loadLayer(mountains1, mountainsData);
//
//    this->window->addDrawable(tileMap1);
//
//    auto tileSet = make_shared<TileSet>("resources/isometric2.png", 64, 64);
//
//    auto grass = make_shared<Layer>("Grass", 5, 5, true, 1.0f, tileSet);
//    auto trees = make_shared<Layer>("Trees", 5, 5, true, 1.0f, tileSet);
//
//    auto tileMap = make_shared<IsometricMap>("Demo TileMap", 5, 5, 64, 32);
//
//    /* Comes from Tiled Map Editor */
//    vector<unsigned int> gData= {
//        3, 3, 3, 3, 3,
//        3, 3, 3, 3, 3,
//        3, 3, 3, 3, 3,
//        3, 3, 3, 3, 3,
//        3, 3, 3, 3, 0
//    };
//
//    vector<unsigned int> tData = {
//        0, 0, 0, 4, 16,
//        0, 0, 0, 19, 23,
//        0, 0, 0, 19, 23,
//        0, 0, 0, 19, 23,
//        0, 0, 0, 19, 23
//    };
//
//    tileMap->loadLayer(grass, gData);
//    tileMap->loadLayer(trees, tData);
//
//    this->window->addDrawable(tileMap);
}