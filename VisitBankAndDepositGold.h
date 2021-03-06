//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_VISITBANKANDDEPOSITGOLD_H
#define GOLD_MINER_FSM_VISITBANKANDDEPOSITGOLD_H


#include "State.h"
#include "Miner.h"

class VisitBankAndDepositGold : public State<Miner> {
private:

    VisitBankAndDepositGold() {}

public:

    // Singleton pattern.
    static VisitBankAndDepositGold *Instance();

    void Enter(Miner *miner);

    void Execute(Miner *miner);

    void Exit(Miner *miner);
};


#endif //GOLD_MINER_FSM_VISITBANKANDDEPOSITGOLD_H
