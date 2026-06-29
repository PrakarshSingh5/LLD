#include <iostream>

using std::cout;


1. Elevator
2. ElevatorController
3. Request
4. Floor
5. Button

Elevator : 
knows : cfloor, directon , request , state
what does : opendoor, closedoor, move, addRequest()

ElevetorController :
knows: elevetors, request
what does : find the exact elevetor for that request , 

Request: 
knows : direction , target floor
what does : assign direction, target floor 

Floor : 
knows : current floor,  target floor
what does : target floor 

Button : 
knows : direction 
what does : assign direction



enum Direction {
    UP, 
    DOWN, 
    IDLE
};

class Request{
public: 
    int sourceFloor;
    Direction direction;

    Request(int sourceFloor, Direction direction){
            this->sourceFloor=sourceFloor;
            this->direction=direction;
    }
};

class Elevator{
    public:
        int id;
        int currentFloor;
        Direction direction;
        // vector<Request> allRequests;


        Elevator(int id){
            this->id=id;
            this->currentFloor=0;
            this->direction=IDLE;
        }

        void moveToFloor(int floor){
            cout<<"Moving to ";
            currentFloor=floor;
        }

        void OpenDoor(){
            cout << "Open Door";
        }

        void closeDoor(){
             cout << "Close Door";
        }

};


class ElevatorController{
    public:
        vector<int>reqeuets;
        int currentfloor;
        void pressButton(int currentfloor){
            this->currentfloor=currentfloor;
            //will write the streagy to select the elevator

        }
        void requestFloor(int targetFloor){
            if(this->currentfloor>targetFloor){
                Request(targe)
            }
        }
   
    
}