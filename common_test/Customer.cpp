//
// Created by BanMing on 4/27/2020.
//

//制造一个log entry
void logCall(const std::string &funcName) {
    std::cout << funcName << std::endl;
}

class Customer {
public:
    Customer(const Customer &rhs);

    Customer &operator=(const Customer &rhs);

private:
    std::string name;
};

// 复制rhs的数据
Customer::Customer(const Customer &rhs) : name(rhs.name) {
    logCall("Customer copy constructor");
//    trl::shared_prt<>
}

Customer &Customer::operator=(const Customer &rhs) {
    logCall("Customer copy assignment operator");
    name = rhs.name; //复制rhs的数据
    return *this;
}

typedef std::string AddressLines[4];

void Run() {

}

