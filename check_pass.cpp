#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


class Ticket {
public:
    string departs;
    string arrive;
    string departureTime;
    string arrivalTime;
    string duration;
    string passengerName;
    string travelDate;
    string ticketClass;
    string PNR;
    int availableSeats;
};

class Passenger {
private:
    vector<string> validStations = {"StationA", "StationB", "StationC", "StationD"};

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

        
        cout << "Enter Travel Date (YYYY-MM-DD): ";
        cin >> ticket.travelDate;

        
        cout << "Enter Ticket Class (Economy/Business/First): ";
        cin >> ticket.ticketClass;

        
        while (ticket.ticketClass != "Economy" && ticket.ticketClass != "Business" && ticket.ticketClass != "First") {
            cout << "Invalid ticket class. Please enter a valid class: ";
            cin >> ticket.ticketClass;
        }

      
        ticket.departureTime = generateRandomTime();
        ticket.arrivalTime = generateRandomTime();
        ticket.duration = generateRandomDuration();
        ticket.passengerName = "Passenger" + to_string(rand() % 1000);
        ticket.PNR = generateRandomPNR();

       
        displayAvailableSeats(ticket);
    }

    void displayAvailableSeats(Ticket& ticket) {
        ticket.availableSeats = rand() % 50 + 1; 
        cout << "Available Seats for " << ticket.ticketClass << " on " << ticket.travelDate << ": "
             << ticket.availableSeats << "\n";
    }

    string generateRandomTime() {
        int hour = rand() % 24;
        int minute = rand() % 60;
        return to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
    }

    string generateRandomDuration() {
        int hours = rand() % 5 + 1; 
        int minutes = rand() % 60;
        return to_string(hours) + "h" + (minutes < 10 ? "0" : "") + to_string(minutes) + "m";
    }

    string generateRandomPNR() {
        return "PNR" + to_string(rand() % 1000000);
    }
};

int main() {
    srand(time(0)); 

    Passenger passenger;
    Ticket ticket;

    passenger.inputDetails(ticket);

    passenger.displayAvailableSeats(ticket);

    
 
    return 0;
}
