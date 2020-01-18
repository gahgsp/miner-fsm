//
// Created by Kelvin on 12/01/2020.
//

#ifndef GOLD_MINER_FSM_STATEMACHINE_H
#define GOLD_MINER_FSM_STATEMACHINE_H

#include <cstddef>
#include <assert.h>
#include "State.h"

template <class BaseEntity>
class StateMachine {
private:

    // A pointer to the entity that owns this instance.
    BaseEntity* m_pOwner;

    State<BaseEntity>* m_pCurrentState;

public:
    StateMachine(BaseEntity* owner): m_pOwner(owner), m_pCurrentState(NULL) {}

    // Methods to initialize the FSM.
    void SetCurrentState(State<BaseEntity>* currState) {
        m_pCurrentState = currState;
    }

    // Call this to update the FSM.
    void Update() const {
        // Same for the current state.
        if (m_pCurrentState) {
            m_pCurrentState->Execute(m_pOwner);
        }
    }

    // Change to a new state.
    void ChangeState(State<BaseEntity>* pNewState) {
        assert(pNewState && "<StateMachine::ChangeState>: Trying to change to a null state.");

        // Call the exit method of the current state.
        m_pCurrentState->Exit(m_pOwner);

        // Change the current state to the new state.
        m_pCurrentState = pNewState;

        // Call the entry method of the new state.
        m_pCurrentState->Enter(m_pOwner);
    }

    // Getters.
    State<BaseEntity>* CurrentState() const { return m_pCurrentState; }

    // Checks if the the current state is equal to the state passed as a parameter.
    bool IsInState(const State<BaseEntity>& state) const;
};

#endif //GOLD_MINER_FSM_STATEMACHINE_H
