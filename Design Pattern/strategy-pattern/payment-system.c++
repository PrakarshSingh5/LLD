// Classes 
// Orchestrator
// PaymentController
// UPI
// Credit Card
// Debit Card
// Net Banking
// Wallet


class PaymentData {
public:
    int amount;
    string bic_swift;
    string account_number;
    string upi_id;
};
class PaymentStrategy{
    public:
        virtual void payment(PaymentData data )=0;
}

class UPI : public PaymentStrategy {
    public: 
        void payment(PaymentData data)override{
            // do processing 
        }
}
class CreditCard  : public PaymentStrategy{
    public: 
        void payment(PaymentData data)override{
            // do processing 
        }
}
class DebitCard : public PaymentStrategy {
    public: 
        void payment(PaymentData data)override{
            // do processing 
        }
}
class NetBanking : public PaymentStrategy {
    public: 
        void payment(PaymentData data)override{
            // do processing 
        }
}

class Wallet : public PaymentStrategy {
    public: 
        void payment(PaymentData data)override {
            // do processing 
        }
}

class Orchestrator{
    PaymentStrategy* paymentStrategy;
    public: 
        void setpayment(PaymentController* paymentController){
            this->paymentController=paymentController;
        }  
        
        void dopayment(payment data){
            paymentController->payment(data);
        }

}

int main(){
    Orchestrator p;

    p.setpayment(new UPI());   
    p.dopayment(data);
}

