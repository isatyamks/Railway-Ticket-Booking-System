class Passenger {
public:
    void inputDetails(Ticket& ticket) {
        cout << "Enter Departure Time: ";
        cin >> ticket.departureTime;
        cout << "Enter Departs: ";
        cin >> ticket.departs;
        cout << "Enter Arrive: ";
        cin >> ticket.arrive;
        
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
        int hours = rand() % 5 + 1; 
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