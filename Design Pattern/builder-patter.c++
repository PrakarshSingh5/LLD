class User{
    private :
        string name ;
        string email ;
        
        int phone_number;
        string address;
    public : 
        User(string name, string email){
             this->name=name;
             this->email=email;
        }   
}

class userbuilder{
    private:
        User* user;
    public:
        userbuilder(string name, string email){
            user = new User(name, email);
        }

        userbuilder& setPhoneNumber(int phone_number){
            user->setPhone(phone_number);
            return *this;
        }

        userbuilder& setAddress(string address){
            user->setAddress(phone_number);
             return *this;
        }

        User* build() {
    return user;
}


}