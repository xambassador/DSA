//
// Created by yash on 01/06/21.
//

#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"

class Driver : private Person {
public:
    Driver(std::string);
};

Driver::Driver(std::string name) {
    this->name = name;
}



#endif