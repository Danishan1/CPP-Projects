#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define classes for the Hotel Management System

// Class for handling guests
class Guest
{
private:
    string name;
    string email;
    string phone;

public:
    Guest()
    {
    }
    Guest(string name, string email, string phone)
    {
        this->name = name;
        this->email = email;
        this->phone = phone;
    }

    string getName() { return name; }
    string getEmail() { return email; }
    string getPhone() { return phone; }
};

// Class for handling rooms
class Room
{
private:
    int roomNumber;
    string roomType;
    double roomRate;

public:
    Room(){}
    Room(int roomNumber, string roomType, double roomRate)
    {
        this->roomNumber = roomNumber;
        this->roomType = roomType;
        this->roomRate = roomRate;
    }

    int getRoomNumber() { return roomNumber; }
    string getRoomType() { return roomType; }
    double getRoomRate() { return roomRate; }
};

// Class for handling reservations
class Reservation
{
private:
    Guest guest;
    Room room;
    string checkInDate;
    string checkOutDate;

public:
    Reservation(){}
    Reservation(Guest guest, Room room, string checkInDate, string checkOutDate)
    {
        this->guest = guest;
        this->room = room;
        this->checkInDate = checkInDate;
        this->checkOutDate = checkOutDate;
    }

    Guest getGuest() { return guest; }
    Room getRoom() { return room; }
    string getCheckInDate() { return checkInDate; }
    string getCheckOutDate() { return checkOutDate; }
};

// Class for handling the hotel
class Hotel
{
private:
    vector<Reservation> reservations;
    vector<Room> rooms;

public:
    // Function to add a new reservation
    void addReservation(Reservation r)
    {
        reservations.push_back(r);
    }

    // Function to add a new room
    void addRoom(Room r)
    {
        rooms.push_back(r);
    }

    // Function to get a list of available rooms for a given date range
    vector<Room> getAvailableRooms(string checkInDate, string checkOutDate)
    {
        vector<Room> availableRooms;
        for (int i = 0; i < rooms.size(); i++)
        {
            bool roomAvailable = true;
            for (int j = 0; j < reservations.size(); j++)
            {
                if (reservations[j].getRoom().getRoomNumber() == rooms[i].getRoomNumber())
                {
                    // Check if the room is available for the given date range
                    if (checkInDate >= reservations[j].getCheckInDate() && checkInDate <= reservations[j].getCheckOutDate())
                    {
                        roomAvailable = false;
                    }
                    else if (checkOutDate >= reservations[j].getCheckInDate() && checkOutDate <= reservations[j].getCheckOutDate())
                    {
                        roomAvailable = false;
                    }
                }
            }
            if (roomAvailable)
            {
                availableRooms.push_back(rooms[i]);
            }
        }
        return availableRooms;
    }

    // Function to display all reservations
};