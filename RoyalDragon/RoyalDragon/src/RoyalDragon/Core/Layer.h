#pragma once

#include "Base.h"

namespace RoyalDragon {

    /**
     * @brief Ӧ�ó���ͼ���ջ�е�ͼ�㡣
     *
     * This class represents a layer in the application's layer stack.
     * Layers can be attached to the application to provide specific functionality.
     */
    class ROYALDRAGON_API Layer
    {
    public:
        /**
         * @brief ����һ���µ�ͼ�����
         *
         * @param name ͼ������ơ�
         * @param name The name of the layer.
         */
        Layer(const std::string& name = "Layer");

        /**
         * @brief Layer ���������������
         *
         * Virtual destructor for the Layer class.
         */
        virtual ~Layer();

        /**
         * @brief ��ͼ�㸽�ӵ�Ӧ�ó���ʱ���á�
         *
         * Called when the layer is attached to the application.
         */
        virtual void onAttach() {}

        /**
         * @brief ��ͼ���Ӧ�ó����з���ʱ���á�
         *
         * Called when the layer is detached from the application.
         */
        virtual void onDetach() {}

        /**
         * @brief ��ͼ����Ҫ����ʱ���á�
         *
         * Called when the layer needs to be updated.
         */
        virtual void onUpdate() {}

        /**
         * @brief ���¼�����ʱ���á�
         *
         * @param event �������¼���
         * @param event The event that occurred.
         */
        virtual void OnEvent(Event& event) {}

        /**
         * @brief ��ȡͼ������ơ�
         *
         * @return ͼ������ơ�
         * @return The name of the layer.
         */
        inline const std::string& GetName() const { return m_DebugName; }

    private:
        std::string m_DebugName; /**< ͼ������ơ�The name of the layer. */
    };

} // namespace RoyalDragon
