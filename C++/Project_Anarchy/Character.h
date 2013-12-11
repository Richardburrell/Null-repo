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
        
        Character():x(0), y(0), z(0), dx(0), dy(-1){} //default constructor
        
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
        
            Player():Character(), health(5){} //default constructor
        
            Player(const double x, const double y, const double z, const int health):Character(x, y, z), health(health)
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
        
            Zombie():Character(), health(6), iD(0){}    //default constructor
        
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
                return (new Zombie(getID(), getHealth(), getX(), getY(), getZ()));
            }
        
<<<<<<< HEAD
			bool operator == (Zombie& enemy){
				return(this->iD == enemy.iD);
			}
=======
            //--------------Overloaded Operators-----
        
            bool operator ==(const Zombie& assignThis);
        
>>>>>>> 1fab815662f198da09ed6b1ae7d05a9406ee0f92
    }; //end of Zombie Definition
    
    
    
    
} //end of namespace


//************************************************************************************************



namespace Inventory {
    
    /* namespace containg the classes for a players in ventory ranging from resources, guns, and gadgets
    */
    
    class Item{                                                     //abstract class - cannot be accessed
        
        private:
        
            int itemId;
            int numOfItemHeld;
        
        protected:
        
            //--------------Constructors-------------
        
            Item():itemId(0), numOfItemHeld(1){}    //default constructor
        
            Item(int itemId, int numOfItemHeld):itemId(itemId),     //constructor for specific item
                numOfItemHeld(numOfItemHeld){}
        
        public:
        
            //--------------Setters------------------
        
            void setItemId(int& itemId);
            void setNumOfItemHeld(int& numOfItemHeld);
        
            //--------------Getters------------------
        
            int getItemId() const {return itemId;}
            int getNumOfItemHeld() const {return numOfItemHeld;}
        
            //--------------Virtuals-----------------
            virtual Item* createItem() const =0;
        
    }; //end of Item class
    
    
    
    
    
    class Resources: public Item{
        
        private:
        
            double x;
            double y;
            double z;
        
        public:
        
            //--------------Constructors-----------------
        
            Resources():Item(), x(0), y(0), z(0){}  //default constructor
        
            Resources(double x, double y, double z, int iD, int numOfItemHeld)
                    :Item(iD, numOfItemHeld), x(x), y(y), z(z)  //constructor for specific resource
                    {}
        
            //--------------Setters----------------------
        
            void setX(double& x);
            void setY(double& y);
            void setZ(double& z);
        
            //--------------Getters----------------------
        
            double getX() const {return x;}
            double getY() const {return y;}
            double getZ() const {return z;}
        
            //--------------Virtuals---------------------
        
            virtual Resources* createItem() const{
                return (new Resources(getX(), getY(), getZ(), getItemId(), getNumOfItemHeld()));
            }
        
    }; //end of Resources class
    
    
    
    
    
    class Guns: public Item{
        
        private:
        
            int damage;                                             //amount of damage
            int ammoType;
        
        public:
        
            //-------------Constructors-----------------
        
            Guns():Item(), damage(2), ammoType(getItemId()){}                                                //default gun constructor
        
            Guns(int damage, int ammoType, int iD, int numOfItemHeld)
                :Item(iD, numOfItemHeld), damage(damage),        //constructor to create a specific  gun
                ammoType(ammoType){}
        
            //-------------Setters----------------------
        
            void setAmmoType(int ammoType);
            void setDamage(int damage);
        
            //-------------Getters----------------------
        
            int getAmmoType() const {return ammoType;}
            int getDamage() const {return damage;}
        
            //-------------Virtuals----------------------
        
            virtual Guns* createItem() const{
                return (new Guns(getDamage(), getAmmoType(), getItemId(), getNumOfItemHeld()));
            }
    }; //end of Guns class
    
    
    
    
    
    class Gadgets: public Item{
        
        private:
        
            int energyLevel;
            int damage;
        
        public:
        
            //-------------Constructors-----------------
        
            Gadgets():Item(), energyLevel(100), damage(getItemId()){}                                               //default gadget constructor
        
            Gadgets(int damage, int energyLevel, int iD, int numOfItemHeld)
                    :Item(iD, numOfItemHeld), damage(damage),        //constructor to create a specific  gadget
                    energyLevel(energyLevel){}
        
            //-------------Setters----------------------
        
            void setEnergyLevel(int energyLevel);
            void setDamage(int damage);
        
            //-------------Getters----------------------
        
            int getEnergyLevel() const {return energyLevel;}
            int getDamage() const {return damage;}
        
            //-------------Virtuals----------------------
        
            virtual Gadgets* createItem() const{
                return (new Gadgets(getDamage(), getEnergyLevel(), getItemId(), getNumOfItemHeld()));
            }

        
    }; //end of Gadgets class
    
    
    
    
    template <typename T>
    
    class Pack{                               //playes inventory pack object
        
        private:
        
            T* pack[3][3] = {nullptr};        //array of type T pointers to items
            int numOfElementsUsed;            //number of elements containing an item
        
        public:
        
            //--------------Constructors------------------
        
            Pack(){       //default constructor
                setNumOfElementsUsed(0);
            }
        
            //--------------Setters-----------------------
        
            void setNumOfElementsUsed(int numOfElementsUsed){this->numOfElementsUsed = numOfElementsUsed;}
        
            //--------------Getters-----------------------
        
            int getNumOfElementsUsed() const {return numOfElementsUsed;}
        
            //--------------Pack Instructions-------------
        
            void addItem(T& item, int row, int column){
                pack[row][column] = item;
            }
        
            void deleteItem(T& item, int row, int column){
                delete pack[row][column];
            }
        
            void swapItems(T& item1, T& item2, int row1, int column1,
                           int row2, int column2){
                
                pack[row1][column1] = item2;
                pack[row2][column2] = item1;
                
            }
        
    }; //end of Pack class
    
    
    
    
    template <typename T>
    
    class Bin{                             //cube storage bin object
        
        private:
        
        T* bin[5][5] = {nullptr};
        int numOfElementsUsed;            //number of elements containing an item
        
        public:
        
            //--------------Constructors------------------
        
            Bin(){       //default constructor
                setNumOfElementsUsed(0);
            }
        
            //--------------Setters-----------------------
        
            void setNumOfElementsUsed(int numOfElementsUsed){this->numOfElementsUsed = numOfElementsUsed;}
        
            //--------------Getters-----------------------
        
            int getNumOfElementsUsed() const {return numOfElementsUsed;}
        
            //--------------Bin Instructions--------------
        
            void addItem(T& item, int row, int column){
                bin[row][column] = item;
            }
        
            void deleteItem(T& item, int row, int column){
                delete bin[row][column];
            }
        
            void swapItems(T& item1, T& item2, int row1, int column1,
                           int row2, int column2){
                
                bin[row1][column1] = item2;
                bin[row2][column2] = item1;
            
            }

        
    }; //end of Bin class
}

#endif /* defined(__Hazardous__Character__) */
