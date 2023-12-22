#include <iostream>
#include <memory>

// Prototype
class Prototype {
public:
  virtual ~Prototype() {}
  virtual std::unique_ptr<Prototype> clone() const = 0;
  virtual void print() const = 0;
};

// Concrete Prototype
class ConcretePrototype : public Prototype {
private:
  int field;

public:
  ConcretePrototype(int field) : field(field) {}

  // Copy Constructor
  ConcretePrototype(const ConcretePrototype &other) : field(other.field) {}

  // Cloning method
  std::unique_ptr<Prototype> clone() const override {
    return std::make_unique<ConcretePrototype>(*this);
  }

  void print() const override {
    std::cout << "Field value: " << field << std::endl;
  }
};

// Client code
int main() {
  Prototype *prototype = new ConcretePrototype(100);
  std::unique_ptr<Prototype> clonedPrototype = prototype->clone();

  prototype->print();
  clonedPrototype->print();

  return 0;
}
