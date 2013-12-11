//
//  World.cpp
//  Hazardous
//
//  Created by Ryan Todd on 12/11/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//

#include "World.h"

using namespace world;
using namespace Rooms;
using namespace CharacterType;

//------------------------------Map Implementation------------------------------

//----------Constructors----------

Map::Map(){
    root = nullptr;
    human = nullptr;
    head = nullptr;
    enemy = nullptr;
    numRooms = 0;
}

Map::Map(roomGraph* root, Player* human, ListTracker* head, Zombie* enemy){
    
    this->root = root = new roomGraph(2, true, 0, 0, nullptr, nullptr, nullptr, nullptr, nullptr);
    
    this->human = human = new Player(0, 0, 0, 5);
    
    this->head = head = new ListTracker();
    
    setNumRooms(1);
}




//---------Setters--------------

void Map::setRoot(roomGraph &root){
    this->root = &root;
}

void Map::setHuman(Player &human){
    this->human = &human;
}

void Map::setHead(ListTracker &head){
    this->head = &head;
}

void Map::setNumRooms(int numRooms){
    this->numRooms = numRooms;
}






//---------Functionality---------

void Map::buildStation(){
    
	roomGraph* itrNorth = root;
	roomGraph* itrSouth = root;
	roomGraph* itrEast = root;
	roomGraph* itrWest = root;
    
    if (getNumRooms() == 1) {
        
		itrNorth->north = new roomGraph(0, true, 0, numRooms, nullptr, root, nullptr, nullptr, nullptr);
        numRooms++;
        
        root->south = new roomGraph(0, true, 0, numRooms, root, nullptr, nullptr, nullptr, nullptr);
        numRooms++;
        
        root->east = new roomGraph(0, true, 0, numRooms, nullptr, nullptr, root, nullptr, nullptr);
        numRooms++;
        
        root->west = new roomGraph(0, true, 0, numRooms, nullptr, nullptr, nullptr, root, nullptr);
        numRooms++;
        
    }
}
