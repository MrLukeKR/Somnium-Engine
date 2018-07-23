#pragma once

#include <glew.h>
#include "../Maths/Maths.h"
#include "Shader.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexArray.h"
#include <vector>
#include <string>

namespace Somnium
{
	namespace Graphics
	{
		struct Vertex
		{
			Maths::Vector3 position;
			Maths::Vector3 normal;
			Maths::Vector2 texCoords;
		};

		struct Texture
		{
			GLuint id;
			std::string type;
		};

		class Mesh 
		{
		public:
			Mesh(Buffers::VertexArray* vertexArray, Buffers::IndexBuffer* indexBuffer, std::vector<Texture> textures, Shader& shader);
			Mesh(std::vector<GLfloat> vertexArray, std::vector<GLushort> indexBuffer, std::vector<Texture> textures, Shader& shader);
			~Mesh() { delete m_VAO; delete m_IBO; };

			const inline Buffers::VertexArray* getVAO() const { return m_VAO; }
			const inline Buffers::IndexBuffer* getIBO() const { return m_IBO; }

			const inline std::vector<GLfloat>& getVertexData() const { return m_VertexData; }
			const inline std::vector<GLushort>& getIndexData() const { return m_IndexData; }

			const inline size_t getIBOSize() const { return m_IBO->getCount(); }
			inline Shader& getShader() const { return m_Shader; }
			const Maths::Matrix4 getModelMatrix() const;

			void rotate(float xAngleOffset, float yAngleOffset, float zAngleOffset);
			void rotate(Maths::Vector3 rotationOffset);

			void setOrientation(float xAngle, float yAngle, float zAngle) { setOrientation(Maths::Vector3(xAngle, yAngle, zAngle)); }
			void setOrientation(Maths::Vector3 rotationOffset) { m_Orientation += rotationOffset; };

			void scale(float x, float y, float z);
			void scale(Maths::Vector3 scaleAmount);
			void scale(float uniformScale);

			void translate(float xOffset, float yOffset, float zOffset);
			void translate(Maths::Vector3 offset);

		private:
			Buffers::VertexArray* m_VAO;
			Buffers::IndexBuffer* m_IBO;

			std::vector<GLfloat> m_VertexData;
			std::vector<GLushort> m_IndexData;

			Shader& m_Shader;

			const std::vector<Texture> m_Textures;

			Maths::Vector3 m_Orientation = Maths::Vector3(0, 0, 0);

			Maths::Matrix4 m_ModelMatrix = Maths::Matrix4::identity();
		};
	}
}
