﻿#include "dustpch.h"
#include "LayerStack.h"

Dust::LayerStack::LayerStack()
{
    m_LayerInsert = m_Layers.begin();
}

Dust::LayerStack::~LayerStack()
{
    if (!m_Layers.empty())
    {
        for (Layer* layer : m_Layers)
        {
            delete layer;
        }
    }
}

void Dust::LayerStack::PushLayer(Layer* layer)
{
    m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
}

void Dust::LayerStack::PushOverlay(Layer* overlay)
{
    m_Layers.emplace_back(overlay);
}

void Dust::LayerStack::PopLayer(Layer* layer)
{
    LayersListIterator it = std::find(m_Layers.begin(), m_Layers.end(), layer);
    if (it != m_Layers.end())
    {
        m_Layers.erase(it);
        m_LayerInsert--;
    }
}

void Dust::LayerStack::PopOverlay(Layer* overlay)
{
    LayersListIterator it = std::find(m_Layers.begin(), m_Layers.end(), overlay );
    if (it != m_Layers.end())
    {
        m_Layers.erase(it);
    }
}
