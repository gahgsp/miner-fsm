//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_MINER_H
#define GOLD_MINER_FSM_MINER_H

#include "BaseEntity.h"
#include "State.h"
#include "StateMachine.h"
#include "Location.h"

//------------------------------- Constants --------------------------------
//
//--------------------------------------------------------------------------

// The amount of gold the miner can carry.
const int MaxGoldNuggets = 3;
// Above this level the miner is sleepy.
const int MaxTirednessLevel = 5;
// Above this level the miner is thirsty.
const int MaxThirstyLevel = 5;

//------------------------------- Miner -----------------------------------
// The class with the miner definitions and properties.
//--------------------------------------------------------------------------

class Miner : public BaseEntity {
private:

    // A pointer to the State Machine.
    StateMachine<Miner> *m_pStateMachine;

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

    //--------------------------- State Machine ----------------------------------
    // Defines all the implementations that will effect the miner's state machine.
    //----------------------------------------------------------------------------

    void ChangeLocation(enum Location location);

    // Returns the location where the miner is currently situated.
    Location Location();

    StateMachine<Miner> *GetFSM() const { return m_pStateMachine; }

    //--------------------------- Mining Behavior ------------------------------
    // All the methods to handle the mining behavior (EnterMineAndDigForNugget).
    //--------------------------------------------------------------------------

    void AddToGoldCarried(int goldNuggetsQty);

    void SetGoldInPockets(int goldQty);

    void IncreaseFatigue();

    int GoldCarried();

    bool PocketsFull();

    //--------------------------- Banking Behavior ------------------------------
    // All the methods to handle the banking behavior (VisitBankAndDepositGold).
    //---------------------------------------------------------------------------

    void DepositGold(int goldQty);

    int Wealth();

    //--------------------------- Thirst Behavior ------------------------------
    // All the methods to handle the banking behavior (QuenchThirst).
    //--------------------------------------------------------------------------

    void BuyAndDrinkAWhiskey();

    bool Thirsty();

    //--------------------------- Rest Behavior ---------------------------------
    // All the methods to handle the resting behavior (GoHomeAndSleepTillRested).
    //---------------------------------------------------------------------------

    bool Fatigued();

    void DecreaseFatigue();

};

#endif //GOLD_MINER_FSM_MINER_H
