#ifndef RAILWAY_MEMBER_H
#define RAILWAY_MEMBER_H

#include <vector>
#include<fstream>
#include "Ticket.h"

class RailwayMember {
private:
    int maxTickets;

public:
    RailwayMember(int max) : maxTickets(max) {}

    bool bookTicket(vector<Ticket>& tickets, const Ticket& newTicket) {
        if (tickets.size() < maxTickets && newTicket.availableSeats > 0) {
            tickets.push_back(newTicket);
            cout << "Ticket booked successfully! Your PNR is: " << newTicket.PNR << "\n";
            writePassengerDetails(newTicket); // Write passenger details to CSV file
            updateAvailableSeats(tickets, newTicket); // Update available seats for the booked class and date
            return true;
        } else {
            cout << "Sorry, maximum tickets reached or no available seats. Cannot book more tickets.\n";
            return false;
        }
    }

    void writePassengerDetails(const Ticket& ticket) {
        ofstream fout("pdata.csv", ios::app); // Open file in append mode

        fout << ticket.departureTime << ","
             << ticket.departs << ","
             << ticket.arrive << ","
             << ticket.arrivalTime << ","
             << ticket.duration << ","
             << ticket.passengerName << ","
             << ticket.ticketClass << ","
             << ticket.PNR << ","
             << ticket.travelDate << "\n";

        fout.close();
    }

    void updateAvailableSeats(vector<Ticket>& tickets, const Ticket& newTicket) {
        for (auto& ticket : tickets) {
            if (ticket.travelDate == newTicket.travelDate && ticket.ticketClass == newTicket.ticketClass) {
                ticket.availableSeats--;
            }
        }
    }

    void displayBookedTicket(const vector<Ticket>& tickets, const string& pnr) {
        for (const auto& ticket : tickets) {
            if (ticket.PNR == pnr) {
                cout << "\nBooked Ticket Details:\n";
                displayTicketDetails(ticket);
                return;
            }
        }
        cout << "Ticket with PNR " << pnr << " not found.\n";
    }

    void displayAllTickets(const vector<Ticket>& tickets) {
        cout << "\nAll Booked Tickets:\n";
        for (const auto& ticket : tickets) {
            displayTicketDetails(ticket);
        }
    }

    void readPassengerDetails() {
        ifstream fin("pdata.csv");
        if (!fin) {
            cout << "Error opening pdata.csv file.\n";
            return;
        }

        string line;
        cout << "\nPassenger Details from CSV file:\n";
        while (getline(fin, line)) {
            cout << line << "\n";
        }

        fin.close();
    }

    void displayTicketDetails(const Ticket& ticket) {
        cout << "Departure Time: " << ticket.departureTime << "\n"
             << "Departs: " << ticket.departs << "\n"
             << "Arrive: " << ticket.arrive << "\n"
             << "Arrival Time: " << ticket.arrivalTime << "\n"
             << "Duration: " << ticket.duration << "\n"
             << "Passenger Name: " << ticket.passengerName << "\n"
             << "Class: " << ticket.ticketClass << "\n"
             << "PNR: " << ticket.PNR << "\n"
             << "Travel Date: " << ticket.travelDate << "\n"
             << "Available Seats: " << ticket.availableSeats << "\n";
    }
};

#endif // RAILWAY_MEMBER_H
