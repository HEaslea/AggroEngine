
#pragma once

// All the Layers here

#define MAX_LAYER_STACKS 10u
 
#include <iostream>
#include <array>
#include <vector>
#include <any> 

namespace Layers
{ 
    template <typename InnerType> 
    class LayerEnt
    { 
        InnerType _data;

    public: 
        using held_type = InnerType;

        LayerEnt(InnerType const& t);

        LayerEnt(InnerType&& t); 
         
        void printOut();
    };

    // imps -> see inclusion model in C++ Templates (The Complete Guide)
    template <typename InnerType> 
    LayerEnt<InnerType>::LayerEnt(InnerType const& t) : _data(t) {}


    template <typename InnerType> 
    LayerEnt<InnerType>::LayerEnt(InnerType && t) : _data(std::move(t)) {}


    class LayerStack
    { 
    public:
        static LayerStack& instance();

        void testOut();

        // TODO : the std::any will have to change to Entity later on, with ECS
        std::array<std::vector<std::any>, MAX_LAYER_STACKS> _layer_stack;

    private: 
        LayerStack();

        LayerStack(LayerStack const&) = delete;
        LayerStack& operator=(LayerStack const&) = delete;

        LayerStack(LayerStack&&) = delete;
        LayerStack& operator=(LayerStack&&) = delete;
    };
}