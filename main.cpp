#include <iostream>
#include "Component.h"
#include "ComponentNode.h"
#include "PositionComponent.h"
#include "Entity.h"
#include "Observer.h"
#include "System.h"
#include <iostream>

int main() {

    std::vector<Entity> entity_pool;
    std::vector<Component*> component_pool;
    std::cout << "Hello, World!" << std::endl;
    std::string input_string = "";

    Entity player;
    InputComponent input_component(&input_string);
    component_pool.push_back(&input_component);
    PositionComponent pos_component(0,0,0);
    component_pool.push_back(&pos_component);
    VelocityComponent vel_component(1.0,0,0,0);
    component_pool.push_back(&vel_component);
    NameComponent name("Entity_1");
    component_pool.push_back(&name);
    DisplayCharComponent dchar("@");
    component_pool.push_back(&dchar);
    player.addComponent(&input_component);
    player.addComponent(&pos_component);
    player.addComponent(&vel_component);
    player.addComponent(&name);
    player.addComponent(&dchar);

    Entity prop1;
    PositionComponent posc1(3,3,0);
    component_pool.push_back(&posc1);
    NameComponent name1("Prop1");
    component_pool.push_back(&name1);
    DisplayCharComponent dchar1("H");
    component_pool.push_back(&dchar1);

    prop1.addComponent(&posc1);
    prop1.addComponent(&name1);
    prop1.addComponent(&dchar1);


    Entity prop2;
    PositionComponent posc2(8,10,3);
    component_pool.push_back(&posc1);
    NameComponent name2("Prop2");
    component_pool.push_back(&name2);
    DisplayCharComponent dchar2("5");
    component_pool.push_back(&dchar2);

    prop2.addComponent(&posc2);
    prop2.addComponent(&name2);
    prop2.addComponent(&dchar2);

    PhysicsSystem physics;
    InputSystem input;
    DisplaySystem display;
    std::vector<System*> systems;
    systems.push_back(&input);
    systems.push_back(&physics);
    systems.push_back(&display);

    for(auto system: systems){
        system->registerEntity(player);
        system->registerEntity(prop1);
        system->registerEntity(prop2);
    }

    std::cout << player.m_lock.to_ulong() << std::endl;

    while (input_string != "end"){
        std::getline(std::cin,input_string);
        for(auto system: systems){
            system->update();
        }
    }
    return 0;
}