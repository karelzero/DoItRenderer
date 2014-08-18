#include "VertexElement.h"

namespace DIR
{
	VertexElement::VertexElement()
	{
	}

	VertexElement::VertexElement(unsigned short source, size_t offset, VertexElementType type, VertexElementSemantic semantic, unsigned short index /*= 0*/)
		: m_source(source)
		, m_offset(offset)
		, m_type(type)
		, m_semantic(semantic)
		, m_index(index)
	{
	}

	VertexElement::~VertexElement()
	{
	}
}