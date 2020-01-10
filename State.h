//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_STATE_H
#define GOLD_MINER_FSM_STATE_H


#include "Miner.h"

class State {
public:
    virtual ~State() {}

    // This will execute when the state is entered.
    virtual void Enter(Miner*) = 0;

    // This is called each time the entity's update function is called.
    virtual void Execute(Miner*) = 0;

    // This will execute when the state is exited.
    virtual void Exit(Miner*) = 0;
};


#endif //GOLD_MINER_FSM_STATE_H
