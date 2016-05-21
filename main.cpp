#include <iostream>
#include <Fibula/Core.h>

using namespace std;
using namespace Fibula::Core;

int main() {
    try {
        Kernel game;
        game.run();
    } catch (exception const &e) {
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
