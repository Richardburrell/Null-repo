//
//  Lists.h
//  Hazardous
//
//  Created by Ryan Todd on 12/6/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//

#ifndef __Hazardous__Lists__
#define __Hazardous__Lists__
#include "Character.h"

using namespace CharacterType;

/* this is a namespace used to create a list of Zombies Currently created. It contains a zombie object and a pointer to the next node in the list
 */

namespace LinkedLists {
    
    
    class ListTracker{
        
        private:
            Zombie enemy;               //Zombie object in the list
        
        public:
        
            ListTracker* next;          //pointer to next ListTracker node
        
            //---------------Constructors-------------------
        
            ListTracker(){}             //default constructor
            ListTracker(Zombie enemy, ListTracker* next):enemy(enemy), next(next){} //new Zombie node constructor
        
            //---------------Getters------------------------
        
            Zombie getEnemy() const {return enemy;}
        
            //-------------------Overloaded Operator-----------
        
            ListTracker operator =(const ListTracker& assignThis) { return *this; }
        
    };
    
}// end of namespace LinkedLists

#endif /* defined(__Hazardous__Lists__) */
