//
//  World.h
//  Hazardous
//
//  Created by Ryan Todd on 12/11/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//

#ifndef __Hazardous__World__
#define __Hazardous__World__

#include "Rooms.h"
#include "Character.h"

using namespace Rooms;
using namespace CharacterType;


#endif /* defined(__Hazardous__World__) */

/*
 This is the class that will contain all of the properties of our map that is uased to play on.
 The scene  will use this class to run all other objects in the game.
 */

namespace world {
    
    class Map{
        
    private:
        
        roomGraph* root;
        Player* human;
        ListTracker* head;
        Zombie* enemy;
        int numRooms;
        
    public:
        
        //----------Constructors--------------
        
        Map();
        Map(roomGraph* root, Player* human, ListTracker* head, Zombie* enemy);
        
        //----------Getters-------------------
        
        roomGraph* getRoot() {return root;}
        Player* getHuman() {return human;}
        ListTracker* getHead() {return head;}
        Zombie* getEnemy() {return enemy;}
        int getNumRooms() {return numRooms;}
        
        //----------Setters-------------------
        
        void setRoot(roomGraph &root);
        void setHuman(Player &human);
        void setHead(ListTracker &head);
        void setEnemy(Zombie &enemy);
        void setNumRooms(int numRooms);
        
        //----------Functionality-------------
        
        void buildStation();
        
        
        
    };//end of class Map
    
    
}// end of namespace World