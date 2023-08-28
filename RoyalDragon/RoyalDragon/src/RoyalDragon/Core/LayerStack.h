#pragma once

#include "Base.h"
#include "Layer.h"

#include <vector>

namespace RoyalDragon {
    /**
     * @brief ��ʾӦ�ó���ͼ���ջ���ࡣ
     *
     * This class represents the layer stack of the application.
     */
    class ROYALDRAGON_API LayerStack
    {
    public:
        /**
         * @brief Ŀ���ǳ�ʼ��һ�����������Ա���ͼ���ջ�в���ͼ��ʱʹ�á����������ָ��ͼ���ջ�Ŀ�ͷ��
         *
         * The purpose is to initialize an iterator for use when inserting layers into the layer stack.
         * This iterator points to the beginning of the layer stack.
         *
         * �ٸ����ӣ�
         * For example:
         *     �������ڶ�ջ����һЩͼ�㣬��������Ҫ����һ���µ�ͼ�㡣
         *     �����ֱ��ʹ�� m_Layers.PushLayer(newLayer)����ô��ͼ�㽫�ᱻ��ӵ���ջ��ĩβ��
         *     ���ǣ��������Ҫ������ͼ��Ĳ���λ�ã�������ĳ���ض�ͼ��֮ǰ���룬
         *     �����ʹ�� m_LayerInsert ��������ָ������λ�ã�
         *     Ȼ��ʹ�� insert ��������ͼ����뵽ָ��λ�á�
         *
         *     Suppose you have some layers in the stack, and you want to insert a new layer.
         *     If you directly use m_Layers.PushLayer(newLayer), the new layer will be added to the end of the stack.
         *     However, if you want to control the insertion position of the new layer, such as inserting before a specific layer,
         *     you can use the m_LayerInsert iterator to specify the insertion position,
         *     and then use the insert function to insert the new layer at the specified position.
         *
         * Constructor for the LayerStack class.
         */
        LayerStack();

        /**
         * @brief LayerStack �������������
         *
         * Destructor for the LayerStack class.
         */
        ~LayerStack();

        /**
         * @brief ��ͼ��ѹ���ջ��
         *
         * Pushes a layer onto the stack.
         *
         * @param layer Ҫѹ���ͼ�㡣
         * @param layer The layer to push.
         */
        void PushLayer(Layer* layer);

        /**
         * @brief ������ͼ��ѹ���ջ��
         *
         * Pushes an overlay layer onto the stack.
         *
         * @param overlay Ҫѹ��ĵ���ͼ�㡣
         * @param overlay The overlay layer to push.
         */
        void PushOverlay(Layer* overlay);

        /**
         * @brief �Ӷ�ջ�е���ͼ�㡣
         *
         * Pops a layer from the stack.
         *
         * @param layer Ҫ������ͼ�㡣
         * @param layer The layer to pop.
         */
        void PopLayer(Layer* layer);

        /**
         * @brief �Ӷ�ջ�е�������ͼ�㡣
         *
         * Pops an overlay layer from the stack.
         *
         * @param overlay Ҫ�����ĵ���ͼ�㡣
         * @param overlay The overlay layer to pop.
         */
        void PopOverlay(Layer* overlay);

        /**
         * @brief ���ص�����ָ���ջ�Ŀ�ͷ��
         *
         * Returns an iterator pointing to the beginning of the stack.
         *
         * @return ������ָ���ջ�Ŀ�ͷ��
         * @return An iterator pointing to the beginning of the stack.
         */
        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }

        /**
         * @brief ���ص�����ָ���ջ��ĩβ��
         *
         * Returns an iterator pointing to the end of the stack.
         *
         * @return ������ָ���ջ��ĩβ��
         * @return An iterator pointing to the end of the stack.
         */
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers; /**< ͼ���ջ��The stack of layers. */
        std::vector<Layer*>::iterator m_LayerInsert; /**< ͼ������������The layer insertion iterator. */
    };

} // namespace RoyalDragon
