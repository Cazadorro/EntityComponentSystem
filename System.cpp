//
// Created by Shae Bolt on 2/28/2017.
//

#include "System.h"

void PhysicsSystem::update() {
    for (PhysicsNode &node : m_nodes) {
        std::cout << "physics being done on node" << std::endl;
        std::cout << "\n\tPosition" << "\n\t\t x: " <<
                  node.m_position->m_x << "\n\t\t y: " <<
                  node.m_position->m_y << "\n\t\t z: " <<
                  node.m_position->m_z << std::endl;
        std::cout << "\n\tVelocity " << node.m_velocity->m_velocity
                  << std::endl;
        node.m_position->m_x += node.m_velocity->m_velocity;
        std::cout << "updating x based on velocity " << node.m_position->m_x <<
        std::endl;


    }
}


void InputSystem::update() {
    for (InputNode &node : m_nodes) {
        std::cout << "input being done on node" << std::endl;
        std::cout << "\n\tInput " <<
                  (*node.m_input->m_input_ptr) << std::endl;
        std::cout << "\n\tVelocity " << node.m_velocity->m_velocity
                  << std::endl;


        double velocity = 0;
        if(*node.m_input->m_input_ptr == "move left"){
            velocity = 1;
        }
        else if(*node.m_input->m_input_ptr == "move right"){
            velocity = -1;
        }
        else if(*node.m_input->m_input_ptr == "stop"){
            velocity = 0;
        }
        else{
            std::cout << "unrecognized input" << std::endl;
        }
        node.m_velocity->m_velocity = velocity;
        std::cout << "velocity based on input " << node
                .m_velocity->m_velocity << std::endl;
    }
}
