//
// Created by BanMing on 4/27/2020.
//

class Transaction {
public:
    // 做出一份因类型不同而不同的日志记录
    virtual void logTransaction() const;

    Transaction();

    ~ Transaction();

private:
    void init();
};

Transaction::Transaction() {
    std::cout << "Transaction" << std::endl;
//    logTransaction();
}

void Transaction::init() {
    logTransaction();
}

Transaction::~Transaction() {
    logTransaction();
}

void Transaction::logTransaction() const {
    std::cout << "Transaction log" << std::endl;
}

class BuyTransaction : public Transaction {
public:
    virtual void logTransaction() const;

//    ~BuyTransaction();
};

void BuyTransaction::logTransaction() const {
    std::cout << "BuyTransaction log" << std::endl;
}

//BuyTransaction::~BuyTransaction() {
//    logTransaction();
//}

void Run() {
    //这里构造函数不会调用 BuyTransaction 的logTransaction
    //因为这里构造函数是从base class 开始依次执行的。
    BuyTransaction buyTransaction;
//    buyTransaction.logTransaction();
//    delete buyTransaction;
}

