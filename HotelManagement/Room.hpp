#ifndef ROOM
#define ROOM

#include "Customer.hpp"

class Room
{
public:
    char type;
    char stype;
    char ac;
    int roomNumber;
    int rent;
    int status;

    class Customer cust;
    class Room addRoom(int);
    void searchRoom(int);
    void deleteRoom(int);
    void displayRoom(Room);
};

#endif