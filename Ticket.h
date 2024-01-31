#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <vector>

class Ticket {
public:
    string departureTime;
    string departs;
    string arrive;
    string arrivalTime;
    string duration;
    string passengerName;
    string ticketClass;
    string PNR;
    string travelDate;
    int availableSeats;

    Ticket() {}

    Ticket(string depTime, string dep, string arr, string arrTime, string dur, string name,
           string tClass, string pnr, string date, int seats)
        : departureTime(depTime), departs(dep), arrive(arr), arrivalTime(arrTime),
          duration(dur), passengerName(name), ticketClass(tClass), PNR(pnr),
          travelDate(date), availableSeats(seats) {}
};

#endif // TICKET_H
