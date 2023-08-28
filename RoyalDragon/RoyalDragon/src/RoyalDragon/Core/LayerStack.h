#pragma once

#include "Base.h"
#include "Layer.h"

#include <vector>

namespace RoyalDragon {
    /**
     * @brief 表示应用程序图层堆栈的类。
     *
     * This class represents the layer stack of the application.
     */
    class ROYALDRAGON_API LayerStack
    {
    public:
        /**
         * @brief 目的是初始化一个迭代器，以便在图层堆栈中插入图层时使用。这个迭代器指向图层堆栈的开头。
         *
         * The purpose is to initialize an iterator for use when inserting layers into the layer stack.
         * This iterator points to the beginning of the layer stack.
         *
         * 举个例子：
         * For example:
         *     假设你在堆栈中有一些图层，并且你想要插入一个新的图层。
         *     如果你直接使用 m_Layers.PushLayer(newLayer)，那么新图层将会被添加到堆栈的末尾。
         *     但是，如果你想要控制新图层的插入位置，例如在某个特定图层之前插入，
         *     你可以使用 m_LayerInsert 迭代器来指定插入位置，
         *     然后使用 insert 函数将新图层插入到指定位置。
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
         * @brief LayerStack 类的析构函数。
         *
         * Destructor for the LayerStack class.
         */
        ~LayerStack();

        /**
         * @brief 将图层压入堆栈。
         *
         * Pushes a layer onto the stack.
         *
         * @param layer 要压入的图层。
         * @param layer The layer to push.
         */
        void PushLayer(Layer* layer);

        /**
         * @brief 将叠加图层压入堆栈。
         *
         * Pushes an overlay layer onto the stack.
         *
         * @param overlay 要压入的叠加图层。
         * @param overlay The overlay layer to push.
         */
        void PushOverlay(Layer* overlay);

        /**
         * @brief 从堆栈中弹出图层。
         *
         * Pops a layer from the stack.
         *
         * @param layer 要弹出的图层。
         * @param layer The layer to pop.
         */
        void PopLayer(Layer* layer);

        /**
         * @brief 从堆栈中弹出叠加图层。
         *
         * Pops an overlay layer from the stack.
         *
         * @param overlay 要弹出的叠加图层。
         * @param overlay The overlay layer to pop.
         */
        void PopOverlay(Layer* overlay);

        /**
         * @brief 返回迭代器指向堆栈的开头。
         *
         * Returns an iterator pointing to the beginning of the stack.
         *
         * @return 迭代器指向堆栈的开头。
         * @return An iterator pointing to the beginning of the stack.
         */
        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }

        /**
         * @brief 返回迭代器指向堆栈的末尾。
         *
         * Returns an iterator pointing to the end of the stack.
         *
         * @return 迭代器指向堆栈的末尾。
         * @return An iterator pointing to the end of the stack.
         */
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers; /**< 图层堆栈。The stack of layers. */
        std::vector<Layer*>::iterator m_LayerInsert; /**< 图层插入迭代器。The layer insertion iterator. */
    };

} // namespace RoyalDragon
