//
//  Rooms.cpp
//  Hazardous
//
//  Created by Ryan Todd on 12/6/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//

#include "Rooms.h"
#define nullptr 0


using namespace Rooms;


//--------------------Sector Implementation---------------------------


//---------Setters----------------

void Sector::setMinX(double& minX){
    this->minX = minX;
}

void Sector::setMinY(double& minY){
    this->minY = minY;
}

void Sector::setMaxX(double& maxX){
    this->maxX = maxX;
}

void Sector::setMaxY(double& maxY){
    this->maxY = maxY;
}

//---------Checkers---------------

bool Sector::checkX(double& x){
    return (x < getMaxX() && x > getMinX());
}

bool Sector::checkY(double& y){
    return (y < getMaxY() && y > getMinY());
}

//--------------------End of Sector-----------------------------------






//--------------------roomGraphs implementation---------------------------

//---------Constructors-----------

roomGraph::roomGraph (){     //default constructor used when initially creating the map to create the first node
    
    Sector();
    
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

roomGraph::roomGraph (const int state, const bool marked, const int numZombieNodes,
                      const int nodeiD, const double minX, const double
                      minY, const double maxX, const double maxY,
                      roomGraph* north, roomGraph* south, roomGraph* east, roomGraph* west,
                      ListTracker* head):north(north), south(south), east(east), west(west), head(head){                 //constructor used when adding a node to the graph
                            
    Sector(minX, minY, maxX, maxY);

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
    ListTracker* itr = nullptr;
	for (itr = head; itr != nullptr; itr = itr-> next){
		itr-> next = new ListTracker (newZombie, nullptr);
<<<<<<< HEAD
	}
=======
    }
>>>>>>> 1fab815662f198da09ed6b1ae7d05a9406ee0f92
}

void roomGraph::deleteZombie(Zombie delZombie){     //this will traverse a list and delete a specific node
    ListTracker* before = head;
	ListTracker* itr = nullptr;
	for (itr = head; itr != nullptr; itr = itr-> next){
		if (head->getEnemy() == delZombie){
			head = head->next;
			itr-> next = nullptr;					//this is the special case where the zombie is the first in the list
			delete itr;
		}
		else if (itr->getEnemy() == delZombie){
			before = head-> next;					//this moves the before pointer to the next item in the list allowing us to delete itr
			itr-> next = nullptr;
			delete itr;
		}
	before = itr;									
	}
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

//------------------------End of roomGraph-----------------------





