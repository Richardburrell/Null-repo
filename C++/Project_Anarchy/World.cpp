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
		itrNorth = itrNorth->north;
        
        itrSouth->south = new roomGraph(0, true, 0, numRooms, root, nullptr, nullptr, nullptr, nullptr);
        numRooms++;
		itrSouth = itrSouth->south;
        
        itrEast->east = new roomGraph(0, true, 0, numRooms, nullptr, nullptr, root, nullptr, nullptr);
        numRooms++;
		itrEast = itrEast->east;
        
        itrWest->west = new roomGraph(0, true, 0, numRooms, nullptr, nullptr, nullptr, root, nullptr);
        numRooms++;
		itrWest = itrWest->west;
        
    }else{
		if(itrNorth->north == nullptr){
			itrNorth->north = new roomGraph(0, true, 0, numRooms, nullptr, itrNorth, nullptr, nullptr, nullptr);
			numRooms++;

			if(itrNorth->east == nullptr){
				itrNorth->east = new roomGraph(0, true, 0, numRooms, nullptr, nullptr, nullptr, itrNorth, nullptr);
				numRooms++;
			}

			if(itrNorth->west == nullptr){
				itrNorth->west = new roomGraph(0, true, 0, numRooms, nullptr, nullptr, itrNorth, nullptr, nullptr);
				numRooms++;
			}

		}

		if(itrSouth->south == nullptr){
			itrSouth->south = new roomGraph(0, true, 0, numRooms, itrSouth, nullptr, nullptr, nullptr, nullptr);
			numRooms++;

			if(itrSouth->east == nullptr){
				itrSouth->east = new roomGraph(0, true, 0, numRooms, nullptr, nullptr, nullptr, itrSouth, nullptr);
				numRooms++;
			}

			if(itrSouth->west == nullptr){
				itrSouth->west = new roomGraph(0, true, 0, numRooms, nullptr, nullptr, itrSouth, nullptr, nullptr);
				numRooms++;
			}
		}

		if(itrEast->east == nullptr){
			itrEast->east = new roomGraph(0, true, 0, numRooms, itrNorth->east, itrSouth->east, nullptr, itrEast, nullptr);
			itrNorth->east->south = itrEast;
			itrSouth->east->north = itrEast;
			numRooms++;
		}

		if(itrWest->west == nullptr){
			itrWest->west = new roomGraph(0, true, 0, numRooms, itrNorth->west, itrSouth->west, itrWest, nullptr, nullptr);
			itrNorth->west->south = itrWest;
			itrSouth->west->north = itrWest;
			numRooms++;
		}

	}
}
