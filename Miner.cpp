//
// Created by Kelvin on 09/01/2020.
//

#include <assert.h>
#include "Miner.h"

void Miner::Update() {
    m_iThirst += 1;

    if (m_pCurrentState) {
        m_pCurrentState->Execute(this);
    }
}

void Miner::ChangeState(State *pNewState) {
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
    return m_iGoldCarried >= 100; // We should make this value dinamic.
}