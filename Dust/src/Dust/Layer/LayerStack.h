#pragma once

#include "dustpch.h"

#include "Layer.h"

namespace Dust
{

typedef std::vector<Layer*> LayersList;
typedef LayersList::iterator LayersListIterator;
    
    class DUST_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        LayersListIterator begin() { return m_Layers.begin(); }
        LayersListIterator end() { return m_Layers.end(); }
    private:
        LayersList m_Layers;
        LayersListIterator m_LayerInsert;
    };
    
}
