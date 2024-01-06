#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TrainBooking
{
public:
    string departureTime;
    string departs;
    string arrive;
    string arrivalTime;
    string duration;
    string passenger;
    string trainClass;
    string PNR;

    void inputDetails()
    {
        cout << "Enter train booking details:" << endl;
        cin >> departureTime >> departs >> arrive >> arrivalTime >> duration >> passenger >> trainClass >> PNR;
    }
};

class FileManager
{
public:
    static void createFile(const string& filename)
    {
        ofstream fout(filename);

        if (!fout.is_open())
        {
            cout << "Error opening the file!" << endl;
            return;
        }

        fout.close();
    }
};

int main()
{
    TrainBooking pass_1;
    pass_1.inputDetails();

    FileManager::createFile("data.csv");
    
    return 0;
}
