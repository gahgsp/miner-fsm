//
// Created by Kelvin on 09/01/2020.
//

#include <assert.h>
#include "Miner.h"
#include "GoHomeAndSleepTillRested.h"
#include "MinerGlobalState.h"
#include "StateMachine.h"

Miner::Miner(int id) : BaseEntity(id),
                       m_Location(HOME),
                       m_iGoldCarried(0),
                       m_iMoneyInBank(0),
                       m_iThirst(0),
                       m_iFatigue(0),
                       m_pCurrentState(GoHomeAndSleepTillRested::Instance()){
    // Set up the State Machine.
    m_pStateMachine = new StateMachine<Miner>(this);
    m_pStateMachine->SetCurrentState(GoHomeAndSleepTillRested::Instance());
    m_pStateMachine->SetGlobalState(MinerGlobalState::Instance());
}

Miner::~Miner() {
    delete m_pStateMachine;
}

void Miner::Update() {
    m_iThirst += 1;
    m_pStateMachine->Update();
}

void Miner::ChangeState(State<Miner> *pNewState) {
    // Assert that both states are valid states.
    assert(m_pCurrentState && pNewState);

    // Call the exit method of the current state.
    m_pCurrentState->Exit(this);

    // Change the state to the new state.
    m_pCurrentState = pNewState;

    // Call the entry method for the new state.
    m_pCurrentState->Enter(this);
}

void Miner::ChangeLocation(enum Location location) {
    m_Location = location;
}

Location Miner::Location() {
    return m_Location;
}

void Miner::AddToGoldCarried(int goldNuggetsQty) {
    m_iGoldCarried += goldNuggetsQty;
}

void Miner::IncreaseFatigue() {
    m_iFatigue++;
}

bool Miner::PocketsFull() {
    return m_iGoldCarried >= 100; // TODO: We should make this value dynamic.
}

void Miner::DepositGold(int goldQty) {
    m_iMoneyInBank += goldQty;
}

int Miner::GoldCarried() {
    return m_iGoldCarried;
}

void Miner::SetGoldInPockets(int goldQty) {
    m_iGoldCarried = goldQty;
}

int Miner::Wealth() {
    return m_iMoneyInBank;
}

bool Miner::Fatigued() {
    return m_iFatigue > 20; // TODO: We should make this value dynamic.
}

bool Miner::Thirsty() {
    return m_iThirst > 20; // TODO: We should make this value dynamic.
}

void Miner::DecreaseFatigue() {
    m_iFatigue -= 1;
}

void Miner::BuyAndDrinkAWhiskey() {
    m_iThirst = 0;
    m_iGoldCarried -= 2;
}