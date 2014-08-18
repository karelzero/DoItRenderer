#ifndef __VERTEX_DECLARATION_H__
#define __VERTEX_DECLARATION_H__

#include "VertexElement.h"
#include <list>

namespace DIR
{
	class VertexDeclaration
	{
	public:
		typedef std::list<VertexElement> VertexElementList;

	public:
		VertexDeclaration();
		~VertexDeclaration();

		size_t GetElementCount() const { return m_listElement.size(); }
		const VertexElementList& GetElementList() const { return m_listElement; }
		const VertexElement* GetElement(size_t index) const;
	protected:
		VertexElementList m_listElement;
	};
}

#endif