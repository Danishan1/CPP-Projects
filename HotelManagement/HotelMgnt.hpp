#ifndef HOTELMGNT
#define HOTELMGNT

#include "Room.hpp"

class HotelMgnt : protected Room
{
public:
    void checkIn();
    void getAvailRoom();
    void searchCustomer(char *);
    void checkOut(int);
    void guestSummaryReport();
};

#endif