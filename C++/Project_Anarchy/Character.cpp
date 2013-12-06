//
//  Character.cpp
//  Hazardous
//
//  Created by Ryan Todd on 12/6/13.
//  Copyright (c) 2013 Ryan Todd. All rights reserved.
//
# include "Character.h"
using namespace CharacterType;

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

//--------------End of Zombie-------------------------------