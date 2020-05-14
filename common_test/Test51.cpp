/******************************************************************
** 文件名: Test51.cpp
** 创建人: BanMing 
** 日  期: 5/13/2020, 8:00:30 AM
** 描  述:  

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

namespace Test51
{
    class Test51
    {
    private:
        /* data */
    public:
        Test51(/* args */);
        ~Test51();
        void *operator new(std::size_t size) throw(std::bad_alloc);
    };

    Test51::Test51(/* args */)
    {
    }

    Test51::~Test51()
    {
    }

    void *Test51::operator new(std::size_t size) throw(std::bad_alloc)
    {
        using namespace std;
        if (size == 0)
        {
            size = 1;
        }
        while (true)
        {
            // 尝试分配size bytes；
            // if(分配成功)
            // return （一个指针，指向分配内存）；

            // 分配失败；找出目前的new-handling函数
            new_handler globalHandler = set_new_handler(0);
            set_new_handler(globalHandler);

            if (globalHandler)
                (*globalHandler)();
            else
                throw std::bad_alloc();
        }
    }

} // namespace Test51
void Run() {}