//
// Created by Michael Soliman on 05/05/2021.
//

#ifndef C_COMPONENT_H
#define C_COMPONENT_H

class IComponent {
public:
    virtual ~IComponent() = default;
    virtual void print(){
        std::cout<<"this is base class"<<'\n';
    };
};

class Transform : public IComponent {
public:
    void print() override{
        std::cout<<"this is of type Transform "<<'\n';
    };
};
class Renderer : public IComponent {
public:
    void print() override{
        std::cout<<"this is of type Renderer"<<'\n';
    };
};

#endif //C_COMPONENT_H
