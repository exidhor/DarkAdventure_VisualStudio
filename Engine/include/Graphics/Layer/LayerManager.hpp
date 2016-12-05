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

		// todo : refactor the doc
        
        /*!
         * \class   LayerManager
         * \brief   // todo
         */
        class ENGINE_API LayerManager
        {
            friend class Drawer; // to be able to access to the layer values

        public :
            /*!
             * \brief   Construct the DisplayManager with default values.
             * \warning The defaut layer size is set to 0
             */
            LayerManager();

            /*!
             * \brief   Construct the DisplayManager.
             * \param   numberOfLayer : the size we reserve in the array
             * \param   defaultVertexLayerSize : the default size of the layer
             *          it means that each layer will reserve this size
             *          when they are constructed
             * \param	defaultDifferentVertexSize : the default number of 
             *			different draw we will reserved.
             */
            LayerManager(unsigned numberOfLayer, 
						   unsigned defaultVertexLayerSize,
						   unsigned defaultDifferentVertexSize);

            virtual ~LayerManager();

            /*!
             * \brief   Allocate or reallocate the array with the size
             * \param   size : the number of layer it will allocate
             */
            void reserve(unsigned size);

            /*!
             * \brief   Prepare the layer for the next display of the
             *          frame.
             * \warning This has to be call before any "draw"
             * \warning This may be slow if layers are not sorted
             */
            void prepare();

            /*!
             * \brief   Construct a layer in the array, reserving the
             *          default size (set in the DisplayManager).
             * \param   depthLevel : the level of depth (to determine
             *          the order of drawing)
			 * \param	key : the key which identify the layer
             * \warning This combinaison of arguments has to be
             *          new in this manager to fit well in the map.
             */
            void addLayer(unsigned depthLevel,
                          std::string const& key);

            /*!
             * \brief   Construct a layer in the array, reserving a 
             *			specific size for the Layer.
             * \param   depthLevel : the level of depth (to determine
             *          the drawing order)
			 * \param   vertexLayerSize : the size reserved for the Layer.
			 * \param	key : the key which identify the layer
             * \warning This combinaison of arguments has to be
             *          new in this manager to fit well in the map.
             */
            void addLayer(unsigned depthLevel,
                          unsigned vertexLayerSize,
						  std::string const& key);
			
			/*!
			* \brief	Construct a layer in the array, reserving a 
             *			specific size for the Layer and for the number of
             *			different draw.
			* \param	depthLevel : the level of depth (to determine
			*			the drawing order).
			* \param	vertexLayerSize : the size reserved for the Layer.
			* \param	differentVertexSize : the number of different 
             *			draw we will reserved.
			* \param	key : the key which identify the layer
			* \warning	This combinaison of arguments has to be
			*			new in this manager to fit well in the map.
			*/
			void addLayer(unsigned depthLevel,
						  unsigned vertexLayerSize,
						  unsigned differentVertexSize,
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
             * \brief   Set the default size for the layer.
             *          This size will be allocate by default
             *          when new layer will be constructed
             * \param   vertexLayerSize : the new default size for layer
             */
            void setDefaultVertexLayerSize(unsigned vertexLayerSize);

			/*!
			* \brief   Set the default number of different Render arg.
			* \param   differentVertexSize : the new default differenteVertexSize
			*/
			void setDefaultDifferentVertexSize(unsigned differentVertexSize);

            /*!
             * \return  Returns the number of layer in the DisplayManager
             */
            unsigned size() const;

        protected :
        
        private :
            /*!
             * \brief   Remove all the vertices in the layers
             */
            void clearLayers();

			//LayerArray	m_layerArray;
			LayerFactory m_layerFactory;

            unsigned	m_defaultVertexLayerSize;
			unsigned	m_defaultDifferentVertexSize;
			bool		m_needToBeSorted;
        };
        
    }
}

#endif // DEF_DISPLAY_MANAGER_HPP