//
// Created by Kelvin on 09/01/2020.
//

#include <iostream>
#include "QuenchThirst.h"
#include "EnterMineAndDigForNugget.h"

void QuenchThirst::Enter(Miner *miner) {
    if (miner->Location() != SALOON) {
        miner->ChangeLocation(SALOON);
        std::cout << "Too thirsty... need some whiskey right now!" << std::endl;
    }
}

void QuenchThirst::Execute(Miner *miner) {
    if (miner->Thirsty()) {
        miner->BuyAndDrinkAWhiskey();
        std::cout << "Enough alcohol for today..." << std::endl;
        miner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
    }
}

void QuenchThirst::Exit(Miner *miner) {
    std::cout << "Leaving the saloon, feeling refreshed!" << std::endl;
}

QuenchThirst *QuenchThirst::Instance() {
    static QuenchThirst instance;
    return &instance;
}