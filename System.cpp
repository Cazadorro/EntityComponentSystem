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
        std::cout << "\n\tVelocity " << node.m_velocity->m_magnitude
                  << std::endl;
        node.m_position->m_x += static_cast<int64_t>(node.m_velocity->m_x);
        node.m_position->m_y += static_cast<int64_t>(node.m_velocity->m_y);
        node.m_position->m_z += static_cast<int64_t>(node.m_velocity->m_z);

        std::cout << "updating x based on velocity " << node.m_position->m_x <<
                  std::endl;


    }
}


void InputSystem::update() {
    for (InputNode &node : m_nodes) {
        std::cout << "input being done on node" << std::endl;
        std::cout << "\n\tInput " <<
                  (*node.m_input->m_input_ptr) << std::endl;
        std::cout << "\n\tVelocity magnitude" << node.m_velocity->m_magnitude
                  << std::endl;

        if (*node.m_input->m_input_ptr == "l") {
            node.m_velocity->m_x = -1;
            node.m_velocity->m_y = 0;
            node.m_velocity->m_z = 0;
        } else if (*node.m_input->m_input_ptr == "r") {
            node.m_velocity->m_x = 1;
            node.m_velocity->m_y = 0;
            node.m_velocity->m_z = 0;
        } else if (*node.m_input->m_input_ptr == "u") {
            node.m_velocity->m_x = 0;
            node.m_velocity->m_y = -1;
            node.m_velocity->m_z = 0;
        } else if (*node.m_input->m_input_ptr == "d") {
            node.m_velocity->m_x = 0;
            node.m_velocity->m_y = 1;
            node.m_velocity->m_z = 0;
        } else if (*node.m_input->m_input_ptr == "s") {
            node.m_velocity->m_x = 0;
            node.m_velocity->m_y = 0;
            node.m_velocity->m_z = 0;
        } else {
            std::cout << "unrecognized input" << std::endl;
        }
        std::cout << "\n\tVelocity" << "\n\t\t x: " <<
                  node.m_velocity->m_x << "\n\t\t y: " <<
                  node.m_velocity->m_y << "\n\t\t z: " <<
                  node.m_velocity->m_z << std::endl;
    }
}

void DisplaySystem::update() {
    const int64_t width = 16;
    const int64_t height = 16;
    std::string map[16][16] = {{"."}};
    std::fill( &map[0][0], &map[16][0], ".");
    for (DisplayNode &node : m_nodes){
        const int64_t j = node.m_position->m_x;
        const int64_t i = node.m_position->m_y;
        if(i < height && i >= 0 && j < width && j >= 0){
            map[i][j] = node.m_displaychar->m_displaychar;
        }
    }
    std::cout << std::endl;
    for(int64_t i = 0; i < height; ++i){
        for(int64_t j = 0; j < width; ++j){
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}