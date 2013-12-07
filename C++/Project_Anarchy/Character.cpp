//
//  Character.cpp
//  Hazardous
//
//  Created by Ryan Todd on 12/6/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//
# include "Character.h"
using namespace CharacterType;
using namespace Inventory;

//---------------Character Implementation-----------------

//----------Setters-----------

void Character::setX(const double& x){ //is bogus right now but will use that statment to check x as a valid point
    this->x = (x < 0)? x : 0;
}

void Character::setY(const double& y){ //is bogus right now but will use that statment to check y as a valid point
    this->y = (y < 0)? y : 0;
}

void Character::setZ(const double& z){ //is bogus right now but will use that statment to check z as a valid point
    this->z = (z < 0)? z : 0;
}

void Character::setDx(const double& dx){ //is bogus right now but will use that statment to check dx as a valid direction
    this->dx = (dx == 1 || dx == 0 || dx == -1 )? dx : 0;
}

void Character::setDy(const double& dy){ //is bogus right now but will use that statment to check dy as a valid direction
    this->dy = (dy == 1 || dy == 0 || dy == -1 )? dy : 0;
}

void Character::setHealth(const int& health){ //is bogus right now but will use that statment to validate healthpoints
    this->health = (health > 0)? health : 3;
}

//---------------End of Character---------------------------






//---------------Player Implementation----------------------

//----------Setters-----------

void Player::setHealth(const int& health){  //this will make sure the player always has 5 healthpoints when created
    this->health = (health == 5)? health : 5;
}

//---------------End of Player------------------------------






//---------------Zombie Implementation----------------------

//-----------Setters----------

void Zombie::setHealth(const int& health){
    this->health = (health > 0)? health : 1;
}

void Zombie::setID(const int& iD){
    this->iD = (iD >= 0 && iD < 3)? iD : 0;
}

//---------Overloaded Operators-----

bool Zombie::operator ==(const Zombie& assignThis){
    
    bool retVal = false; //fix this in future to compare differently, this will be a bug as is when we ceate graphics but i have no other way at the moment
    
    if (getX() == assignThis.getX()
        &&
        getY() == assignThis.getY()
        &&
        getZ() == assignThis.getZ()) {
        
        retVal = true;
    }
    
    return retVal;
}


//--------------End of Zombie-------------------------------






//--------------Item Implementation-------------------------

void Item::setItemId(int& itemId){
    this->itemId = (itemId >= 0 && itemId < 4)? itemId : 0;
}

void Item::setNumOfItemHeld(int& numOfItemHeld){
    this->numOfItemHeld = (numOfItemHeld > -1)? numOfItemHeld : 0;
}

//---------------End of Item--------------------------------






//---------------Resources Implementation--------------------

//--------Setters-------------

void Resources::setX(double& x){
    this->x = x;
}

void Resources::setY(double& y){
    this->y = y;
}

void Resources::setZ(double& z){
    this->z = z;
}

//----------------End of Resources---------------------------






//----------------Guns Implementation------------------------

//--------Setters---------------

void Guns::setAmmoType(int ammoType){
    this->ammoType = (getItemId() == ammoType &&
                      (ammoType > -1 && ammoType < 4))
                      ? ammoType : 0;
}

void Guns::setDamage(int damage){
    this->damage = damage;
}

//---------------End of Guns--------------------------------






//---------------Gadgets Implementation---------------------

void Gadgets::setEnergyLevel(int energyLevel){
    this->energyLevel = (energyLevel > -1 && energyLevel < 100)? energyLevel : 100;
}

void Gadgets::setDamage(int damage){
    this->damage = damage;
}

//---------------End of Gadgets-----------------------------

