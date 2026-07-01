class BaseCoffee{
    public:
     virtual string description()=0;
     virtual int cost()=0;
}

class Espresso : public basecoffee {
    public:
     virtual string description() override {
        return "This is the espresso";
     }
     virtual int cost() override{
            return  100;
     }
}


class MilkDecorator : public BaseCoffee {
private:
    BaseCoffee* coffee;

public:
    MilkDecorator(BaseCoffee* coffee) {
        this->coffee = coffee;
    }

    string description() override {
        return coffee->description() + " + Milk";
    }

    int cost() override {
        return coffee->cost() + 20;
    }
};
