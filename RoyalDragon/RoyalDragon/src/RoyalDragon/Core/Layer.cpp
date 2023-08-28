#include "rdpch.h"
#include "Layer.h"

namespace RoyalDragon {

    /**
     * @brief ����һ���µ�ͼ�����
     *
     * @param name ͼ������ơ�
     * @param name The name of the layer.
     */
    Layer::Layer(const std::string& name)
        : m_DebugName(name)
    {
    }

    /**
     * @brief Layer �������������
     *
     * Virtual destructor for the Layer class.
     */
    Layer::~Layer()
    {
    }

} // namespace RoyalDragon
