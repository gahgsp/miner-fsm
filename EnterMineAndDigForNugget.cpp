//
// Created by Kelvin on 09/01/2020.
//

#include <iostream>
#include "EnterMineAndDigForNugget.h"
#include "VisitBankAndDepositGold.h"
#include "QuenchThirst.h"

EnterMineAndDigForNugget *EnterMineAndDigForNugget::Instance() {
    static EnterMineAndDigForNugget instance;
    return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner *pMiner) {
    // If the miner is not at the gold mine, he must
    // change his location to the gold mine.
    if (pMiner->Location() != GOLD_MINE) {
        std::cout << "Walkin' to the gold mine." << std::endl;

        pMiner->ChangeLocation(GOLD_MINE);
    }
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner) {
    // Digs gold nuggets until it reaches the max value.
    // If he gets thirsty, changes the state to go to the salon for a whiskey.
    pMiner->AddToGoldCarried(1);

    // Increases the fatigue.
    pMiner->IncreaseFatigue();

    std::cout << "Picking up a gold nugget." << std::endl;

    // If we have enough gold, we can go to the bank.
    if (pMiner->PocketsFull()) {
        pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
    }

    // If the miner is thirsty, then we go to the saloon.
    if (pMiner->Thirsty()) {
        pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
    }
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner) {
    std::cout << "Leaving the mine with the pocket full of gold!" << std::endl;
}
