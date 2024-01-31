#ifndef PASSENGER_H
#define PASSENGER_H

#include "Ticket.h"


class 

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


#endif // PASSENGER_H
