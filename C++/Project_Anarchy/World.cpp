//
//  World.cpp
//  Hazardous
//
//  Created by Ryan Todd on 12/11/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//

#include "World.h"

using namespace world;

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
    
    this->root = root = new roomGraph(2, 1, 0, 0, 0, 0, 0, 0, nullptr, nullptr, nullptr, nullptr, nullptr);
    
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
    
    roomGraph* itr = nullptr;
    
    if (getNumRooms() == 1) {
        
        *root->getNorth() = *new roomGraph(0, 1, 0, numRooms, 0, 0, 0, 0, nullptr, root, nullptr, nullptr, nullptr);
        numRooms++;
        
        *root->getSouth() = *new roomGraph(0, 1, 0, numRooms, 0, 0, 0, 0, root, nullptr, nullptr, nullptr, nullptr);
        numRooms++;
        
        *root->getEast() = *new roomGraph(0, 1, 0, numRooms, 0, 0, 0, 0, nullptr, nullptr, root, nullptr, nullptr);
        numRooms++;
        
        *root->getWest() = *new roomGraph(0, 1, 0, numRooms, 0, 0, 0, 0, nullptr, nullptr, nullptr, root, nullptr);
        numRooms++;
        
    }
}
