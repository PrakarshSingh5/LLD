class PaymentGateway {
public:
    virtual void pay() = 0;
};

// is a paymentgatway has a strip --> adpator 
class StripeAdapter : public PaymentGateway {
private:
    Stripe* stripe;

public:
    StripeAdapter(Stripe* stripe) {
        this->stripe = stripe;
    }

    void pay() override {
        stripe->makePayment();
    }
};

class Stripe {
public:
    void makePayment() {
        cout << "Stripe payment done\n";
    }
};

int main() {
    Stripe* stripe = new Stripe();

    PaymentGateway* gateway = new StripeAdapter(stripe);

    gateway->pay();
}