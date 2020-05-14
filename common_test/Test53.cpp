/******************************************************************
** 文件名: Test53.cpp
** 创建人: BanMing 
** 日  期: 5/14/2020, 7:56:50 AM
** 描  述:  

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

namespace Test53
{
    class B
    {
    private:
        /* data */
    public:
        virtual void f() const;
    };

    class D : public B
    {
    private:
        /* data */
    public:
        virtual void f();
    };

} // namespace Test53
void Run() {}