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
    
    class Sector{
        /*
            this class creates a sector or a rectangle area on the x,y plane that is applied as a room
        */
        
        private:
        
            //-----Points-----
            double minX;
            double minY;
            double maxX;
            double maxY;
        
        public:
        
            //------------------Constructors------------------
        
            Sector():minX(1.0), minY(1.0), maxX(1.0), maxY(1.0){} //default constructor
        
            Sector(double minX, double minY, double maxX, double maxY)
                :minX(minX), minY(minY), maxX(maxX), maxY(maxY){} //constructor for specific sector
        
            //------------------Setters-----------------------
        
            void setMinX(double& minX);
            void setMinY(double& minY);
            void setMaxX(double& maxX);
            void setMaxY(double& maxY);
        
            //------------------Getters-----------------------
        
            double getMinX() const {return minX;}
            double getMinY() const {return minY;}
            double getMaxX() const {return maxX;}
            double getMaxY() const {return maxY;}
        
            //------------------Checks------------------------
        
            bool checkX(double& x);
            bool checkY(double& y);
        
        
    }; //end of Sector class
    
    class roomGraph : public Sector{
        
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
                      const double minX, const double
                      minY, const double maxX, const double maxY,
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
            roomGraph* getNorth() {return north;}
            roomGraph* getEast() {return east;}
            roomGraph* getSouth() {return south;}
            roomGraph* getWest() {return west;}
        
        
            //-------------------List instructions-------------
        
            void appendZombie(Zombie& newZombie);            //adds a zombie to the last node in the list
            void deleteZombie(Zombie delZombie);            //traverses the list and deletes a specific node
            void deleteZombieList();        //starts at head and deletes every node in order
            void copyZombie(Zombie& cpEnemy, ListTracker* copyHead);       //copies a node from the list to be sent to another
            void exchangeZombie(Zombie& leavingZombie);
        
        //-----------------Overloaded------------------------
        
        roomGraph operator =(roomGraph assignThis){return *this;}
        
    };// end roomGraph
    
} // end of Rooms namespace

#endif /* defined(__Hazardous__Rooms__) */
