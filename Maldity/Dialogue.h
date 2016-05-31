#ifndef __DIALOGUE_H__
#define __DIALOGUE_H__

#include "MyString.h"
#include "Vector.h"

class Dialogue
{
public:

	class Node{
	public:
		String title;
		String text;
		Vector <Node*> option;
		Node* next = nullptr;
		

		Node(const char* text, const char* title, Node* next) 
		{
			this->text = text;
			this->title = title;
			this->next = next;
		}

		~Node()
		{
			for (int i = 0, j = option.Size(); i < j; i++)
			{
				delete option[i];
			}
		}

	};

public:

	Vector <Node*> lines;
	Node* current;


	Dialogue(const char* text)
	{
		Node* first = new Node(text, "first", 0);

		lines.PushBack(first);

	}

	~Dialogue()
	{		//TODO
		/*int size = lines.Size();
		for (int i = 0; i < size; i++)
		{
			delete lines[i];
		}*/
	}

	void AddLine(const char* title, const char* text, int previous, int next)
	{
		Node* new_line = nullptr;

		if (next == -1) new_line = new Node(text, title, nullptr);
		else new_line = new Node(text, title, lines[next]);

		lines.PushBack(new_line);

		lines[previous]->option.PushBack(new_line);
	}
		
};




#endif