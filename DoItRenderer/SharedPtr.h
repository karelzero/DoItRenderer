#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

namespace DIR
{
	template<class T>
	class SharedPtr
	{
	public:
		SharedPtr() : m_pRef(NULL), m_pUsed(NULL)
		{
		}

		SharedPtr(T* p) : m_pRef(NULL), m_pUsed(NULL)
		{
			if (p)
			{
				m_pRef = p;
				m_pUsed = new unsigned int(1);
				*m_pUsed = 1;
			}
		}

		SharedPtr(const SharedPtr& sp) : m_pRef(NULL), m_pUsed(NULL)
		{
			Copy(sp);
		}

		template<Class C>
		SharedPtr(const SharedPtr<C>& sp)
		{
			m_pRef = sp->GetPtr();
			m_pUsed = sp->GetCount();
			if (m_pUsed)
				++(*m_pUsed);
		}

		~SharedPtr()
		{
			Release();
		}

		SharedPtr& operator=(const SharedPtr& sp)
		{
			if (m_pRef == sp.m_pRef)
				return *this;

			Copy(sp);
			return *this;
		}

		void SetNull()
		{
			if (m_pRef)
			{
				Release();
				m_pRef = NULL;
				m_pUsed == NULL;
			}
		}

		inline T& operator*() { assert(m_pRef); return *m_pRef; }
		inline T* operator->() { assert(m_pRef); return m_pRef; }

		inline bool IsNull() { return m_pRef == NULL; }
		inline T* GetPtr() const { return m_pRef; }
		inline unsigned int GetCount() const { assert(m_pUsed); return *m_pUsed; }
		
	protected:
		void Copy(const SharedPtr& sp)
		{
			m_pRef = sp.m_pRef;
			m_pUsed = sp.m_pUsed;
			if (m_pUsed)
				++(*m_pUsed);
		}

		void Release()
		{
			if (m_pUsed)
			{
				if (*m_pUsed > 0)
					--(*m_pUsed);

				if (*m_pUsed == 0)
				{
					if (m_pRef)
						delete m_pRef;

					delete m_pUsed;

					m_pRef = NULL;
					m_pUsed = NULL;
				}
			}
		}

	protected:
		T* m_pRef;
		unsigned int* m_pUsed;
	};

	template<Class T, Class C>
	bool operator==(const SharedPtr<T>& l, const SharedPtr<C>& r)
	{
		return l.GetPtr() == r.GetPtr();
	}

	template<Class T, Class C>
	bool operator!=(const SharedPtr<T>& l, const SharedPtr<C>& r)
	{
		return l.GetPtr() != r.GetPtr();
	}

	template<Class T, Class C>
	bool operator<(const SharedPtr<T>& l, const SharedPtr<C>& r)
	{
		return l.GetPtr() < r.GetPtr();
	}
}
#endif