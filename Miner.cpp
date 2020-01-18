//
// Created by Kelvin on 09/01/2020.
//

#include <assert.h>
#include "Miner.h"
#include "GoHomeAndSleepTillRested.h"
#include "StateMachine.h"

Miner::Miner(int id) : BaseEntity(id),
                       m_Location(HOME),
                       m_iGoldCarried(0),
                       m_iMoneyInBank(0),
                       m_iThirst(0),
                       m_iFatigue(0) {
    // Set up the State Machine.
    m_pStateMachine = new StateMachine<Miner>(this);
    m_pStateMachine->SetCurrentState(GoHomeAndSleepTillRested::Instance());
}

Miner::~Miner() {
    delete m_pStateMachine;
}

void Miner::Update() {
    m_iThirst += 1;
    m_pStateMachine->Update();
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
    return m_iGoldCarried >= MaxGoldNuggets;
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
    return m_iFatigue >= MaxTirednessLevel;
}

bool Miner::Thirsty() {
    return m_iThirst >= MaxThirstyLevel;
}

void Miner::DecreaseFatigue() {
    m_iFatigue -= 1;
}

void Miner::BuyAndDrinkAWhiskey() {
    m_iThirst = 0;
    m_iGoldCarried -= 2;
}