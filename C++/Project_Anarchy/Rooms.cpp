//
//  Rooms.cpp
//  Hazardous
//
//  Created by Ryan Todd on 12/6/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//

#include "Rooms.h"

using namespace Rooms;

//--------------------roomGraphs implementation---------------------------

//---------Constructors-----------

roomGraph::roomGraph (){     //default constructor used when initially creating the map to create the first node
    
    state = ONLINE;
    marked = 0;
    numZombieNodes = 0;
    nodeiD = 0;
    
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
    
    head = nullptr;
    
}

roomGraph::roomGraph (const int state, const bool marked, const int numZombieNodes, const int nodeiD,
                      roomGraph* north, roomGraph* south, roomGraph* east, roomGraph* west,
                      ListTracker* head)
                        :north(north), south(south), east(east), west(west), head(head){                 //constructor used when adding a node to the graph

    setState(state);
    setMarked(marked);
    setNumZombieNodes(numZombieNodes);
    setNodeId(nodeiD);
    

}

//---------Setters-----------------

void roomGraph::setState(const int& state){
    this->state = (state >= 0 && state < 3)? state : 0;
}

void roomGraph::setMarked(const bool& marked){
    this->marked = (marked == 0 || marked == 1)? marked : 0;
}

void roomGraph::setNumZombieNodes(const int& numZombieNodes){
    this->numZombieNodes = (numZombieNodes == 0)? numZombieNodes : 0;
}

void roomGraph::setNodeId(const int& nodeiD){
    this->nodeiD = nodeiD;
}

//----------List Instructions-------

void roomGraph::appendZombie(Zombie& newZombie){     //appends a Zombie node to the end of the list
    
}

void roomGraph::deleteZombie(Zombie delZombie){     //this will traverse a list and delete a specific node
    
    
}

void roomGraph::deleteZombieList(){             //deletes a node's entire list of Zombies
    ListTracker* itr = nullptr;
    
    for (int i = 0; i < getNumZombieNodes(); i++) {
        itr = head;
        head = head->next;
        itr->next = nullptr;
        delete itr;
    }
    
}

void roomGraph::copyZombie(Zombie& cpEnemy, ListTracker* copyHead){    //this will copy a zombie from one list to another
    
    ListTracker* itr = nullptr;
    
    for (itr = head; itr != nullptr; itr = itr->next) {
        
        if (itr->getEnemy() == cpEnemy) {
            for (ListTracker* itr2 = copyHead; itr2 != nullptr; itr2 = itr2->next) {
                if (itr2->next == nullptr) {
                    itr2->next = new ListTracker(cpEnemy, nullptr);
                }
            }
        }
    }
    
}

void roomGraph::exchangeZombie(Zombie& leavingZombie){          //this method is for when Zombies leave a node they can be exchanged to the other via copyZombie then deleted via deleteZombie
    
    ListTracker* itr = nullptr;
    
    for (itr = head; itr != nullptr; itr = itr->next) {
        if (itr->getEnemy() == leavingZombie) {
            Zombie temp = itr->getEnemy();
            copyZombie(temp, head);
            deleteZombie(itr->getEnemy());
        }
        
    }
}
