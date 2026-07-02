#include <bits/stdc++.h>
using namespace std;

enum VehicleType {
    BUS,
    CAR,
    BIKE,
    TRUCK,
    BICYCLE
};

class Vehicle {
private:
    string number;
    VehicleType type;

public:
    Vehicle(string number, VehicleType type) {
        this->number = number;
        this->type = type;
    }

    string getNumber() {
        return number;
    }

    VehicleType getType() {
        return type;
    }
};

class ParkingSpot {
private:
    int spotNo;
    VehicleType spotType;
    bool free;
    Vehicle* vehicle;

public:
    ParkingSpot(int spotNo, VehicleType spotType) {
        this->spotNo = spotNo;
        this->spotType = spotType;
        this->free = true;
        this->vehicle = nullptr;
    }

    bool isFree() {
        return free;
    }

    VehicleType getSpotType() {
        return spotType;
    }

    void parkVehicle(Vehicle* vehicle) {
        this->vehicle = vehicle;
        this->free = false;
    }

    void removeVehicle() {
        this->vehicle = nullptr;
        this->free = true;
    }

    int getSpotNo() {
        return spotNo;
    }
};

class Ticket {
private:
    Vehicle* vehicle;
    ParkingSpot* spot;
    time_t entryTime;

public:
    Ticket(Vehicle* vehicle, ParkingSpot* spot) {
        this->vehicle = vehicle;
        this->spot = spot;
        this->entryTime = time(nullptr);
    }

    Vehicle* getVehicle() {
        return vehicle;
    }

    ParkingSpot* getSpot() {
        return spot;
    }

    time_t getEntryTime() {
        return entryTime;
    }
};

class SpotSelectionStrategy {
public:
    virtual ParkingSpot* findSpot(vector<ParkingSpot*>& spots, Vehicle* vehicle) = 0;
};

class FirstFreeSpotStrategy : public SpotSelectionStrategy {
public:
    ParkingSpot* findSpot(vector<ParkingSpot*>& spots, Vehicle* vehicle) override {
        for (auto spot : spots) {
            if (spot->isFree() && spot->getSpotType() == vehicle->getType()) {
                return spot;
            }
        }
        return nullptr;
    }
};

class SpotSelectionStrategyFactory {
public:
    static SpotSelectionStrategy* createStrategy(string type) {
        if (type == "FIRST_FREE") {
            return new FirstFreeSpotStrategy();
        }

        return nullptr;
    }
};

class PricingStrategy {
public:
    virtual int calculateFee(Ticket* ticket) = 0;
};

class FixedPricingStrategy : public PricingStrategy {
public:
    int calculateFee(Ticket* ticket) override {
        return 50;
    }
};

class ParkingLotManager {
private:
    vector<ParkingSpot*> spots;
    SpotSelectionStrategy* spotStrategy;
    PricingStrategy* pricingStrategy;
    vector<Ticket*> activeTickets;
    PaymentStrategy* payment 

public:
    ParkingLotManager(
        vector<ParkingSpot*> spots,
        SpotSelectionStrategy* spotStrategy,
        PricingStrategy* pricingStrategy
    ) {
        this->spots = spots;
        this->spotStrategy = spotStrategy;
        this->pricingStrategy = pricingStrategy;
    }

    Ticket* parkVehicle(Vehicle* vehicle) {
        ParkingSpot* spot = spotStrategy->findSpot(spots, vehicle);

        if (spot == nullptr) {
            cout << "No spot available\n";
            return nullptr;
        }

        spot->parkVehicle(vehicle);

        Ticket* ticket = new Ticket(vehicle, spot);
        activeTickets.push_back(ticket);

        cout << "Vehicle parked at spot: " << spot->getSpotNo() << endl;

        return ticket;
    }

    int unparkVehicle(Ticket* ticket) {
        int fee = pricingStrategy->calculateFee(ticket);

        ParkingSpot* spot = ticket->getSpot();
        spot->removeVehicle();

        cout << "Vehicle removed from spot: " << spot->getSpotNo() << endl;
        cout << "Fee: " << fee << endl;

        return fee;
    }
};


class PaymentStrategy{
    public:
        virtual void payment(int amount)=0;
}

class UPI:public PaymentStrategy{
    pubilc: 
        void payment(int amount)override{
            cout<<`Payment has been done of amount ${amount}`
        }
}

int main() {
    vector<ParkingSpot*> spots;

    spots.push_back(new ParkingSpot(1, CAR));
    spots.push_back(new ParkingSpot(2, BIKE));
    spots.push_back(new ParkingSpot(3, TRUCK));
    spots.push_back(new ParkingSpot(4, CAR));

    SpotSelectionStrategy* spotStrategy =
        SpotSelectionStrategyFactory::createStrategy("FIRST_FREE");

    PricingStrategy* pricingStrategy = new FixedPricingStrategy();

    ParkingLotManager manager(spots, spotStrategy, pricingStrategy);

    Vehicle* car = new Vehicle("UP32AB1234", CAR);

    Ticket* ticket = manager.parkVehicle(car);

    if (ticket != nullptr) {
        manager.unparkVehicle(ticket);
    }

    return 0;
}