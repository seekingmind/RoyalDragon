#include "rdpch.h"
#include "Layer.h"

namespace RoyalDragon {

    /**
     * @brief 构造一个新的图层对象。
     *
     * @param name 图层的名称。
     * @param name The name of the layer.
     */
    Layer::Layer(const std::string& name)
        : m_DebugName(name)
    {
    }

    /**
     * @brief Layer 类的析构函数。
     *
     * Virtual destructor for the Layer class.
     */
    Layer::~Layer()
    {
    }

} // namespace RoyalDragon
