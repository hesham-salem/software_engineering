//https://www.tomdalling.com/blog/software-design/solid-class-design-the-interface-segregation-principle/

//Clients should not be forced to depend upon interfaces that they do not use.

//"fat interfaces" — interfaces with additional useless methods — lead to inadvertent coupling between classes

/*The Interface Segregation Principle (ISP) states that a client should not be exposed to methods it doesn’t need.
Declaring methods in an interface that the client doesn’t need pollutes the interface and leads to a “bulky” or “fat” interface.*/

/*note don't cosider missing implementing of a mothed in interface is case of violate the principle as this can not happen due to
pure virual function instead of this thow  in or empty method will consider violate the principle.*/

/*The Interface Segregation Principle vs liskov substitution principle :
Interface Segregation Principle : focus on applying just the methods in interface ( check not work around by thow or empty method) 
liskov substitution Principle :focus on the bahvior of driven class methods due to implementation expected like the base class 
I mean driven class can be subtituted in stead of base class without diffent behvior 
*/




//before 
#include <iostream>

class Machine {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
};

class Printer : public Machine {
public:
    void print() override {
        std::cout << "Printing..." << std::endl;
    }

    void scan() override {
        // Not applicable for printers
        //or thow exception 
        //or empty
        std::cout << "Scan is not applicable for printers" << std::endl;
    }
};

class Scanner : public Machine {
public:
    void print() override {
        // Not applicable for scanners
        std::cout << "Print is not applicable for scanners" << std::endl;
    }

    void scan() override {
        std::cout << "Scanning..." << std::endl;
    }
};

int main() {
    Machine* machine1 = new Printer();
    machine1->print();
    machine1->scan(); // error: Printer cannot scan

    Machine* machine2 = new Scanner();
    machine2->print(); // error: Scanner cannot print
    machine2->scan();

    return 0;
}

//after

#include <iostream>

class Printable {
public:
    virtual void print() = 0;
};

class Scannable {
public:
    virtual void scan() = 0;
};

class Printer : public Printable {
public:
    void print() override {
        std::cout << "Printing..." << std::endl;
    }
};

class Scanner : public Scannable {
public:
    void scan() override {
        std::cout << "Scanning..." << std::endl;
    }
};

int main() {
    Printable* printer = new Printer();
    printer->print();

    Scannable* scanner = new Scanner();
    scanner->scan();

    return 0;
}
