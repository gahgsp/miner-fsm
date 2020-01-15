#include <iostream>
#include <synchapi.h>
#include "Miner.h"

int main() {

    std::cout << "IIUUU" << std::endl;

    Miner miner(1);

    for (int i = 0; i < 10; i++) {
        miner.Update();
        Sleep(500);
    }
    return 0;
}