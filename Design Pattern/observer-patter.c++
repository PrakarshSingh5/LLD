// oberserver pattern 
class PaymentStrategy{
    observertype* observer;
    public:
        virtual void payment(PaymentData data )=0;

        // call the function observer
}

class observertype{
    public: 
        virtual void sentNotification()=0;
}

class Email:public observertype{
    public:
        void sentNotification() override{
            // write the logic for that
        }
}

class SMS:public observertype{
    public:
        void sentNotification() override{
            // write the logic for that
        }
}

class Analytics:public observertype{
    public:
        void sentNotification() override{
            // write the logic for that
        }
}


class Orchestrator{
    PaymentStrategy* paymentStrategy;
    vector<observertype*>observers;
    public: 
         void addObserver(Observer* observer) {
            observers.push_back(observer);
         }

         void notifyObservers() {
             for (auto observer : observers) {
                  observer->sendNotification();
             }
        }

        void setpayment(PaymentStrategy* paymentStrategy){
            this->paymentStrategy=paymentStrategy;
        }  
        
        void dopayment(PaymentData data){
            paymentStrategy->payment(data);
            notifyObservers();
        }

}










int main(){
    Orchestrator o;
    PaymentFactory p;
    PaymentStrategy* strategy = p.createPayment("UPI");


    p.setpayment(strategy);   
    p.dopayment(data);
}

