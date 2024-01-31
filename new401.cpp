#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const vector<string> validStations = {"StationA", "StationB", "StationC", "StationD", "StationE"};
const vector<string> validTrains = {"Train1", "Train2", "Train3", "Train4", "Train5"};

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

class Passenger {
public:
    void inputDetails(Ticket& ticket) {
        // Validate departure station
        cout << "Enter Departs: ";
        cin >> ticket.departs;
        while (find(validStations.begin(), validStations.end(), ticket.departs) == validStations.end()) {
            cout << "Invalid departure station. Please enter a valid station: ";
            cin >> ticket.departs;
        }

        // Validate arrival station
        cout << "Enter Arrive: ";
        cin >> ticket.arrive;
        while (find(validStations.begin(), validStations.end(), ticket.arrive) == validStations.end()) {
            cout << "Invalid arrival station. Please enter a valid station: ";
            cin >> ticket.arrive;
        }

        // Generate random values for other parameters
        ticket.departureTime = generateRandomTime();
        ticket.arrivalTime = generateRandomTime();
        ticket.duration = generateRandomDuration();
        ticket.passengerName = "Passenger" + to_string(rand() % 1000);
        ticket.ticketClass = generateRandomClass();
        ticket.PNR = generateRandomPNR();

        // New code: ask for travel date
        cout << "Enter Travel Date (YYYY-MM-DD): ";
        cin >> ticket.travelDate;

        // New code: ask for ticket class
        cout << "Enter Ticket Class (Economy/Business/First): ";
        cin >> ticket.ticketClass;

        // Validate ticket class
        while (ticket.ticketClass != "Economy" && ticket.ticketClass != "Business" && ticket.ticketClass != "First") {
            cout << "Invalid ticket class. Please enter a valid class: ";
            cin >> ticket.ticketClass;
        }

        // New code: display available seats for the selected class and date
        displayAvailableSeats(ticket);
    }

    void displayAvailableSeats(Ticket& ticket) {
    ticket.availableSeats = rand() % 50 + 1; // Random number between 1 and 50
    cout << "Available Seats for " << ticket.ticketClass << " on " << ticket.travelDate << ": "
         << ticket.availableSeats << "\n";
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
    RailwayMember railwayMember(5); // Limiting to 5 tickets

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
