#include <iostream>
#include <Fibula/Core/Kernel.hpp>
#include <Fibula/Console/ConsoleListener.hpp>

using namespace std;
using namespace Fibula::Core;
using namespace Fibula::Console;

int main() {
    Kernel game;

    std::shared_ptr<ConsoleListener> consoleListener = std::make_shared<ConsoleListener>(&game);
    game.addListener("event.console.*", consoleListener);

    try {
        game.run();
    } catch (exception const &e) {
        game.terminate();
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
