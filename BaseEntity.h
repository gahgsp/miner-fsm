//
// Created by Kelvin on 09/01/2020.
//

#ifndef GOLD_MINER_FSM_BASEENTITY_H
#define GOLD_MINER_FSM_BASEENTITY_H

class BaseEntity {
private:

    // Unique ID that every game entity must have.
    int m_ID;

    // Generates the next valid ID value for an entity.
    // Every time an entity is instantiated, the value is updated.
    static int m_iNextValidID;

    // Called within the constructor to ensure that only valid IDs are provided.
    void SetID(int val);

public:

    BaseEntity(int id) {
        SetID(id);
    }

    virtual ~BaseEntity() {}

    // All entities must implement an update function.
    virtual void Update() = 0; // This "= 0" means that subclasses have to implement this function.

    int ID() { return m_ID; }
};

#endif //GOLD_MINER_FSM_BASEENTITY_H
