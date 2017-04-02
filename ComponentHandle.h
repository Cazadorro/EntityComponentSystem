//
// Created by Shae Bolt on 3/25/2017.
//

#ifndef UNTITLED_COMPONENTHANDLE_H
#define UNTITLED_COMPONENTHANDLE_H

#include <vector>
#include <stdint.h>
#include <algorithm>
#include <assert.h>


//template<class ComponentClass>
//class ComponentPoolHandle {
//protected:
//    static ComponentPool <ComponentClass> m_pool;
//    uint64_t m_handle_index;
//    bool hasUpdated = false;
//
//    void lazyUpdate() {
//        if (m_pool.hasDefragged() && !hasUpdated) {
//            m_handle_index = m_pool.getSwappedPosition(m_handle_index);
//            m_pool.updateDefraggingStatus();
//        }
//        hasUpdated = m_pool.hasDefragged();
//    }
//
//    ComponentClass& dereference(){
//        lazyUpdate();
//        return m_pool[m_handle_index].getObject();
//    }
//
//public:
//    void kill() {
//        m_pool.killComponent(m_handle_index);
//        m_pool.attemptDefragment();
//    }
//
//    ComponentPoolHandle(const ComponentClass &component) {
//        m_handle_index = m_pool.addComponent(component);
//    }
//
//    ComponentClass &operator*() {
//        return dereference();
//    }
//
//    ComponentClass &operator->() {
//        return dereference();
//    }
//    //TODO add const versions
//    //TODO add arithmetic/comparison operators
//    //TODO +=, -= ++, --, +, -, ==, <, >, !=, >=, <=
//    //TODO add big four and a half.
//
//};
//
//template<class T>
//struct LiveObject{
//    bool m_alive;
//    T m_object;
//    bool isAlive(){return m_alive};
//    void kill(){m_alive = false;};
//    LiveObject(const T& object):m_alive(true), m_object(object){};
//    LiveObject & operator = (const LiveObject& live_object){
//        this->m_alive = live_object.m_alive;
//        this->m_object = live_object.m_object;
//    }
//    T& getObject(){return m_object};
//};
//
//template<class ComponentClass>
//class ComponentPool {
//protected:
//    std::vector<LiveObject<ComponentClass>> m_pool;
//    std::vector<uint64_t> m_swap_pos;
//    bool m_defragging;
//    uint64_t num_dead_components;
//    uint64_t total_reference_count;
//    uint64_t num_references_updated;
//
//    void defragment() {
//        m_swap_pos = std::vector<uint64_t>(m_pool.size(), 0);
//        std::vector<ComponentClass>::size_type first_dead_index = m_pool.size();
//        for (std::vector<ComponentClass>::size_type i = 0;
//             i < m_pool.size(); ++i) {
//            if (first_dead_index == m_pool.size()) {
//                if (m_pool[i].isAlive() == false) {
//                    first_dead_index = i;
//                }
//            } else {
//                if (m_pool[i].isAlive()) {
//                    std::iter_swap(m_pool.begin() + first_dead_index,
//                                   m_pool.begin() + i);
//                    m_swap_pos[i] = first_dead_index;
//                    first_dead_index += 1;
//                }
//            }
//        }
//        assert(((m_pool.size() / 2 + 4) < first_dead_index, "Error, expected "
//                "resize new size to be in line with high dead component "
//                "ratio"));
//        m_pool.resize(first_dead_index);
//        m_defragging = true;
//    }
//
//    bool deadComponentRatioHigh() {
//        return (num_dead_components > (m_pool.size() / 2 + 4));
//    }
//
//public:
//    ComponentClass &operator[](const uint64_t index) {
//        return m_pool[index];
//    }
//
//    ComponentClass &operator[](const uint64_t index) const {
//        return m_pool[index];
//    }
//
//    bool attemptDefragment() {
//        if (deadComponentRatioHigh()) {
//            defragment();
//            num_references_updated = 0;
//            return true;
//        }
//        return false;
//    }
//
//    bool updateDefraggingStatus() {
//        assert(((num_references_updated < total_reference_count), "Error, "
//                "can't update when done updating"));
//        num_references_updated += 1;
//        if (num_references_updated == total_reference_count) {
//            m_defragging = false;
//            m_swap_pos.clear();
//        }
//        return hasDefragged();
//    }
//
//    uint64_t getSwappedPosition(uint64_t index) {
//        assert((hasDefragged(), "Error, shouldn't get swapped position when "
//                "pool hasn't defragged"));
//        return m_swap_pos[index];
//    }
//
//    bool hasDefragged() {
//        return m_defragging;
//    }
//
//    void killComponent(uint64_t index) {
//        assert((m_pool[index].isAlive() == false, "error, Can't kill that "
//                "which is already dead"));
//        m_pool[index].kill();
//        num_dead_components += 1;
//        assert((num_dead_components <= m_pool.size(), "error, can't"
//                " have more dead components than components "));
//    }
//
//    uint64_t addComponent(const ComponentClass &component) {
//        m_pool.push_back(component);
//        return m_pool.size() - 1;
//    }
//
//    ComponentPool() : m_defragging(false), num_dead_components(0),
//                      total_reference_count(0), num_references_updated(0) {};
//};

#endif //UNTITLED_COMPONENTHANDLE_H
