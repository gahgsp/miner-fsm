//
// Created by Kelvin on 09/01/2020.
//

#include <iostream>
#include "GoHomeAndSleepTillRested.h"
#include "EnterMineAndDigForNugget.h"

void GoHomeAndSleepTillRested::Enter(Miner *miner) {
    if (miner->Location() != HOME) {
        std::cout << "Going home to get some rest..." << std::endl;
        miner->ChangeLocation(HOME);
    }
}

void GoHomeAndSleepTillRested::Execute(Miner *miner) {
    if (!miner->Fatigued()) {
        std::cout << "Enough rest! Time to dig more gold!" << std::endl;
        miner->ChangeState(EnterMineAndDigForNugget::Instance());
    } else {
        // Sleep
        miner->DecreaseFatigue();
        std::cout << "ZzzZzz ZZzz..." << std::endl;
    }
}

void GoHomeAndSleepTillRested::Exit(Miner *miner) {
    std::cout << "Leaving the house..." << std::endl;
}

GoHomeAndSleepTillRested* GoHomeAndSleepTillRested::Instance() {
    static GoHomeAndSleepTillRested instance;
    return &instance;
}