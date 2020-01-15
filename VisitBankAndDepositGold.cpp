//
// Created by Kelvin on 09/01/2020.
//

#include <iostream>
#include "VisitBankAndDepositGold.h"
#include "GoHomeAndSleepTillRested.h"

void VisitBankAndDepositGold::Enter(Miner *miner) {
    if (miner->Location() != BANK) {
        std::cout << "Going to the Bank!" << std::endl;
        miner->ChangeLocation(BANK);
    }
}

void VisitBankAndDepositGold::Execute(Miner *miner) {
    // Deposit the current amount of gold carried.
    miner->DepositGold(miner->GoldCarried());

    // Now, the Miner has 0 gold on his pockets.
    miner->SetGoldInPockets(0);

    std::cout << "Gold has been succesfully deposit. Current wealth: " << miner->Wealth() << std::endl;

    // After a hard day, it is time to rest!
    miner->ChangeState(GoHomeAndSleepTillRested::Instance());
}

void VisitBankAndDepositGold::Exit(Miner *miner) {
    std::cout << "Leaving the bank a bit more richer..." << std::endl;
}

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance() {
    static VisitBankAndDepositGold instance;
    return &instance;
}