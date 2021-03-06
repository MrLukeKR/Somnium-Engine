#pragma once

#include "../../Logic/Maths/Maths.h"
#include "../UI/UIObject.h"
#include "../UI/UIText.h"
#include "../UI/UIImage.h"
#include "Camera.h"

namespace Somnium
{
	namespace Graphics
	{
		namespace Cameras
		{
			class FirstPersonCamera : public Camera
			{
				/* Methods */
			public:
				FirstPersonCamera(const float fieldOfView, const float aspectRatio, const float near = 0.1f, const float far = 0.1f, const bool orthographic = false, Maths::Vector3 position = Maths::Vector3(), Maths::Vector3 orientation = Maths::Vector3());

				~FirstPersonCamera() {};

				void move(Direction direction);
				void move(Direction direction, float offset);
				void move(Maths::Vector3 displacement);

			private:
				float m_DefaultMoveDistance = 0.01f;
			};
		}
	}
}
