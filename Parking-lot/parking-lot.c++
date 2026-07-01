enum VehicleType{
        BUS,
        CAR,
        BIKE,
        TRUCK,
        BYCYCLE
};

class Vehicle{
    private:
        int number;
        VehicleType type;
    public:

};

class ParkingSlot{
    private:
        int slot_no;
        VehicleType slot_type;
        bool is_freed;
    public:
}

class Ticket{
    private:
        int price;
        string car_number;
        string entry_time;
        string exit_time;
        string slot;
}


class spotselectStrategy{
    public:
        virtual ParkingSlot* findSpot(vector<ParkingSlot*>spots, Vehicle* vehicle)=0;
}

class FirstFreeSpotStrategy:public spotselectStrategy{
    public:
        ParkingSlot* findSpot(vector<ParkingSlot*>spots,Vehicle* vehicle)override{
                for(int i=0;i<spots.size();i++){
                    if(spots[i]->is_freed && vehicle->type == spots[i]->slot_type){
                        return spots[i];
                    }
                }
        }
}

class spotselectionstrategyfactory{
    public:
        static SpotSelectionStrategy* createStratgy(string type){
             if (type == "FIRST_FREE") {
            return new FirstFreeSpotStrategy();
        }

        if (type == "NEAREST") {
            return new NearestSpotStrategy();
        }

        return nullptr;
        }
}




class ParkingLotManager{
    private:
     ParkingSlots* parkingslot;
    public:
        void findfreedlot(){

        }

}

class ParkingLot{
    private:
        vector<ParkingSlots*>slots;
        spotselectStrategy* spotselectstrategy;
        vector<tikects*>tickets;
    public:
        Ticket* parkVehicle(vehicle* vehicle){
            
        }

}