#pragma once

#ifndef DEF_VEC_2_HPP
#define DEF_VEC_2_HPP

#include "Config.hpp"

namespace dae
{
	namespace utils
	{
		template <typename T>
		class ENGINE_API Vec2
		{
		public:

			Vec2();


			Vec2(T X, T Y);


			template <typename U>
			explicit Vec2(const Vec2<U>& vector);


			T x; ///< X coordinate of the vector
			T y; ///< Y coordinate of the vector

			static double dotProduct(Vec2<T> const& a, Vec2<T> const& b);
		};


		template <typename T>
		Vec2<T> operator -(const Vec2<T>& right);


		template <typename T>
		Vec2<T>& operator +=(Vec2<T>& left, const Vec2<T>& right);


		template <typename T>
		Vec2<T>& operator -=(Vec2<T>& left, const Vec2<T>& right);


		template <typename T>
		Vec2<T> operator +(const Vec2<T>& left, const Vec2<T>& right);

		template <typename T>
		Vec2<T> operator -(const Vec2<T>& left, const Vec2<T>& right);

		template <typename T>
		Vec2<T> operator *(const Vec2<T>& left, T right);

		template <typename T>
		Vec2<T> operator *(T left, const Vec2<T>& right);

		template <typename T>
		Vec2<T>& operator *=(Vec2<T>& left, T right);

		template <typename T>
		Vec2<T> operator /(const Vec2<T>& left, T right);

		template <typename T>
		Vec2<T>& operator /=(Vec2<T>& left, T right);

		template <typename T>
		bool operator ==(const Vec2<T>& left, const Vec2<T>& right);

		template <typename T>
		bool operator !=(const Vec2<T>& left, const Vec2<T>& right);

		//#include "Utils/Container/Vec2.inl"

		// Define the most common types
		typedef Vec2<int>          Vec2i;
		typedef Vec2<unsigned int> Vec2u;
		typedef Vec2<float>        Vec2f;

	}
}

#endif // DEF_VEC_2_HPP
