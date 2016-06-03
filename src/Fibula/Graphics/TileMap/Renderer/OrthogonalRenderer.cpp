#include "OrthogonalRenderer.hpp"

using namespace Fibula::Graphics::TileMap::Renderer;


void OrthogonalRenderer::render(
    WindowRenderer *renderer,
    Fibula::Graphics::TileMap::TileMap *tileMap
) {
    LayerVector layers = tileMap->getLayers();

    for (LayerVector::iterator it = layers.begin(); it != layers.end(); ++it) {
        this->renderTiles(renderer, *(*it).get());
    }
}

void OrthogonalRenderer::renderTiles(WindowRenderer *renderer, const TileMapLayer &layer)
{
    TileVector tiles = layer.getTiles();

    for (TileVector::iterator it = tiles.begin(); it != tiles.end(); ++it) {
        Tile tile = *it->get();

        // Row calculation
        int row = tile.getPosition() / (tile.getWidth() / 2);

        // Column calculation
        double aCol = tile.getPosition() / (double) (tile.getWidth() / 2);
        int col = (int) ((aCol - row) * (tile.getHeight() / 2));

        // Clipping calculation
        int rowFirstPixel = ((row + 1) * tile.getHeight());
        int colFirstPixel = ((col + 1) * tile.getWidth());

//        SDL_Rect clip = { colFirstPixel, rowFirstPixel, tile.getWidth(), tile.getHeight() };
//        SDL_Rect render = { col * tile.getWidth(), row * tile.getHeight(), tile.getWidth(), tile.getHeight() };
//
//        SDL_RenderCopy(renderer, layer.getTileSet()->getTexture(), &clip, &render);
    }
}

