cmake_minimum_required(VERSION 3.15)
project(gold_miner_fsm)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS "${CMAKE_CFLAGS} -fopenmp")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")

add_executable(gold_miner_fsm main.cpp BaseEntity.h Miner.cpp Miner.h State.h EnterMineAndDigForNugget.cpp EnterMineAndDigForNugget.h VisitBankAndDepositGold.cpp VisitBankAndDepositGold.h GoHomeAndSleepTillRested.cpp GoHomeAndSleepTillRested.h QuenchThirst.cpp QuenchThirst.h Location.h StateMachine.h)