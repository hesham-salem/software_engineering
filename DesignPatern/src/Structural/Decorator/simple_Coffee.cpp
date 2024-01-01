#include <iostream>
#include <string>

// Component interface
class Coffee {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete component
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Simple Coffee";
    }

    double cost() const override {
        return 1.0;
    }
};

// Decorator base class
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* coffee) : coffee(coffee) {}

    std::string getDescription() const override {
        return coffee->getDescription();
    }

    double cost() const override {
        return coffee->cost();
    }
};

// Concrete decorators
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const  {
        return coffee->getDescription() + ", Milk";
    }

    double cost() const  {
        return coffee->cost() + 0.5;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }

    double cost() const override {
        return coffee->cost() + 0.2;
    }
};

int main() {
    // Creating a simple coffee
    Coffee* simpleCoffee = new SimpleCoffee();
    std::cout << "Simple Coffee: " << simpleCoffee->getDescription() << ", Cost: $" << simpleCoffee->cost() << std::endl;

    // Decorating with milk
     Coffee* milkCoffee = new MilkDecorator(simpleCoffee);
    std::cout << "Milk Coffee: " << milkCoffee->getDescription() << ", Cost: $" << milkCoffee->cost() << std::endl;

    // Decorating with sugar
    Coffee* sugarMilkCoffee = new SugarDecorator(milkCoffee);
    std::cout << "Sugar Milk Coffee: " << sugarMilkCoffee->getDescription() << ", Cost: $" << sugarMilkCoffee->cost() << std::endl;

    delete simpleCoffee;
    delete milkCoffee;
    delete sugarMilkCoffee;

    return 0;
}
