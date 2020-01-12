//
// Created by Kelvin on 09/01/2020.
//

#include "QuenchThirst.h"

void QuenchThirst::Enter(Miner *miner) {

}

void QuenchThirst::Execute(Miner *miner) {

}

void QuenchThirst::Exit(Miner *miner) {

}

QuenchThirst* QuenchThirst::Instance() {
    static QuenchThirst instance;
    return &instance;
}