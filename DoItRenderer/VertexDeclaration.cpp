#include "VertexDeclaration.h"

namespace DIR
{

	VertexDeclaration::VertexDeclaration()
	{
	}

	VertexDeclaration::~VertexDeclaration()
	{
	}

	const VertexElement* VertexDeclaration::GetElement(size_t index) const
	{
		VertexElementList::const_iterator cIter = m_listElement.begin();
		for (size_t i = 0; i < index; ++i)
			++cIter;

		return (&*cIter);
	}
}