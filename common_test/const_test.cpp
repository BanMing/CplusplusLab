#include <iostream>
struct Test
{
    int a;
};

void Add(Test *res, const Test *left, const Test *right)
{
    res->a = left->a + right->a;
}

enum class EAttackReactionType 
{
	None,
	CanBeDodged,
	CanBeBlocked
};

class MyConstTest
{
private:
    EAttackReactionType a;
    // const EAttackReactionType GetA1() const { return a; }
public:
    MyConstTest() { a = EAttackReactionType::None; }
    EAttackReactionType GetA() const { return a; }
    const EAttackReactionType GetA1() const { return a; }
    const EAttackReactionType& GetA2() const { return a; }
    // EAttackReactionType& GetA3() const { return a; }
};

void Run()
{
    // Test *test1 = new Test();
    // test1->a = 1;

    // Test *test2 = new Test();
    // test2->a = 2;

    // Test* test3 = new Test();
    // test3->a = 3;

    // Add(test1, test2, test1);
    // printf("res:%d\n", test1->a);
    MyConstTest test;
    printf("value %d\n",test.GetA());
}