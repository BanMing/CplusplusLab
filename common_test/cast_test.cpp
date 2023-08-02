class Animal
{
public:
    virtual void makeSound() { std::cout << "I am an animal." << std::endl; }
};

class Dog : public Animal
{
public:
    void makeSound() override { std::cout << "Woof!" << std::endl; }
    void wagTail() { std::cout << "Tail wagging." << std::endl; }
    int test;
};

void Run()
{
    printf("@@@@refrence@@@@@\n");

    Animal animal;

    Dog &dog = static_cast<Dog &>(animal);
    dog.makeSound(); // output: Woof!
    dog.wagTail();   // output: Tail wagging.
    dog.test = 3;
    printf("test:%d\n", static_cast<Dog &>(animal).test);
    printf("@@@@point@@@@@\n");

    Animal *animal1 = new Dog();

    Dog *dog1 = static_cast<Dog *>(animal1);
    dog1->makeSound(); // output: Woof!
    dog1->wagTail();

    delete animal1;

    // Animal animal2;

    // Dog dog2 = static_cast<Dog>(animal2); // complie error
    // dog2.makeSound(); // output: Woof!
    // dog2.wagTail();   // output: Tail wagging.
}
