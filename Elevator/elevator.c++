#include <iostream>

using std::cout;

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