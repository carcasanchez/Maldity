#ifndef __MOVE_H__
#define __MOVE_H__

#include "Double-Linked List.h"
#include "Entity.h"

void Move(List <Entity*>& source, List <Entity*>& destination, const Entity* entity)
{
	List <Entity*> ::Node* n = source.first;


	while (n != nullptr)
	{
		List <Entity*> ::Node* tmp = n->next;

		if (n->data == entity)
		{
			destination.PushBack(n->data);
			source.Erase(n);
		}

		n = tmp;
	}


}

#endif