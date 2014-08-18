#ifndef __VERTEX_ELEMENT_H__
#define __VERTEX_ELEMENT_H__

namespace DIR
{
	enum VertexElementType
	{
		VET_FLOAT1 = 0,
	};

	enum VertexElementSemantic
	{
		VES_POSISTION = 0,
	};

	class VertexElement
	{
	public:
		VertexElement();
		VertexElement(unsigned short source,
					size_t offset,
					VertexElementType type,
					VertexElementSemantic semantic,
					unsigned short index = 0);
		~VertexElement();

		unsigned short GetSource() const { return m_source; }
		size_t GetOffset() const { return m_offset; }
		VertexElementType GetVertexElementType() const { return m_type; }
		VertexElementSemantic GetVertexElementSemantic() const { return m_semantic; }
		unsigned short GetIndex() const { return m_index; }

	protected:
		unsigned short m_source;
		size_t m_offset;
		VertexElementType m_type;
		VertexElementSemantic m_semantic;
		unsigned short m_index;
	};
}

#endif