## Problem Definition
Design a Ride sharing Application where drivers can offer rides (origin, destiniton, no of seats) any rider can request rides(origin, destination, no of seats).
There is an algorithm to choose to calculate ride amount charged for a given ride base on distance and no of seats

1. When the ride closes, show the amount charged to the rider
2. Ride amount if No of Seats >= 2 : No of kilometers * No of seats * 0.75 * Amount charged per km
3. Ride amount if No of sears = 1 : No of Kilometers * Amount charged per km

The program should take as input two or more drivers and a set of riders requesting rides. Multiple rides can happen simultaneously.

## Assumption
1. Assume amount charged per km = 20
2. No of kilometers = destination - origin
3. All values are integer

## Test case
A requesting for a ride R1
INPUT : A request 50, 60, 1
OUTPUT : Ride amount : 10 * 20 = 200

A requesting for a ride R1
INPUT : A request 50, 60, 2
OUTPUT : Ride amount : 10 * 2 * 0.75* 20 = 300

## Bonus
* Upgrade the rider to a preferred rider if he has done in more then 10 rides
* Preferred rider amount if No of seats >= 2 : No of kilometers * No of seats * 0.5 * amount charged per km
* preferred ride amount if No of seats = 1 : No of kilometers * Amount charged per km * 0.75

## Functionality excepted
* Add Driver(name)
* Add rider(name)
* create ride (id, origin, destination, no of seats)
* create/update ride (id, origin, destination, no of seats)