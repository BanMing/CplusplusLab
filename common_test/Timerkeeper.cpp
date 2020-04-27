//
// Created by BanMing on 4/27/2020.
//

class TimerKeeper {
public :
    TimerKeeper();
    // 基类的析构函数，如果不为虚函数，在使用指针指向子类代表基类时，
    // 使用delete指针对象，会产生子类无法删除完整
    virtual ~TimerKeeper();

};

//class AtomicClock : public TimeKeeper {
//};
//
//class WaterClock : public TimeKeeper {
//};
//
//class WristWatch : public TimeKeeper {
//};

void Run() {

//    TimeKeeper *ptk = getTimeKeeper();

//    delete ptk;
}
