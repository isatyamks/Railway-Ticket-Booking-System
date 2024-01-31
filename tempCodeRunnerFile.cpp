
// int main() {
//     srand(static_cast<unsigned>(time(nullptr))); // Seed for random number generation
//     vector<Ticket> tickets;
//     RailwayMember railwayMember(5); // Limiting to 5 tickets

//     while (true) {
//         cout << "\n1. Book Ticket\n"
//              << "2. Display Booked Ticket\n"
//              << "3. Display All Booked Tickets\n"
//              << "4. View Passenger Details from CSV\n"
//              << "5. Exit\n"
//              << "Choose an option: ";

//         int choice;
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                 Ticket newTicket;
//                 Passenger passenger;
//                 passenger.inputDetails(newTicket);

//                 railwayMember.bookTicket(tickets, newTicket);
//                 break;
//             }
//             case 2: {
//                 string enteredPNR;
//                 cout << "Enter PNR to display booked ticket: ";
//                 cin >> enteredPNR;
//                 railwayMember.displayBookedTicket(tickets, enteredPNR);
//                 break;
//             }
//             case 3: {
//                 railwayMember.displayAllTickets(tickets);
//                 break;
//             }
//             case 4: {
//                 railwayMember.readPassengerDetails();
//                 break;
//             }
//             case 5:
//                 cout << "Exiting the program.\n";
//                 return 0;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//         }
//     }

//     return 0;
// }
