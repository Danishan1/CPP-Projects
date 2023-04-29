#include "Basic.hpp"
#include "Room.hpp"

// // Global Declarations
// class Room rooms[max];
// int count = 0;

Room Room::addRoom(int rno)
{
    class Room room;
    room.roomNumber = rno;
    cout << "\nType AC/Non-AC (A/N) : ";
    cin >> room.ac;
    cout << "\nType Comfort (S/N) : ";
    cin >> room.type;
    cout << "\nType Size (B/S) : ";
    cin >> room.stype;
    cout << "\nDaily Rent : ";
    cin >> room.rent;
    room.status = 0;

    cout << "\n Room Added Successfully!";
    getch();
    return room;
}

// void Room::searchRoom(int rno)
// {
//     int i, found = 0;
//     for (i = 0; i < count; i++)
//     {
//         if (rooms[i].roomNumber == rno)
//         {
//             found = 1;
//             break;
//         }
//     }
//     if (found == 1)
//     {
//         cout << "Room Details\n";
//         if (rooms[i].status == 1)
//         {
//             cout << "\nRoom is Reserved";
//         }
//         else
//         {
//             cout << "\nRoom is available";
//         }
//         displayRoom(rooms[i]);
//         getch();
//     }
//     else
//     {
//         cout << "\nRoom not found";
//         getch();
//     }
// }

// void Room::displayRoom(Room tempRoom)
// {
//     cout << "\nRoom Number: \t" << tempRoom.roomNumber;
//     cout << "\nType AC/Non-AC (A/N) " << tempRoom.ac;
//     cout << "\nType Comfort (S/N) " << tempRoom.type;
//     cout << "\nType Size (B/S) " << tempRoom.stype;
//     cout << "\nRent: " << tempRoom.rent;
// }

// Room Room::addRoom(int)
// {
//     return Room();
// }
