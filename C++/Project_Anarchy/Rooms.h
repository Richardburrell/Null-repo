//
//  Rooms.h
//  Hazardous
//
//  Created by Ryan Todd on 12/6/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//

#ifndef __Hazardous__Rooms__
#define __Hazardous__Rooms__

#include "Character.h"
#include "Lists.h"

using namespace CharacterType;
using namespace LinkedLists;

/*
    this is a namespace used to create nodes for a graph. Each graph node contains a few status iVars, a counter for the amount of nodes in the list along with a head node to use when creating a list, then four pointers used to point at different graph nodes as a path
*/

namespace Rooms {
    
    enum isActive{OFFLINE, STANDBY, ONLINE};
    
    class roomGraph{
        
        private:
        
            int state;              //int to check status based on isActive (0 offline, 1 standBy, 2 online)
            bool marked;            //bool to protect against cycling errors
            int numZombieNodes;     //count to keep track of Zombies in the node
            int nodeiD;             //used to identify which node is being dealt with
        
            roomGraph* north;       //pointers used to navigate the graph in four directions
            roomGraph* south;
            roomGraph* east;
            roomGraph* west;
        
            ListTracker* head;      //points to the first node of the list of zombies currently in this node
        
        public:
        
            //-------------------Constructors------------------
        
            roomGraph();        //default constructor
        
            roomGraph(const int state, const bool marked, const int numZombieNodes, const int nodeiD,
                      roomGraph* north, roomGraph* south, roomGraph* east, roomGraph* west,
                      ListTracker* head);                 //constructor used when adding a node to the graph
        
            //-------------------Setters-----------------------
        
            void setState(const int& state);
            void setMarked(const bool& marked);
            void setNumZombieNodes(const int& numZombieNodes);
            void setNodeId(const int& nodeiD);
        
            //-------------------Getters-----------------------
        
            int getState() const {return state;}
            bool getMarked() const {return marked;}
            int getNumZombieNodes() const {return numZombieNodes;}
            int getNodeId() const {return nodeiD;}
        
        
            //-------------------List instructions-------------
        
            void appendZombie(ListTracker& node);            //adds a zombie to the last node in the list
            bool deleteZombie();            //traverses the list and deletes a specific node
            void deleteZombieList();        //starts at head and deletes every node in order
            void copyZombie(Zombie& cpEnemy);       //copies a node from the list to be sent to another
        
    };// end roomGraph
    
} // end of Rooms namespace

#endif /* defined(__Hazardous__Rooms__) */
