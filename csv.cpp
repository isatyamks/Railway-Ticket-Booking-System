#include <iostream>
#include <fstream>
#include <string>  

using namespace std;

void member(string mem){

    cout<<"Choose Any one Option Below:\n --> I am a passenger (p) \n -->I am a IR member (IRM)"<<endl;
    cin>>mem;
    if(mem =='p'){

    }
    

}

void create() {
    ofstream fout;

    fout.open("data.csv");  

    if (!fout.is_open()) {
        cout << "Error opening the file!" << endl;
        return;  
    }

    cout << "Enter Details of Passenger:"
         << " roll name maths phy chem bio" << endl;

   string departureTime;
    string departs;
    string arrive;
    string arrivalTime;
    string duration;
    string passenger;
    string trainClass;
    string PNR;

    cout<<"Are You Passenger or IR Staff"

    for (int i = 0; i < irmem; i++) {
        
    
        cout << "Enter train booking details:" << endl;
        cin >> departureTime >> departs >> arrive >> arrivalTime >> duration >> passenger >> trainClass >> PNR;
    }

   
    fout.close();
}

int main() {
    create();  
    return 0;  
}
