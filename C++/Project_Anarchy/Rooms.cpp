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

void roomGraph::appendZombie(ListTracker& node){
    
}

bool roomGraph::deleteZombie(){     //this will traverse a list and delete a specific node and if a node has been deleted return true
    
    bool ret_Val = false;
    
    
    return ret_Val;
}

void roomGraph::deleteZombieList(){
    ListTracker* itr = nullptr;
    
    for (int i = 0; i < getNumZombieNodes(); i++) {
        itr = head;
        head = head->next;
        itr->next = nullptr;
        delete itr;
    }
    
}

void roomGraph::copyZombie(Zombie& cpEnemy){    //this will copy a node from one list to another
    
    ListTracker* itr = nullptr;
    
    for (itr = head; itr != nullptr; itr = itr->next) {
        
        if (itr->getEnemy() == cpEnemy) {
            for (ListTracker* itr2 = head; itr2 != nullptr; itr2 = itr2->next) {
                if (itr->next == nullptr) {
                    itr->next = new ListTracker(cpEnemy, nullptr);
                }
            }
        }
    }
    
}