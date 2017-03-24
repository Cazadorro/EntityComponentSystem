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
    player.addComponent(&input_component);
    player.addComponent(&pos_component);
    player.addComponent(&vel_component);
    player.addComponent(&name);
    player.addComponent(&dchar);

    PhysicsSystem physics;
    InputSystem input;
    DisplaySystem display;
    std::vector<System*> systems;
    systems.push_back(&input);
    systems.push_back(&physics);
    systems.push_back(&display);

    physics.registerEntity(player);
    input.registerEntity(player);
    display.registerEntity(player);

    while (input_string != "end"){
        std::getline(std::cin,input_string);
        for(auto system: systems){
            system->update();
        }
    }
    return 0;
}