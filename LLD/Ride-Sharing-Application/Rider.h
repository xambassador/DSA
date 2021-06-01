//
// Created by yash on 01/06/21.
//

#ifndef RIDER_H
#define RIDER_H

#include <vector>
#include "Person.h"
#include "Ride.h"

class Rider : private Person {
    std::vector<Ride> completedRides;
    Ride currentRide;

public:
    Rider(std::string);
    void createRide(int, int, int, int);
    void updateRide(int, int, int, int);
    void withDrawRide(int);
    int closeRide();
};


Rider::Rider(std::string name) {
    this->name = name;
}

void Rider::createRide(int id, int origin, int destination, int seats) {
    if (origin >= destination) {
        std::cout << "Cant create ride. You enter wrong origin and destination values." << std::endl;
        return;
    }

    currentRide.setId(id);
    currentRide.setOrigin(origin);
    currentRide.setSeats(seats);
    currentRide.setDestination(destination);
    currentRide.setRideStatus(RideStatus::CREATED);
}


void Rider::updateRide(int id, int origin, int destination, int seats) {
    if (currentRide.getRideStatus() == RideStatus::WITHDRAWN) {
        std::cout << "Can not update ride. Ride was withdrawn" << std::endl;
        return;
    }

    if (currentRide.getRideStatus() == RideStatus::COMPLETED) {
        std::cout << "Can not update ride. Ride already completed." << std::endl;
        return;
    }

    createRide(id, origin, destination, seats);
}


void Rider::withDrawRide(int id) {
    if (currentRide.getId() != id) {
        std::cout << "Wrong id. Cant withdraw ride." << std::endl;
        return;
    }

    if (currentRide.getRideStatus() != RideStatus::CREATED) {
        std::cout << "Ride wasn't in progress. Cant withdraw ride." << std::endl;
        return;
    }

    currentRide.setRideStatus(RideStatus::WITHDRAWN);
}


int Rider::closeRide() {
    if (currentRide.getRideStatus() != RideStatus::CREATED) {
        std::cout << "Ride wasn't in progress. Cant close ride." << std::endl;
        return 0;
    }

    currentRide.setRideStatus(RideStatus::COMPLETED);
    completedRides.push_back(currentRide);
    return currentRide.calculateFare(completedRides.size() >= 10);
}

#endif
