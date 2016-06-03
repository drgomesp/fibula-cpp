#ifndef FIBULA_ORTHOGONALRENDERER_HPP
#define FIBULA_ORTHOGONALRENDERER_HPP

#include <Fibula/Graphics/TileMap/RendererAdapter.hpp>
#include <Fibula/Graphics/TileMap/TileMap.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            namespace Renderer {
                class OrthogonalRenderer : public RendererAdapter
                {
                public:
                    virtual void render(WindowRenderer *renderer, TileMap *tileMap) override;

                protected:
                    void renderTiles(WindowRenderer *renderer, const TileMapLayer &layer);
                };
            }
        }
    }
}


#endif //FIBULA_ORTHOGONALRENDERER_HPP
