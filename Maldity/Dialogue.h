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
		

		Node(const char* text, const char* title) 
		{
			this->text = text;
			this->title = title;
		}

	};

public:

	Vector <Node*> lines;
	Node* current;


	Dialogue(const char* text)
	{
		Node* first = new Node(text, "first");

		lines.PushBack(first);

	}

	void AddLine(const char* title, const char* text, int previous)
	{
		Node* new_line = new Node(text, title);

		lines.PushBack(new_line);

		lines[previous]->option.PushBack(new_line);
	}
		
};




#endif