//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_ENTERMINEANDDIGFORNUGGET_H
#define GOLD_MINER_FSM_ENTERMINEANDDIGFORNUGGET_H


#include "State.h"

class EnterMineAndDigForNugget : public State<Miner> {
private:

    EnterMineAndDigForNugget() {};

public:

    // Singleton pattern.
    static EnterMineAndDigForNugget* Instance();

    virtual void Enter(Miner* pMiner);

    virtual void Execute(Miner* pMiner);

    virtual void Exit(Miner* pMiner);
};


#endif //GOLD_MINER_FSM_ENTERMINEANDDIGFORNUGGET_H
