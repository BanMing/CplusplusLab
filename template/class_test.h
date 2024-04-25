#include <vector>
#include <memory>
#include <string>

// 前置声明，在Blob中声明友元所需要的
template <typename>
class BlobPtr;

template <typename>
class Blob;

template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

#pragma region Blob

template <typename T>
class Blob
{
    // 每个Blob实例将访问权限授予用相同类型实例化的BlobPtr和相等运算符
    friend class BlobPtr<T>;
    friend bool operator== <T>(const Blob<T> &, const Blob<T> &);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    // 构造函数
    Blob();
    Blob(std::initializer_list<T> il);

    // Blob中的元素数目
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // 添加和删除元素
    void push_back(const T &t){data->push_back(t)};
    void pop_back();

    // 元素访问
    T &back();
    T &operator[](size_type i);

private:
    void check(size_type i, const std::string &msg) const;

private:
    std::shared_ptr<std::vector<T>> data;
};

template <typename T>
inline Blob<T>::Blob() : data(std::make_shared<std::vector<T>>())
{
}

template <typename T>
inline Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il))
{
}

template <typename T>
inline void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
inline T &Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
inline T &Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}
#pragma endregion

#pragma region BlobPtr
template <typename T>
class BlobPtr
{
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    T &operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr]; //(*p)为本对象指向的vector
    }

    // 递增和递减
    // 编译器处理模板自身引用时会自动提供匹配的实参
    BlobPtr &operator++();
    BlobPtr &operator--();

private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;

private:
    // 保存一个weak_ptr，表示底层vector可能被销毁
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
inline BlobPtr<T> &BlobPtr<T>::operator++()
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}
#pragma endregion

typedef Blob<std::string> StrBlob;
// C++11中可以直接设置别名
template <typename T>
using BlobT = Blob<T>;

void Run()
{
    Blob<std::string> articles = {"a", "b", "c"};

    Blob<char> ca; // BlobPtr<char>和operator==<char>都是本对象的友元
    Blob<int> ia;  // BlobPtr<int>和operator==<int>都是本对象的友元
}