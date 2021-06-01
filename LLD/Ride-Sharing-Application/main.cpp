//
// Created by yash on 01/06/21.
//

#include <iostream>
#include <string>

#include "Ride.h"
#include "Rider.h"
#include "Driver.h"

int main() {

    Rider rider("Yash");
    Driver driver("Jeet");

    rider.createRide(1, 50, 60, 1);
    std::cout << rider.closeRide() << std::endl;

    rider.updateRide(1,50,60,2);
    std::cout << rider.closeRide() << std::endl;

    std::cout << "*************************************************" << std::endl;

    rider.createRide(1,50,60,1);
    rider.withDrawRide(1);
    rider.updateRide(1,50,60,2);
    std::cout << rider.closeRide() << std::endl;

    std::cout << "*************************************************" << std::endl;

    rider.createRide(1,50,60,1);
    rider.updateRide(1,50,60,2);
    std::cout << rider.closeRide() << std::endl;


    return 0;
}