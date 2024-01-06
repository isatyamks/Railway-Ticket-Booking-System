#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

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

    Ticket() {}

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
        ofstream fout("passenger_data.csv", ios::app); // Open file in append mode

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

    void displayTicketDetails(const Ticket& ticket) {
        cout << "Departure Time: " << ticket.departureTime << "\n"
             << "Departs: " << ticket.departs << "\n"
             << "Arrive: " << ticket.arrive << "\n"
             << "Arrival Time: " << ticket.arrivalTime << "\n"
             << "Duration: " << ticket.duration << "\n"
             << "Passenger Name: " << ticket.passengerName << "\n"
             << "Class: " << ticket.ticketClass << "\n"
             << "PNR: " << ticket.PNR << "\n";
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
        // Generate random values for other parameters
        ticket.arrivalTime = generateRandomTime();
        ticket.duration = generateRandomDuration();
        ticket.passengerName = "Passenger" + to_string(rand() % 1000);
        ticket.ticketClass = generateRandomClass();
        ticket.PNR = generateRandomPNR();
    }

    string generateRandomTime() {
        int hour = rand() % 24;
        int minute = rand() % 60;
        return to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
    }

    string generateRandomDuration() {
        int hours = rand() % 5 + 1; // Random duration between 1 and 5 hours
        int minutes = rand() % 60;
        return to_string(hours) + "h" + (minutes < 10 ? "0" : "") + to_string(minutes) + "m";
    }

    string generateRandomClass() {
        string classes[] = {"Economy", "Business", "First"};
        return classes[rand() % 3];
    }

    string generateRandomPNR() {
        return "PNR" + to_string(rand() % 1000000);
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed for random number generation
    vector<Ticket> tickets;
    RailwayMember railwayMember(5);  // Limiting to 5 tickets

    while (true) {
        cout << "\n1. Book Ticket\n"
             << "2. Display Booked Ticket\n"
             << "3. Exit\n"
             << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                Ticket newTicket;
                Passenger passenger;
                passenger.inputDetails(newTicket);

                railwayMember.bookTicket(tickets, newTicket);
                break;
            }
            case 2: {
                string enteredPNR;
                cout << "Enter PNR to display booked ticket: ";
                cin >> enteredPNR;
                railwayMember.displayBookedTicket(tickets, enteredPNR);
                break;
            }
            case 3:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
