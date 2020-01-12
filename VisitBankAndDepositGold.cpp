//
// Created by Kelvin on 09/01/2020.
//

#include "VisitBankAndDepositGold.h"

void VisitBankAndDepositGold::Enter(Miner *miner) {

}

void VisitBankAndDepositGold::Execute(Miner *miner) {

}

void VisitBankAndDepositGold::Exit(Miner *miner) {

}

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance() {
    static VisitBankAndDepositGold instance;
    return &instance;
}