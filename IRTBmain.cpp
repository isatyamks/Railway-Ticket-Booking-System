#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Ticket.h"
#include "RailwayMember.h"
#include "Passenger.h"

using namespace std;

const vector<string> validStations = {"StationA", "StationB", "StationC", "StationD", "StationE"};

const vector<string> validTrains = {"Rajdhani Express", "Shatabdi Express", "Duronto Express", "Garib Rath Express",
                                    "Humsafar Express", "Jan Shatabdi Express", "Superfast Express", "Deccan Queen",
                                    "Gatimaan Express", "Tejas Express", "Vande Bharat Express", "Godavari Express",
                                    "Mangala Lakshadweep Express", "Purushottam Express", "Swarna Jayanti Express",
                                    "Goa Sampark Kranti Express", "Sampoorna Kranti Express", "Himalayan Queen",
                                    "Golden Temple Mail", "Express", "Mail", "Duronto Express", "Express",
                                    "Superfast Express", "Express", "Express", "Mail", "Express",
                                    "Express", "Superfast Express", "Express", "Express", "Superfast Express",
                                    "Express", "Express", "Express", "Express", "Superfast Express",
                                    "Express", "Express", "Superfast Express", "Express", "Express",
                                    "Rajdhani Express", "Express", "Express", "Express", "Superfast Express"};

int main()
{
    srand(static_cast<unsigned>(time(nullptr))); // Seed for random number generation
    vector<Ticket> tickets;
    RailwayMember railwayMember(5); // Limiting to 5 tickets

    while (true)
    {
        cout << "\n1. Book Ticket\n"
             << "2. Display Booked Ticket\n"
             << "3. Display All Booked Tickets\n"
             << "4. View Passenger Details from CSV\n"
             << "5. Exit\n"
             << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Ticket newTicket;
            Passenger passenger;
            passenger.inputDetails(newTicket);

            railwayMember.bookTicket(tickets, newTicket);
            break;
        }
        case 2:
        {
            string enteredPNR;
            cout << "Enter PNR to display booked ticket: ";
            cin >> enteredPNR;
            railwayMember.displayBookedTicket(tickets, enteredPNR);
            break;
        }
        case 3:
        {
            railwayMember.displayAllTickets(tickets);
            break;
        }
        case 4:
        {
            railwayMember.readPassengerDetails();
            break;
        }
        case 5:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
