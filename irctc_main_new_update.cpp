#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

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

    Ticket(string depTime, string dep, string arr, string arrTime, string dur, string name, string tClass, string pnr)
        : departureTime(depTime), departs(dep), arrive(arr), arrivalTime(arrTime), duration(dur),
          passengerName(name), ticketClass(tClass), PNR(pnr) {}
};

class RailwayMember {
private:
    int maxTickets;

public:
    RailwayMember(int max) : maxTickets(max) {}

    bool bookTicket(vector<Ticket>& tickets, const Ticket& newTicket) {
        if (tickets.size() < maxTickets) {
            tickets.push_back(newTicket);
            cout << "Ticket booked successfully!\n";
            writePassengerDetails(newTicket); // Write passenger details to CSV file
            return true;
        } else {
            cout << "Sorry, maximum tickets reached. Cannot book more tickets.\n";
            return false;
        }
    }

    void writePassengerDetails(const Ticket& ticket) {
        ofstream fout("data.csv", ios::app); // Open file in append mode

        fout << ticket.departureTime << ","
             << ticket.departs << ","
             << ticket.arrive << ","
             << ticket.arrivalTime << ","
             << ticket.duration << ","
             << ticket.passengerName << ","
             << ticket.ticketClass << ","
             << ticket.PNR << "\n";

        fout.close();
    }
};

class Passenger {
public:
    void inputDetails(Ticket& ticket) {
        cout << "Enter Departure Time: ";
        cin >> ticket.departureTime;
        cout << "Enter Departs: ";
        cin >> ticket.departs;
        cout << "Enter Arrive: ";
        cin >> ticket.arrive;
        cout << "Enter Arrival Time: ";
        cin >> ticket.arrivalTime;
        cout << "Enter Duration: ";
        cin >> ticket.duration;
        cout << "Enter Passenger Name: ";
        cin >> ticket.passengerName;
        cout << "Enter Class: ";
        cin >> ticket.ticketClass;
        cout << "Enter PNR: ";
        cin >> ticket.PNR;
    }
};

int main() {
    vector<Ticket> tickets;
    RailwayMember railwayMember(5);  // Limiting to 5 tickets

    while (true) {
        cout << "\n1. Book Ticket\n"
             << "2. Exit\n"
             << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                Ticket newTicket("", "", "", "", "", "", "", "");

                Passenger passenger;
                passenger.inputDetails(newTicket);

                railwayMember.bookTicket(tickets, newTicket);
                break;
            }
            case 2:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
