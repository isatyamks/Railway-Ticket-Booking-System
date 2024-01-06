

class Passenger_general {
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
    };


class Passenger_satyam {
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
        //ticket.passengerName = "Passenger" + to_string(rand() % 1000);
        ticket.passenger =auto();
        ticket.ticketClass = generateRandomClass();
        ticket.PNR = generateRandomPNR();
    }





