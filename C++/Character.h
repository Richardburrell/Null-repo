//
//  Character.h
//  Hazardous
//
//  Created by Ryan Todd on 12/6/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//

#ifndef __Hazardous__Character__
#define __Hazardous__Character__

/* This is the abstract base class Character that will be used to create every type of character oin the game via polymorphism. The class will contain the basic properties shared by every type of character in the game.
 */

namespace CharacterType {
    

    class Character{
        private: //only within the class
        
            double x;   //graph coordinates
            double y;
            double z;
    
            double dx;  //directional coordinates
            double dy;
    
            int health; //health points
        
        protected: //only children can access this constructor
        
            Character(){} //default constructor
        
            Character(const double& x, const double& y, const double& z){
                setX(x);
                setY(y);
                setZ(z);
                this->dx = 0;
                this->dy = -1;
                this->health = 100;
            }
    
        public: //accessed anywhere
        
            //-----------Setters-----------
        
            void setX(const double& x);
            void setY(const double& y);
            void setZ(const double& z);
            void setDx(const double& dx);
            void setDy(const double& dy);
            void setHealth(const int& health);
        
            //-----------Getters------------ (all are inline)
        
            double getX()const {return x;}
            double getY()const {return y;}
            double getZ()const {return z;}
            double getDx()const {return dx;}
            double getDy()const {return dy;}
            int getHealth()const {return health;}
        
            //-----------Virtuals------------
        
            virtual Character* createCharacter() const =0;
        
    }; //end of Character Definition
    
    
    
    
    class Player: public Character{
        
        private:
        
            int health;  //health specific to the player
        
        public:
        
            //---------------Constructor------------
        
            Player(){} //default constructor
        
            Player(const int health, const double x, const double y, const double z):Character(x, y, z), health(health)
                {} //constructor initializes Character base class then initializes the extra player traits
        
            //---------------Setters----------------
        
            void setHealth(const int& health);
        
            //---------------Getters----------------
        
            int getHealth() const {return health;}
        
            //---------------Virtuals---------------
        
            virtual Player* createCharacter() const{
                return (new Player(getX(), getY(), getZ(), getHealth()));
            }
        
    }; //end of Person Definition
    
    
    
    
    class Zombie: public Character{
        
        private:
        
            int health;   //health specific to the zombie
            int iD;       //this will declare which type of zombie will be spawned
        
        public:
        
            //---------------Constructors------------
        
            Zombie(){}    //default constructor
        
            Zombie(const int iD, const int health, const double x, const double y, const double z)
                    :Character(x, y, z), iD(iD), health(health)
                    {} //constructor initailizes Character base class then initializes the extra zombie traits
        
            //---------------Setters-----------------
        
            void setHealth(const int& health);
            void setID(const int& iD);
        
            //---------------Getters-----------------
        
            int getHealth() const {return health;}
            int getID() const {return iD;}
        
            //---------------Virtuals----------------
        
            virtual Zombie* createCharacter() const{
                return (new Zombie(getX(), getY(), getZ(), getID(), getHealth()));
            }
        
    }; //end of Zombie Definition
    
    
    
    
} //end of namespace

#endif /* defined(__Hazardous__Character__) */
