//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_MINER_H
#define GOLD_MINER_FSM_MINER_H

#include "BaseEntity.h"
#include "State.h"
#include "StateMachine.h"
#include "Location.h"

// The amount of gold the miner can carry.
const int MaxGoldNuggets = 3;
// Above this level the miner is sleepy.
const int MaxTirednessLevel = 5;
// Above this level the miner is thirsty.
const int MaxThirstyLevel = 5;

class Miner : public BaseEntity {
private:

    // A pointer to the State Machine.
    StateMachine<Miner>* m_pStateMachine;

    // A pointer to the current state.
    State<Miner>* m_pCurrentState;

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

    Miner(int id);

    ~Miner();

    // This must be implemented.
    void Update();

    StateMachine<Miner>* GetFSM() const { return m_pStateMachine; }

    void ChangeLocation(enum Location location);

    // Returns the location where the miner is currently situated.
    Location Location();

    void AddToGoldCarried(int goldNuggetsQty);

    void IncreaseFatigue();

    bool PocketsFull();

    bool Thirsty();

    void DepositGold(int goldQty);

    int GoldCarried();

    void SetGoldInPockets(int goldQty);

    int Wealth();

    bool Fatigued();

    void DecreaseFatigue();

    void BuyAndDrinkAWhiskey();
};

#endif //GOLD_MINER_FSM_MINER_H
