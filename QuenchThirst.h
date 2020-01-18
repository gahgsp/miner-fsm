//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_QUENCHTHIRST_H
#define GOLD_MINER_FSM_QUENCHTHIRST_H


#include "State.h"
#include "Miner.h"

class QuenchThirst : public State<Miner> {
private:

    QuenchThirst() {}

public:

    // Singleton pattern.
    static QuenchThirst *Instance();

    void Enter(Miner *miner);

    void Execute(Miner *miner);

    void Exit(Miner *miner);
};


#endif //GOLD_MINER_FSM_QUENCHTHIRST_H
