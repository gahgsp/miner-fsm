//
// Created by Kelvin on 14/01/2020.
//

#ifndef GOLD_MINER_FSM_MINERGLOBALSTATE_H
#define GOLD_MINER_FSM_MINERGLOBALSTATE_H

#include "Miner.h"

class MinerGlobalState : public State<Miner> {
private:

    MinerGlobalState() {};

public:

    static MinerGlobalState *Instance();

    void Enter(Miner *miner);

    void Execute(Miner *miner);

    void Exit(Miner *miner);
};

#endif //GOLD_MINER_FSM_MINERGLOBALSTATE_H
