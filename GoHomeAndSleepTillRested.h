//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_GOHOMEANDSLEEPTILLRESTED_H
#define GOLD_MINER_FSM_GOHOMEANDSLEEPTILLRESTED_H


#include "State.h"
#include "Miner.h"

class GoHomeAndSleepTillRested : public State<Miner> {
private:

    GoHomeAndSleepTillRested() {};

public:

    void Enter(Miner *miner);

    void Execute(Miner *miner);

    void Exit(Miner *miner);

    // Singleton pattern.
    static GoHomeAndSleepTillRested *Instance();
};


#endif //GOLD_MINER_FSM_GOHOMEANDSLEEPTILLRESTED_H
