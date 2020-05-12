//
// Created by BanMing on 2020/5/12.
//

namespace Test49 {

    class NewHandlerHolder {
    public:
        explicit NewHandlerHolder(std::new_handler nh) : handler(nh) {}

        ~NewHandlerHolder() { std::set_new_handler(handler); }

    private:
        std::new_handler handler;

        NewHandlerHolder(const NewHandlerHolder &);

        NewHandlerHolder &operator=(const NewHandlerHolder &);
    };
/////////////////////////////////////////////////////////////////////////////////////////

    class Widget {
    public:
        static std::new_handler set_new_handler(std::new_handler p) throw();

        static void *operator new(std::size_t size) throw(std::bad_alloc);

    private:
        static std::new_handler currentHandler;
    };

    // Static 成员必须在class定义式之外被定义
    std::new_handler Widget::currentHandler = 0;

    //Widget内的set_new_handler函数会将它获得的指针存储起来，然后返回先前存储的指针，这也正是标准版set_new_handler
    std::new_handler Widget::set_new_handler(std::new_handler p) throw() {
        std::new_handler oldHandler = currentHandler;
        currentHandler = p;
        return oldHandler;
    }

    void *Widget::operator new(std::size_t size) throw(std::bad_alloc) {
        // 安装Widget的new-handler分配内存或抛出异常。恢复global new-handler
        NewHandlerHolder h(std::set_new_handler(currentHandler));
        return ::operator new(size);
    }
}


void Run() {

}
