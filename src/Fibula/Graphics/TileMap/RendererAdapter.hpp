#ifndef FIBULA_TILEMAPRENDERERADAPTER_HPP
#define FIBULA_TILEMAPRENDERERADAPTER_HPP

#include <Fibula/Graphics/Window/WindowAdapter.hpp>
#include <Fibula/Graphics/TileMap/TileMap.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            using WindowRenderer = Fibula::Graphics::Window::RendererAdapter;

            class RendererAdapter
            {
            public:
                RendererAdapter()
                { }

                virtual void render(WindowRenderer *renderer, TileMap *tileMap) = 0;

                virtual ~RendererAdapter()
                { }
            };
        }
    }
}

#endif //FIBULA_RENDERERADAPTER_HPP
