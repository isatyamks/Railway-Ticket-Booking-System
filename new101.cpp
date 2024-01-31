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
            writePassengerDetails(newTicket); 
            return true;
        } else {
            cout << "Sorry, maximum tickets reached. Cannot book more tickets.\n";
            return false;
        }
    }

    void writePassengerDetails(const Ticket& ticket) {
        ofstream fout("passenger_data.csv", ios::app); 

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
        
        cout << "Enter Departs: ";
        cin >> ticket.departs;
        while (find(validStations.begin(), validStations.end(), ticket.departs) == validStations.end()) {
            cout << "Invalid departure station. Please enter a valid station: ";
            cin >> ticket.departs;
        }

       
        cout << "Enter Arrive: ";
        cin >> ticket.arrive;
        while (find(validStations.begin(), validStations.end(), ticket.arrive) == validStations.end()) {
            cout << "Invalid arrival station. Please enter a valid station: ";
            cin >> ticket.arrive;
        }

        
        ticket.departureTime = generateRandomTime();
        ticket.arrivalTime = generateRandomTime();
        ticket.duration = generateRandomDuration();
        ticket.passengerName = "Passenger" + to_string(rand() % 1000);
        ticket.ticketClass = generateRandomClass();
        ticket.PNR = generateRandomPNR();
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
