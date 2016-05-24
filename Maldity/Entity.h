#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "MyString.h"
#include "Double-Linked List.h"
#include <iostream>

enum Tipus{ ROOM, EQUIP_ITEM, NON_EQUIP_ITEM, NPC, PLAYER,  EXIT };
enum Cardinal {N, S, E, W, NONE};
class Entity{

public:

	String name;
	String description;
	Tipus type;
	

	List <Entity*> inside;

	Entity(){};

	Entity(const char* str1, const char* str2, Tipus type) : name(str1), description(str2), type(type){}

	virtual ~Entity(){};

	virtual void Look()
	{

		printf("%s",  description.C_str());
		if (type==NON_EQUIP_ITEM ||type==EQUIP_ITEM)
			for (List<Entity*>::Node *it = inside.first; it != nullptr; it = it->next)
			{
				printf("It has a %s inside.\n", it->data->name.C_str());
			}
	};
	
	virtual void Update(){};

	//This move entities from one list to another
	void Move(Entity* source, Entity* destination, const Entity* entity)
	{
		List <Entity*> ::Node* n = source->inside.first;


		while (n != nullptr)
		{
			List <Entity*> ::Node* tmp = n->next;

			if (n->data == entity)
			{
				destination->inside.PushBack(n->data);
				source->inside.Erase(n);
			}

			n = tmp;
		}


	}


};


#endif