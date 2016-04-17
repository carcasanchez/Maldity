#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <assert.h>


template <typename type>
class Vector
{
private:
	type* elements = nullptr;
	unsigned int num_elements = 0;
	unsigned int mem = 10;
	


public:

	Vector()
	{
		elements = new type[mem];
	}

	Vector(const int num)
	{
		mem = num;
		num_elements = num;

		elements= new type[num];


	}

	Vector(const Vector<type>& other)
	{
		num_elements = other.num_elements;

		if (mem < other.mem)
			elements = new type[other.mem];

		mem = other.mem;

		for (int i = 0; i < num_elements; i++)
			elements[i] = other.elements[i];
	}



	~Vector()
	{
		delete[] elements;
	}

	type operator[](int pos) const
	{

		//assert(num_elements<pos);
		return elements[pos];

	}

	type& operator[](int pos)
	{

		//assert(num_elements<pos);
		return elements[pos];

	}

	void PushBack(const type& element)
	{


		if (num_elements == mem)
		{
			type* new_elements;

			new_elements = new type[mem + 10];

			for (int i = 0; i < mem; i++)
				new_elements[i] = elements[i];

			mem += 10;

			delete[] elements;
			elements = new_elements;
		}
		elements[num_elements] = element;
		num_elements++;
	}

	void PushFront(const type& element)
	{

		num_elements++;

		if (num_elements > mem)
		{
			type* new_elements;
			mem += 10;
			new_elements = new type[mem];

			for (int i = num_elements; i >= 0; i--)
				new_elements[i + 1] = elements[i];


			delete[] elements;
			elements = new_elements;

		}

		else for (int i = num_elements; i > 0; i--)
			elements[i] = elements[i - 1];


		elements[0] = element;
		num_elements++;

	}

	bool Empty()
	{
		if (num_elements == 0)
			return true;
		else return false;
	}

	void Clean()
	{
		num_elements = 0;
	}

	bool PopBack(type& value)
	{
		if (num_elements > 0)
		{
			num_elements--;
			value = elements[num_elements];

		}

		else return false;
	}

	void Shrink_to_fit()
	{
		type* temp;
		temp = new type[num_elements];
		mem = num_elements;

		for (int i = 0; i < num_elements; i++)
			temp[i] = elements[i];

		delete[] elements;
		elements = temp;


	}


};

#endif
