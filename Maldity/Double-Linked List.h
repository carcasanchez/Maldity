#ifndef LIST
#define LIST

	
template <typename TYPE>
class List
{
public:

	struct Node
	{
		TYPE data;
		Node* next = nullptr;
		Node* prev = nullptr;


		Node(const TYPE& data) : data(data)
		{};

		~Node(){};

	};

	Node* first = nullptr;
	
public:

	List(){};
	~List(){};

	
	bool Empty() const
	{
		return first == nullptr;
	}

	unsigned int Size() const
	{
		Node* n;
		unsigned int ret = 0;

		n = first;

		if (first != nullptr);
			while (n != nullptr)
			{
				n = n->next;
				ret++;
			}

		return ret;
	}

	Node* End() const
	{
		Node* n;

		n = first;

		
			while (n->next != nullptr)
			{
				n = n->next;
			}

		return n;
	}

	void PushBack(const TYPE& element)
	{
		Node* new_element = new Node(element);
		Node* n = first;
		
		if (first == nullptr)
			first = new_element;
		else
		{
			while (n->next != nullptr)
			{
				n = n->next;
			}
			n->next = new_element;
			n->next->prev = n;
		}
	}
	
	void PushFront(const TYPE& element)
	{
		Node* new_element = new Node(element);
		new_element->next = first;
		first = new_element;
		
		if (first->next != nullptr)
			first->next->prev = first;
	}

	void PopBack()
	{
		Node* n = first;
		Node* n2 = first;

		if (first != nullptr)
		{
			if (first->next != nullptr)
			{
			
			while (n2->next != nullptr)
			{
				
				n2 = n2->next;
			}

			while (n->next != n2)
			{
				n = n->next;
			}


			n->next = nullptr;
			delete n2;
			
			}

			else
			{
				first = nullptr;
				delete n;
			}
		}


	}

	bool PopFront()
	{
	
		Node* temp=nullptr;

		if (first != nullptr)
		{
			temp = first->next;
			delete first;
			first = temp;	
			first->prev = nullptr;
			return true;
		}

		return false;
	}

	bool Erase(Node* other)
	{
		Node* n = nullptr;
		Node* n2 = nullptr;


		if (first != nullptr)
		{
			if (first == other)
			{

				if (first->next == nullptr)
				{
					delete first;
					first = nullptr;
					
				}
				
				else
				{
					n = first->next;
					delete first;
					first = n;
					first->prev = nullptr;

				}
				return true;
			}

			else if (first->next != nullptr)
			{
				n = first;
				n2 = first->next;

				while (n2 != other && n2->next != nullptr)
				{
					n = n->next;
					n2 = n2->next;
				}

				if (n2 == other)
				{
					n->next = n2->next;
					
					if (n->next != nullptr)
						n->next->prev = n;

					delete n2;

					return true;
				}
			}


		}

		return false;
	}

	bool Insert(const TYPE& element, int pos)
	{
		int i = 0;
		Node* n = first;
		Node* new_node = nullptr;

		if (pos == 0)
		{
			PushFront(element);
			return true;
		}

		else if (first != nullptr && pos>0)
		{
			for (i = 0; i < pos-1 && n->next != nullptr; i++)
			{
				n = n->next;
			}

			if (n->next == nullptr && i != pos - 1)
				return false;


			new_node = new Node(element);
					
			new_node->next = n->next;
			new_node->prev = n;
			n->next = new_node;

			if (new_node->next != nullptr)
				new_node->next->prev = new_node;
			
			return true;
		}

		return false;
	}

	void Clean()
	{
		Node* n = first;

		if (first != nullptr)
		{
			if (first->next != nullptr)
			 while (n->next != nullptr)
			{
				n = n->next;
				delete n->prev;
			}

			delete n;
			first = nullptr;
		}
	}

	Node* Iterate()
	{
		//TODO: arguments passing
	}

};


#endif

