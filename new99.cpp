#include<iostream>
#include<fstream>
#include<vector>

string Ticket,updateAvailableSeats;
const string Ticket;

using namespace std;

class RailwayMember {
private:
    int maxTickets;

public:
    RailwayMember(int max) : maxTickets(max) {}

    bool bookTicket(vector<Ticket> tickets, const Ticket newTicket) {
        if (tickets.size() < maxTickets && newTicket.availableSeats > 0) {
            tickets.push_back(newTicket);
            cout << "Ticket booked successfully! Your PNR is: " << newTicket.PNR << "\n";
            writePassengerDetails(newTicket); 
            updateAvailableSeats(tickets, newTicket); 
            return true;
        } else {
            cout << "Sorry, maximum tickets reached or no available seats. Cannot book more tickets.\n";
            return false;
        }
    }

    void writePassengerDetails(const Ticket ticket) {
        ofstream fout("passenger_data.csv", ios::app); 

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
};
int main()
{

return 0;
}