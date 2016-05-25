#include <iostream>
#include <Fibula/Core.h>

using namespace std;
using namespace Fibula::Core;

int main() {
    Kernel game;

    try {
        game.run();
    } catch (exception const &e) {
        game.terminate();
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
