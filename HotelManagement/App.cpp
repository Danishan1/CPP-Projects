#include "basics.hpp"
#include "rooms.hpp"
#include "hotelMgnt.hpp"

#define max 100
using namespace std;

// managing rooms (adding and searching available rooms)
void manageRooms()
{
    class Room room;
    int select, roomNo, i, flag = 0;
    char ch;
    do
    {
        system("cls");
        cout << "\n~~~~~ Manage Rooms ~~~~~";
        cout << "\n1. Add Room";
        cout << "\n2. Search Room";
        cout << "\n3. Back to Main Menu";
        cout << "\n\nEnter Option: ";
        cin >> select;

        // switch statement
        switch (select)
        {
        case 1:
            cout << "\nEnter Room Number: ";
            cin >> roomNo;
            i = 0;
            for (i = 0; i < count; i++)
            {
                if (rooms[i].roomNumber == roomNo)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                cout << "\nRoom Number is Present.\nPlease enter unique Number";
                flag = 0;
                getch();
            }
            else
            {
                rooms[count] = room.addRoom(roomNo);
                count++;
            }
            break;
        case 2:
            cout << "\nEnter room number: ";
            cin >> roomNo;
            room.searchRoom(roomNo);
            break;
        case 3:
            // nothing to do
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (select != 3);
}

bool isRoomPre(int a)
{
    if (a == 0)
    {
        cout << "\nRooms data is not available.\nPlease add the rooms first.";
        getch();
        return false;
    }
    else
    {
        return true;
    }
}

using namespace std;
int main()
{
    class HotelMgnt hm;
    int i, j, select, roomNo;
    char ch;
    char pname[100];

    system("cls");

    do
    {
        system("cls");
        cout << "~~~~~~~~~~~~~~ Hotel Management ~~~~~~~~~~~~~~~~~\n";
        cout << "\n1. Manage Rooms";
        cout << "\n2. Check-In Room";
        cout << "\n3. Available Rooms";
        cout << "\n4. Search Customer";
        cout << "\n5. Check-Out Room";
        cout << "\n6. Guest Summary Report";
        cout << "\n7. Exit";
        cout << "\n\nEnter Option: ";
        cin >> select;
        switch (select)
        {
        case 1:
            manageRooms();
            break;
        case 2:
            if (isRoomPre(count))
                hm.checkIn();
            break;
        case 3:
            if (isRoomPre(count))
                hm.getAvailRoom();
            break;
        case 4:
            if (isRoomPre(count))
            {
                cout << "Enter Customer Name: ";
                cin >> pname;
                hm.searchCustomer(pname);
            }
            break;
        case 5:
            if (isRoomPre(count))
            {
                cout << "Enter Room Number : ";
                cin >> roomNo;
                hm.checkOut(roomNo);
            }
            break;
        case 6:
            hm.guestSummaryReport();
            break;
        case 7:
            cout << "\n~~~~~ THANK YOU! FOR USING SOFTWARE ~~~~~~";
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (select != 7);

    getch();
}