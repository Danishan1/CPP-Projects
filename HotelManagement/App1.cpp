#include "Basic.hpp"
#include "HotelMgnt.hpp"
#include "Room.hpp"

#define max 100
// using namespace std;

// Global Declarations
class Room rooms[max];
int countN = 0;

// managing rooms (adding and searching available rooms)
void manageRooms()
{
    class Room room = Room();
    int opt, rno, i, flag = 0;
    char ch;
    do
    {
        system("cls");
        cout << "\n### Manage Rooms ###";
        cout << "\n1. Add Room";
        cout << "\n2. Search Room";
        cout << "\n3. Back to Main Menu";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        // switch statement
        switch (opt)
        {
        case 1:
            cout << "\nEnter Room Number: ";
            cin >> rno;
            i = 0;
            for (i = 0; i < countN; i++)
            {
                if (rooms[i].roomNumber == rno)
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
                rooms[countN] = room.addRoom(rno);
                countN++;
            }
            break;
        case 2:
            cout << "\nEnter room number: ";
            cin >> rno;
            room.searchRoom(rno);
            break;
        case 3:
            // nothing to do
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 3);
}

int main()
{
    class HotelMgnt hm;
    int i, j, opt, rno;
    char ch;
    char pname[100];

    system("cls");

    do
    {
        system("cls");
        cout << "######## Hotel Management #########\n";
        cout << "\n1. Manage Rooms";
        cout << "\n2. Check-In Room";
        cout << "\n3. Available Rooms";
        cout << "\n4. Search Customer";
        cout << "\n5. Check-Out Room";
        cout << "\n6. Guest Summary Report";
        cout << "\n7. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            manageRooms();
            break;
        case 2:
            if (countN == 0)
            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";
                getch();
            }
            else
                hm.checkIn();
            break;
        case 3:
            if (countN == 0)
            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";
                getch();
            }
            else
                hm.getAvailRoom();
            break;
        case 4:
            if (countN == 0)
            {
                cout << "\nRooms are not available.\nPlease add the rooms first.";
                getch();
            }
            else
            {
                cout << "Enter Customer Name: ";
                cin >> pname;
                hm.searchCustomer(pname);
            }
            break;
        case 5:
            if (countN == 0)
            {
                cout << "\nRooms are not available.\nPlease add the rooms first.";
                getch();
            }
            else
            {
                cout << "Enter Room Number : ";
                cin >> rno;
                hm.checkOut(rno);
            }
            break;
        case 6:
            hm.guestSummaryReport();
            break;
        case 7:
            cout << "\nTHANK YOU! FOR USING SOFTWARE";
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 7);

    getch();
}