//
// Created by yash on 01/06/21.
//

#ifndef RIDE_H
#define RIDE_H


enum RideStatus {
    IDLE, CREATED, WITHDRAWN, COMPLETED
};

class Ride {
    int id;
    int origin, destination, seats;
    RideStatus rideStatus;

public:

    static const int AMOUNT_PER_KM = 20;

    Ride();

    /* Setters */
    void setDestination(int dest);
    void setOrigin(int origin);
    void setSeats(int seats);
    void setId(int id);
    void setRideStatus(RideStatus rideStatus);

    /* Getters */
    int getId() const;
    RideStatus getRideStatus() const;

    int calculateFare(bool);
};

Ride::Ride() {
    this->id = this->origin = this->destination = this->seats = 0;
    this->rideStatus = RideStatus::IDLE;
}

int Ride::calculateFare(bool isPriorityRider) {
    int distance = destination - origin;
    if (seats < 2) {
        return distance * AMOUNT_PER_KM * (isPriorityRider ? 0.75 : 1);
    }

    return distance * seats * AMOUNT_PER_KM * (isPriorityRider ? 0.5 : 0.75);
}


void Ride::setDestination(int dest) {
    this->destination = dest;
}

void Ride::setOrigin(int origin) {
    this->origin = origin;
}

void Ride::setSeats(int seats) {
    this->seats = seats;
}

void Ride::setId(int id) {
    this->id = id;
}

void Ride::setRideStatus(RideStatus rideStatus) {
    this->rideStatus = rideStatus;
}

int Ride::getId() const {
    return this->id;
}

RideStatus Ride::getRideStatus() const {
    return this->rideStatus;
}

#endif