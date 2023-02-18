#include <iostream>
#include <memory>
/*
https://boost-experimental.github.io/di/cpp-london-2017/
https://github.com/stevef51/CPPServiceLocator
*/

/*
states that high-level modules should not depend on low-level modules, both should depend on abstractions. 
Abstractions should not depend on details, but details should depend on abstractions.
*/

namespace before
{

class GasEngine
{
public:
    void Start()
    {
        std::cout<<"I use gas as my fuel!"<<std::endl;
    }
};


class Car
{
public:
    Car()
    {
        std::shared_ptr<GasEngine> engine_ptr(new GasEngine());
        engine_ptr->Start();
    }
};
    //now upper module here is car and lower module in engine 
    // if we chnage type of engine(lower module) form gas to electric we should also change the upper module to meet this 


}//end of namespace before


namespace after
{
class IEngine
{
public:
    IEngine(){}

    void virtual Start(){}
};

class electricEngine: public IEngine
{
    void Start()
    {
        std::cout<<"I use electricity as my fuel!"<<std::endl;

    }
};

class gasEngine: public IEngine
{
    void Start()
    {
        std::cout<<"I use gas as my fuel!"<<std::endl;

    }
};


class Car
{
    IEngine *engine;
public:
    Car(IEngine *engine)
    {
        //std::shared_ptr<GasEngine> engine_ptr(new GasEngine());
        engine->Start();
    }
};

}
// but here if we chnage type of engine(lower module) form gas to electric 
// we don't need change the upper module to meet this as we use depency injection design pattern

int main()
{
//before

    std::shared_ptr<before::Car> car_ptr(new before::Car());

//after

    std::shared_ptr<after::IEngine> gasEngine_ptr(new after::gasEngine());
    std::shared_ptr<after::IEngine> electricEngine_ptr(new after::electricEngine());
    std::shared_ptr<after::Car> electricCar_ptr(new after::Car(electricEngine_ptr.get()));
    std::shared_ptr<after::Car> gasCar_ptr(new after::Car(gasEngine_ptr.get()));

}
