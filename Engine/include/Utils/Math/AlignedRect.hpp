#pragma once

#include "Config.hpp"
#include "Utils/Container/Vec2.hpp"

namespace dae
{
	namespace utils
	{
		 class ENGINE_API AlignedRect
		 {
		 public :
			 float left;
			 float top;
			 float width;
			 float height;

			 AlignedRect()
				 : AlignedRect(0, 0, 0, 0)
			 {
				 // nothing
			 }

			 AlignedRect(float left, float top, float width, float height)
				 : left(left),
				   top(top),
				   width(width),
				   height(height)
		 	{
				 // nothing
			 }

			 Vec2f getSize() const
			 {
				 return Vec2f(width, height);
			 }

			 Vec2f getPosition() const
			 {
				 return Vec2f(left, top);
			 }
		 };
	}
}