#pragma once

#include "Base.h"

namespace RoyalDragon {

    /**
     * @brief 应用程序图层堆栈中的图层。
     *
     * This class represents a layer in the application's layer stack.
     * Layers can be attached to the application to provide specific functionality.
     */
    class ROYALDRAGON_API Layer
    {
    public:
        /**
         * @brief 构造一个新的图层对象。
         *
         * @param name 图层的名称。
         * @param name The name of the layer.
         */
        Layer(const std::string& name = "Layer");

        /**
         * @brief Layer 类的虚析构函数。
         *
         * Virtual destructor for the Layer class.
         */
        virtual ~Layer();

        /**
         * @brief 当图层附加到应用程序时调用。
         *
         * Called when the layer is attached to the application.
         */
        virtual void onAttach() {}

        /**
         * @brief 当图层从应用程序中分离时调用。
         *
         * Called when the layer is detached from the application.
         */
        virtual void onDetach() {}

        /**
         * @brief 当图层需要更新时调用。
         *
         * Called when the layer needs to be updated.
         */
        virtual void onUpdate() {}

        /**
         * @brief 当事件发生时调用。
         *
         * @param event 发生的事件。
         * @param event The event that occurred.
         */
        virtual void OnEvent(Event& event) {}

        /**
         * @brief 获取图层的名称。
         *
         * @return 图层的名称。
         * @return The name of the layer.
         */
        inline const std::string& GetName() const { return m_DebugName; }

    private:
        std::string m_DebugName; /**< 图层的名称。The name of the layer. */
    };

} // namespace RoyalDragon
