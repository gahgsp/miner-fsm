//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_MINER_H
#define GOLD_MINER_FSM_MINER_H

#include "BaseEntity.h"
#include "State.h"
#include "Location.h"

class Miner : public BaseEntity {
private:

    // A pointer to the current state.
    State* m_pCurrentState;

    // The place where the miner is currently situated.
    Location m_Location;

    // How many gold nuggets the miner is currently holding.
    int m_iGoldCarried;

    // How much money the miner has deposited in his bank account.
    int m_iMoneyInBank;

    // The higher the value, the thirstier the miner.
    int m_iThirst;

    // The higher the value, the more tired the miner is.
    int m_iFatigue;

public:

    Miner(int ID);

    // This must be implemented.
    void Update();

    // This method changes the current state to the new state.
    void ChangeState(State* pNewState);

    void ChangeLocation(enum Location location);

    // Returns the location where the miner is currently situated.
    Location Location();

    void AddToGoldCarried(int goldNuggetsQty);

    void IncreaseFatigue();

    bool PocketsFull();

    bool Thirsty();
};

#endif //GOLD_MINER_FSM_MINER_H
