//
// Created by Kelvin on 14/01/2020.
//

#include "MinerGlobalState.h"

void MinerGlobalState::Enter(Miner *miner) {

}

void MinerGlobalState::Execute(Miner *miner) {

}

void MinerGlobalState::Exit(Miner *miner) {

}

MinerGlobalState* MinerGlobalState::Instance() {
    static MinerGlobalState instance;
    return &instance;
}