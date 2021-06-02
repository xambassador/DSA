//
// Created by yash on 02/06/21.
//

#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "Rider.h"

class System {
    int drivers;
    std::vector<Rider> riders;

public:
    System(int, std::vector<Rider>&);
    void createRide(int, int, int, int, int);
    void updateRide(int, int, int, int, int);
    void withDrawRide(int, int);
    int closeRide(int);
};


System::System(int drivers, std::vector<Rider> &rides) {
    if (drivers < 2 || riders.size() < 2) {
        std::cout << "Not enough drivers or riders." << std::endl;
    }

    this->drivers = drivers;
    this->riders = riders;
}

void System::createRide(int riderId, int rideId, int origin, int destination, int seats) {
    if (drivers == 0) {
        std::cout << "Drivers are currently busy. Try after some time.." << std::endl;
        return;
    }

    for (Rider &rider : riders) {
        if (rider.getId() == riderId) {
            rider.createRide(riderId, origin, destination, seats);
            drivers--;
            break;
        }
    }
}

void System::updateRide(int riderId, int rideId, int origin, int destination, int seats) {
    for (Rider &rider : riders) {
        if (rider.getId() == riderId) {
            rider.updateRide(riderId, origin, destination, seats);
            drivers--;
            break;
        }
    }
}

void System::withDrawRide(int riderId, int rideId) {
    for (Rider &rider : riders) {
        if (rider.getId() == riderId) {
            rider.withDrawRide(riderId);
            drivers++;
            break;
        }
    }
}

int System::closeRide(int riderId) {
    for (Rider &rider : riders) {
        if (rider.getId() == riderId) {
            drivers++;
            return rider.closeRide(riderId);
        }
    }

    return 0;
}

#endif
