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

    // A record of the last state the entity was in.
    State<BaseEntity>* m_pPreviousState;

    // This state logic is called every time the FSM is updated.
    State<BaseEntity>* m_pGlobalState;

public:
    StateMachine(BaseEntity* owner): m_pOwner(owner), m_pCurrentState(NULL), m_pPreviousState(NULL), m_pGlobalState(NULL) {}

    // Methods to initialize the FSM.
    void SetCurrentState(State<BaseEntity>* currState) {
        m_pCurrentState = currState;
    }
    void SetGlobalState(State<BaseEntity>* glbState) {
        m_pGlobalState = glbState;
    }
    void SetPreviousState(State<BaseEntity>* prevState){
        m_pPreviousState = prevState;
    }

    // Call this to update the FSM.
    void Update() const {
        // If a global state exists, call it's execute method.
        if (m_pGlobalState) {
            m_pGlobalState->Execute(m_pOwner);
        }

        // Same for the current state.
        if (m_pCurrentState) {
            m_pCurrentState->Execute(m_pOwner);
        }
    }

    // Change to a new state.
    void ChangeState(State<BaseEntity>* pNewState) {
        assert(pNewState && "<StateMachine::ChangeState>: Trying to change to a null state.");

        // Keep a record of the previous state.
        m_pPreviousState = m_pCurrentState;

        // Call the exit method of the current state.
        m_pCurrentState->Exit(m_pOwner);

        // Change the current state to the new state.
        m_pCurrentState = pNewState;

        // Call the entry method of the new state.
        m_pCurrentState->Enter(m_pOwner);
    }

    // Change state back to the previous state.
    void RevertToPreviousState() {
        ChangeState(m_pPreviousState);
    }

    // Getters.
    State<BaseEntity>* CurrentState() const { return m_pCurrentState; }
    State<BaseEntity>* GlobalState() const { return m_pGlobalState; }
    State<BaseEntity>* PreviousState() const { return m_pPreviousState; }

    // Checks if the the current state is equal to the state passed as a parameter.
    bool IsInState(const State<BaseEntity>& state) const;
};

#endif //GOLD_MINER_FSM_STATEMACHINE_H
