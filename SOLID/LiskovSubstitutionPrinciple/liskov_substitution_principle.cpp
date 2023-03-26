/*The Interface Segregation Principle vs liskov substitution principle :
Interface Segregation Principle : focus on applying just the methods in interface ( should not work around by thow or empty method) 
liskov substitution Principle :focus on the bahvior of driven class methods due to implementation expected like the base class 
I mean driven class can be subtituted in stead of base class without diffent behvior (take into account the inherited methods that not overriden alongside with
the overriden methods for example getter in the down example
*/

// before

#include <iostream>

class Rectangle {
protected:
    int width;
    int height;

public:
    Rectangle(int width, int height) : width(width), height(height) {}

    virtual void setWidth(int width) {
        this->width = width;
    }

    virtual void setHeight(int height) {
        this->height = height;
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    int getArea() const {
        return width * height;
    }
};

class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) {}

    void setWidth(int width) override {
        this->width =  width;
    }

    void setHeight(int height) override {
        this->width = this->height = height;
    }
};

void process(Rectangle& r) {
    int width = r.getWidth();
    r.setHeight(10);
    std::cout << "Expected area = " << (width * 10) << ", got " << r.getArea() << std::endl;
}

int main() {
    Rectangle rectangle(5, 10);
    Square square(5);

    process(rectangle); // Expected area = 50, got 50
    process(square); // Expected area = 50, got 100

    return 0;
}



