

	template <typename T>
	myVector<T>::myVector()
	{
		m_vector = new T[1];
		capacity = 1;
		size = 0;
		empty = false;
	}
	template <typename T>
	myVector<T>::myVector(const myVector& copySource)
	{
		this->m_vector = copySource.m_vector;
		this->capacity = copySource.capacity;
		this->size = copySource.size;
		this->empty = copySource.empty;
	}

	template <typename T>
	 myVector<T>:: ~myVector()
	{
		delete[] m_vector;
	}
	template <typename T>
	myVector<T> myVector<T>::getObj()
	{
		 return this->m_vector; 
	}
	template <typename T>
	int myVector<T>::getCapacity()
	{
		return this->capacity;
	}

	template <typename T>
	int myVector<T>::getSize()
	{
		return size;
	}

	template <typename T>
	bool myVector<T>::clear()
	{
		size = 0;
		return true;
	}
	template <typename T>
	bool myVector<T>::insert(T member, int index)   
	{
		if (index == capacity)
			push_back(member);
		else
			m_vector[index] = member;
		if (m_vector[index] == NULL)
		{
			return EXIT_FAILURE;
		}
		else
		{
			return true;
		}
	}
    /* Add element at last */
	template <typename T>
	bool myVector<T>::push_back(T element)
	{
		bool IsAdded = false;
		/* Check if we have enough space */
		if (size == capacity)
		{
			T* temp = new T[capacity * 2];

			if (temp == NULL) 
			{
				
				return EXIT_FAILURE;
			}
			for (int i = 0; i < size; i++)
			{
				temp[i] = m_vector[i];
			}

			delete[] m_vector;
			capacity *= 2;
			m_vector = temp;
		}

		m_vector[size] = element;
		size++;
	
		return true;
	}
	

	template <typename T>
	bool myVector<T>::pop_back()
	{
		size--;
		return true;
	}

	template <typename T>
	bool myVector<T>::resize()
	{
		if (capacity > size)
			capacity = size;
		return true;
	}

	
	template <typename T>
	T& myVector<T>::operator[](int index )
	{
		if (index > size)
		{
			std::cout << "Index out of bound" << std::endl;
			return m_vector[1];
		}
		else 
		{
			return m_vector[index];
		}
	}

	template <typename T>
	T& myVector<T>::operator++()
	{
		if (position < (size - 1))
			++position;
		return m_vector[position];
	}

	template <typename T>
	T& myVector<T>::operator--()
	{
		if (position > 0) --position;
		return m_vector[position];
	}

	template <typename T>
	bool myVector<T>::operator+=(T m_vector)
	{
		push_back(m_vector);
		return true;
	}

	template <typename T>
	bool myVector<T>::operator-=(T m_vector)
	{
		myVector *temp;
		size++;
		for (int i = 0; i < size-1; i++)
		{
			temp[i + 1] = m_vector[i];
		}
		delete[] m_vector;
		m_vector = temp;
		return true;
	}

	template<typename T>
	int myVector<T>::getPosition()
	{
		return this->position;
	}


	template <typename T>
	std::ostream& operator<<(std::ostream &os, myVector<T> &vec)
	{
		std::cout << "Le vecteur contient: " << std::endl;
		for (int i = 0; i < vec.getSize(); i++)
		{
			os << "Vecteur[" << i << "] = " << vec[i] << std::endl;
		}
	
		return os;
	}
	


