#pragma once

#ifndef DEF_VERTEX_ARRAY_HPP
#define DEF_VERTEX_ARRAY_HPP

#include "Config.hpp"
//#include <c++/cstring>
#include <iostream>
#include <cassert>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Utils/Container/Vec2.hpp"
#include "Animations/Tile/Tile.hpp"

// todo : refactor the doc

namespace dae
{
    namespace graphics
    {
        /*!
         * \class VertexArray
         * \brief Store some vertices
         *
         */
        class VertexArray
        {
        public :

            /*!
             * \brief   Construct a void VertexArray.
             * \warning The internal array is not allocate (=nullptr)
             */
            VertexArray();

            /*!
             * \brief   Construct the VertexArray and allocate
             *          the array.
             * \param   size : the size to allocate
             */
            VertexArray(int size);

            VertexArray(std::vector<utils::Vec2f> const& vertexPosition);

            /*!
             * \brief   Construct the copy of a VertexArray, same size,
             *          same content.
             * \param   vertexArray : The VertexArray to copy
             */
            VertexArray(VertexArray const& vertexArray);

            /*!
             * \brief   Free the array memory
             */
            virtual ~VertexArray();

            /*!
             * \brief   Copy the content of a VertexArray into this one.
             * \param   vertexArray : the VertexArray to copy
             */
            void copy(VertexArray const& vertexArray);

            /*!
             * \brief   Access to the internal array
             * \param   index : the index of the case
             */
            sf::Vertex & operator[](unsigned index);

			/*!
			* \brief   Access to the internal array
			* \param   index : the index of the case
			*/
            sf::Vertex const& operator[](unsigned index) const;

            /*!
             * \brief   Set the size of the array.
             * \warning This method may allocate, then it
             *          can slow the process.
             * \param   vertexSize : The new size to set
             */
            void reserve(int vertexSize);

            void clear();

            void add(VertexArray const& vertexArray);

			void setTexturePoint(utils::AlignedRect const& rect);

            void setColor(sf::Color const& color);

            /*!
             * \brief   Check if the internal array is allocate.
             * \return  Return True if the internal array is not
             *          allocate and False otherwise.
             */
            bool isVoid() const;

            /*!
             * \brief   Return the size of the internal array
             * \return  the size of the internal array
             */
            unsigned getSize() const;

			unsigned getCapacity() const;

            sf::Color const& getColor() const;

        protected :

        private :
            /*!
             * \brief   Copy an Array into another one.
             * \warning The dest array HAS TO have at least the same size
             *          as the origin array.
             * \param   dest : the destination
             * \param   origin : the array which will be copied
             * \param   size : the size of the array
             */
            void static copyArray(sf::Vertex* dest, sf::Vertex* origin, int size);

            /*!
             * \brief   Copy the content of the origin vector to the dest vector
             * \param   dest : the vector which will get the value
             * \param   origin the vector where will will take the value from
             */
            void static copyArray(std::vector<sf::Vertex> & dest, std::vector<sf::Vertex> const& origin);

            /*!
             * \brief   Free the memory of the array, and then allocate.
             * \param   The size of the new array.
             */
            void reallocateArray(int size);

            std::vector<sf::Vertex> m_vertices;
        };
    }
}

#endif // DEF_VERTEX_ARRAY_HPP
