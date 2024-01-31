#ifndef PASSENGER_H
#define PASSENGER_H


#include<iostream>
#include<string>
#include<fstream>

using namespace std;




class{


    public:


        void Welcome(){
            int wkey;
            cout<<"Welcome to the IRTB";
            cout<<"Login as a \n IRTB member----[1]\nPassenger---[2]"<<endl;
            cin>>wkey;
            int t=0;


            while(t){

            
            if(wkey==1){


                t=0;
                break;


            }
            else if (wkey==2){

                t=0;
                break;

            }

            else{
                cout<<"Please Choose a Valid Key!"<<endl;
                t=1;
                break;


            }

            }


        }











};

#endif 