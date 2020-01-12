//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_QUENCHTHIRST_H
#define GOLD_MINER_FSM_QUENCHTHIRST_H


#include "State.h"

class QuenchThirst : public State {
public:
    void Enter(Miner *miner) override;

    void Execute(Miner *miner) override;

    void Exit(Miner *miner) override;

    static QuenchThirst* Instance();
};


#endif //GOLD_MINER_FSM_QUENCHTHIRST_H
