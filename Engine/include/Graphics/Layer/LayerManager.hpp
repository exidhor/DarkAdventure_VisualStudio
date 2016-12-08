#pragma once

#ifndef DEF_DISPLAY_MANAGER_HPP
#define DEF_DISPLAY_MANAGER_HPP

#include "Config.hpp"
#include "Graphics/Layer/Layer.hpp"
#include "Graphics/Render/DisplayPackage.hpp"
#include "Graphics/Layer/LayerFactory.hpp"


namespace dae
{
    namespace graphics
    {        
        /*!
         * \class   LayerManager
         * \brief   It keeps stored the different layers and allowed
         *			them to be fill with vertices and then display.
         */
        class ENGINE_API LayerManager
        {
            friend class Drawer; // to be able to access to the layer values
			friend class DEBUG_GraphicsView; // to be able to display internal infos

        public :
            /*!
             * \brief   Construct the DisplayManager with default values.
             * \warning The defaut layer capacity is set to 0 (no reserve of memory)
             */
            LayerManager();

            /*!
             * \brief   Construct the DisplayManager.
             * \param   layerCapacity : the capacity we reserve in the layer array
             * \param   defaultVertexCapacity : the default capacity for the vertex array
             *			in the layer. it means that each layer will reserve this capacity 
             *			when no capacity is specified (starting value is 0)
             * \param	defaultMergedDrawCapacity : the default capacity for the merged draw array
             *			in the layer. it means that each layer will reserve this capacity 
             *			when no capacity is specified (starting value is 0)
             */
            LayerManager(size_t layerCapacity, 
						 size_t defaultVertexCapacity,
						 size_t defaultMergedDrawCapacity);

	        /**
             * \brief	void
             */
            virtual ~LayerManager();

            /*!
             * \brief   Allocate or reallocate the layer array with the size.
             *			It can't reduce the capacity but extend it. It doesn't affect
             *			the data in the layer array.
             * \param   capacity : the number of layer it will allocate
             */
            void reserve(size_t capacity);

            /*!
             * \brief   Prepare the layers to be able to draw the next frame
             * \warning This has to be call before any "draw"
             * \warning This may be slow if new layers have just been added.
             */
            void prepare();

            /*!
             * \brief   Construct a layer in the array, reserving the
             *          default capacity.
             * \param   depthLevel : the level of depth (to determine
             *          the order of drawing)
			 * \param	key : the key which identify the layer
             * \warning The key and the depth level hase to be unique
             */
            void addLayer(unsigned depthLevel,
                          std::string const& key);

            /*!
             * \brief   Construct a layer in the array, reserving a 
             *			specific capacity for the Layer.
             * \param   depthLevel : the level of depth (to determine
             *          the drawing order)
			 * \param   vertexCapacity : the capacity reserved for the vertex array
			 * \param	key : the key which identify the layer
			 * \warning The key and the depth level hase to be unique
             */
            void addLayer(unsigned depthLevel,
                          size_t vertexCapacity,
						  std::string const& key);
			
			/*!
			* \brief	Construct a layer in the array, reserving a 
             *			specific size for the Layer and for the number of
             *			different draw.
			* \param	depthLevel : the level of depth (to determine
			*			the drawing order).
			* \param	vertexCapacity : the capacity reserved for the vertex array
			* \param	mergedDrawCapacity : the capacity reservedfor the merged
			*			draw array in the layer.
			* \param	key : the key which identify the layer
			* \warning The key and the depth level hase to be unique
			*/
			void addLayer(unsigned depthLevel,
						  size_t vertexCapacity,
						  size_t mergedDrawCapacity,
						  std::string const& key);

            /*!
             * \brief   fill a layer with some vertices
             * \param   displayPackage : some data to find the right
             *          layer.
             * \param   vertexArray : vertices will be fit into the
             *          layer.
             */
            void addVertices(DisplayPackage & displayPackage,
                             VertexArray const& vertexArray);

            /*!
             * \brief   Set the default capacity for the vertex array in the layers.
			 * \param   vertexCapacity : the default capacity for the vertex array
			 *			in the layer. it means that each layer will reserve this capacity
			 *			when no capacity is specified (starting value is 0)
             */
            void setDefaultVertexCapacity(size_t vertexCapacity);

			/*!
			* \brief	Set the default capacity for the merged draw array in the layers
			* \param	mergedDrawCapacity : the default capacity for the merged draw array
			*			in the layer. it means that each layer will reserve this capacity
			*			when no capacity is specified (starting value is 0)
			*/
			void setDefaultMergedDrawCapacity(size_t mergedDrawCapacity);

            /*!
             * \return  Returns the number of layers
             */
            size_t size() const;
        
        private :
            /*!
             * \brief   Remove all the vertices from the layers
             */
            void clearLayers();

			LayerFactory m_layerFactory;

			size_t	m_defaultVertexCapacity;
			size_t	m_defaultMergedDrawCapacity;
			bool	m_needToBeSorted;
        };
        
    }
}

#endif // DEF_DISPLAY_MANAGER_HPP