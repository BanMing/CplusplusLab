// 左值、右值和引用

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void left_value()
{

    vector<string> arr(3);      // left value
    const int x = 2;            // left value
    int y;                      // left
    int z = x + y;              // z left value,x + y right value
    string str = "foo";         // str left value , "foo" right value
    vector<string> *ptr = &arr; // *ptr left value
}

void lvalue_reference()
{
    string str = "hell";          //
    string &rstr = str;           // rstr是str的另一个名字
    rstr += 'o';                  // 把str改成“hello”
    bool cond1 = (&str == &rstr); // true；str和rstr是同一个对象
    bool cond2 = (str == rstr);   // true；str和rstr是同一个对象

    // string &bad1 = "hello";          // 非法：“hello”不是一个可修改左值
    // string &bad2 = str + "";         // 非法：+“” 不是左值
    // string &sub = str.substr(0,4);   // 非法：str.substr(0,4)不是左值

    for (auto &x : str)
    {
        cout << x << endl;
        /* code */
    }
}

void rvalue_reference()
{
    string str = "hell";
    string &&bad1 = "hello";
    string &&bad2 = str + "s";
    string &&bad3 = str.substr(0, 4);
}

void swap(double &a, double &b){};
void swap(const double &a, const double &b){};

class LagreType
{
};
int randomInt(size_t start, size_t end) { return rand(); }

LagreType randomItem1(const vector<LagreType> &arr)
{
    return arr[randomInt(0, arr.size())];
}

const LagreType &randomItem2(const vector<LagreType> &arr)
{
    return arr[randomInt(0, arr.size())];
}

vector<int> partialSum(const vector<int> arr)
{
    vector<int> result(arr.size());
    result[0] = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
        result[i] = result[i - 1] + arr[i];
    }
    // vector已带有移动语义实现
    return result;
}

void Run()
{
    lvalue_reference();

    vector<LagreType> vec;
    LagreType item1 = randomItem1(vec);       // 复制
    LagreType item2 = randomItem2(vec);       // 复制
    const LagreType item3 = randomItem2(vec); // 不复制

    vector<int> vec1;
    vector<int> sums = partialSum(vec1); // 在老c++中是复制，在c++中是移动
}