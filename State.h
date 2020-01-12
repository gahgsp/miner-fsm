//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_STATE_H
#define GOLD_MINER_FSM_STATE_H


#include "Miner.h"

template <class BaseEntity>
class State {
public:

    // This will execute when the state is entered.
    virtual void Enter(Miner*) = 0;

    // This is called each time the entity's update function is called.
    virtual void Execute(Miner*) = 0;

    // This will execute when the state is exited.
    virtual void Exit(Miner*) = 0;

    virtual ~State() {}
};


#endif //GOLD_MINER_FSM_STATE_H
