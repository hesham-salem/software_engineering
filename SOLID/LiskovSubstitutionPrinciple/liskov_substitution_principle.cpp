#include <iostream>
using namespace std;

namespace before
{
    class Amphibian
    {
    public:
        virtual void swim() = 0;
        virtual void walk() = 0;
    };
    class frog : public Amphibian
    {
        void swim()
        {
            cout << "I am swiming " << endl;
        }
        void walk()
        {
            cout << "I am walking" << endl;
        }
    };
    class Dolphin : public Amphibian
    {
        void swim()
        {
            cout << "I am swiming " << endl;
        }
        void walk()
        {
            // empty or thow exception
            throw std::runtime_error("not implemented walk method");
        }
    };
}

namespace after
{
    class Amphibian
    {
    public:
        virtual void swim() = 0;
        virtual void walk() = 0;
    };
    class swiming_animal
    {
    public:
        virtual void swim() = 0;
    };
    class frog : public Amphibian
    {
        void swim()
        {
            cout << "I am swiming " << endl;
        }
        void walk()
        {
            cout << "I am walking" << endl;
        }
    };
    class Dolphin : public swiming_animal
    {
        void swim()
        {
            cout << "I am swiming " << endl;
        }
        void walk()
        {
            // empty or thow exception
        }
    };
}
void test_function_for_Amphibian(before::Amphibian *animal)
{
    animal->swim();
    animal->walk();
}
void test_function_for_swiming_animal(after::swiming_animal *animal)
{
    animal->swim();
}
int main()
{
    before::Dolphin _dolphin_1;
    test_function_for_Amphibian(&_dolphin_1); // voilate LSP as a method of base class or interface not valid eg: empty or give exception

    // to solve this seperate  the base class /interface for Dolphin as it acording to LSP can not base on Amphibian interface as no implement for walk method
    // so lets Dolphin based on
    // applied LSP swiming_animal interface
    // don't work aroud this to couple Dolphin and frog on the same base Amphibian interface they are differ
       after::Dolphin _dolphin_2;
      test_function_for_swiming_animal(&_dolphin_2);
      after::frog _frog;
      test_function_for_Amphibian(&_frog); 
}
