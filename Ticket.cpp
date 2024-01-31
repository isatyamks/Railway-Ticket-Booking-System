#include "Ticket.h"
#include <iostream>
#include <fstream>

Ticket::Ticket() {}

Ticket::Ticket(std::string depTime, std::string dep, std::string arr, std::string arrTime, std::string dur,
               std::string name, std::string tClass, std::string pnr, std::string date, int seats)
    : departureTime(depTime), departs(dep), arrive(arr), arrivalTime(arrTime),
      duration(dur), passengerName(name), ticketClass(tClass), PNR(pnr),
      travelDate(date), availableSeats(seats) {}
