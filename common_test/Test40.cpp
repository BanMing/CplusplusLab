//
// Created by BanMing on 2020/5/8.
//
class BorrowableItem { //图书馆允许你借某些东西
public:
    void checkOut();   //离开时进行检查
};

class ElectronicGadget {
private:
    bool checkOut() const; //执行自我检测，返回是否测试成功
};

//多重继承
class MP3Player : public BorrowableItem, public ElectronicGadget {
};

void Run() {
    MP3Player mp;
    //歧义！调用的是哪个checkOut？
    // mp.checkOut();
    // 可以指定调用
    mp.BorrowableItem::checkOut();
}