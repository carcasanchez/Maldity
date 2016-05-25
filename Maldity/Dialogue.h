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
		int index;

		Node(const char* text, const char* title, int index) : index (index)
		{
			this->text = text;
			this->title = title;
		}

	};

public:

	Vector <Node*> lines;
	int index;


	Dialogue(const char* text)
	{
		Node* first = new Node(text, "first", 0);

		lines.PushBack(first);
	}

	void AddLine(const char* title, const char* text, int previous, int index)
	{
		Node* new_line = new Node(text, title, index);

		lines.PushBack(new_line);

		lines[previous]->option.PushBack(new_line);
	}
		
};




#endif