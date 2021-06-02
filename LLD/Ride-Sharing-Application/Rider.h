//
// Created by yash on 01/06/21.
//

#ifndef RIDER_H
#define RIDER_H

#include <vector>
#include "Person.h"
#include "Ride.h"

class Rider : private Person {
    std::vector<Ride> allRides;

public:
    Rider(std::string);
    void createRide(int, int, int, int);
    void updateRide(int, int, int, int);
    void withDrawRide(int);
    int closeRide(int);
};


Rider::Rider(std::string name) {
    this->name = name;
}

void Rider::createRide(int id, int origin, int destination, int seats) {
    if (origin >= destination) {
        std::cout << "Cant create ride. You enter wrong origin and destination values." << std::endl;
        return;
    }

    Ride currentRide;
    currentRide.setId(id);
    currentRide.setOrigin(origin);
    currentRide.setSeats(seats);
    currentRide.setDestination(destination);
    currentRide.setRideStatus(RideStatus::CREATED);
    allRides.push_back(currentRide);
}


void Rider::updateRide(int id, int origin, int destination, int seats) {
    auto it = allRides.rbegin();
    for (; it != allRides.rend(); ++it) {
        if (it->getId() == id) {
            break;
        }
    }

    if (it->getRideStatus() != RideStatus::CREATED) {
        std::cout << "Ride is not in progress. can not update ride." << std::endl;
        return;
    }

    it->setOrigin(origin);
    it->setDestination(destination);
    it->setSeats(seats);
}


void Rider::withDrawRide(int id) {
    auto it = allRides.rbegin();
    for (; it != allRides.rend(); ++it) {
        if (it->getId() == id) {
            break;
        }
    }

    if (it->getRideStatus() != RideStatus::CREATED) {
        std::cout << "Ride is not in progress. can not withdraw ride." << std::endl;
        return;
    }

    it->setRideStatus(RideStatus::WITHDRAWN);
    allRides.erase((it+1).base());
}


int Rider::closeRide(int id) {
    auto it = allRides.rbegin();
    for (; it != allRides.rend(); ++it) {
        if (it->getId() == id) {
            break;
        }
    }

    if (it->getRideStatus() != RideStatus::CREATED) {
        std::cout << "Ride is not in progress. can not close ride." << std::endl;
        return 0;
    }

    it->setRideStatus(RideStatus::COMPLETED);
    return it->calculateFare(allRides.size() >= 10);
}

#endif
