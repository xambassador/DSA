//
// Created by yash on 01/06/21.
//

#include <iostream>
#include <string>

#include "System.h"
#include "Ride.h"
#include "Rider.h"
#include "Driver.h"


int main() {

    Rider rider(1, "Yash");
    Driver driver("Jeet");
    Rider rider1(2, "Cow");
    Rider rider2(3, "Bee");

    std::vector<Rider> riders;

    riders.push_back(rider);
    riders.push_back(rider1);
    riders.push_back(rider2);

    System system(3, riders);

    rider.createRide(1,50,60,1);
    std::cout << rider.closeRide(1) << std::endl;
    rider.updateRide(1,50,60,2);
    std::cout << rider.closeRide(1) << std::endl;

    return 0;
}