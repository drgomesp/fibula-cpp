#include <iostream>

#include "Core/Kernel.hpp"

using namespace std;

int main()
{
    Game::Core::Kernel game("My awesome game!");

    try {
        game.run();
    } catch (exception const &e) {
        game.terminate();
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}