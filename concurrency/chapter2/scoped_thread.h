#ifndef _SCOPED_THREAD_H_
#define _SCOPED_THREAD_H_

#include <iostream>
#include <thread>

class scoped_thread
{
private:
    std::thread t;

public:
    explicit scoped_thread(std::thread _t) : t(std::move(_t))
    {
        if (!t.joinable())
        {
            throw std::logic_error("No thread");
        }
    }

    ~scoped_thread()
    {
        t.join();
    }

    scoped_thread(scoped_thread const &other) = delete;
    scoped_thread &opreator= (scoped_thread const &) = delete;
};

#endif //_SCOPED_THREAD_H_