#pragma once

#include <list>
#include "IContainerManager.h"
#include "Object.h"

class ObjectManager 
	: public IManager<Object>
{
public:
	ObjectManager();
	virtual ~ObjectManager();

private:
	std::list<Object*> ObjectsList;
	std::list<Object*>::iterator it;

public:
	void AddObject(Object* object);

	void RefreshObjects();

	Object* Begin();
	Object* End();
	Object* Next();

	Object* First() const;
	Object* Last() const;
	Object* Current() const;

	int Count() const;

};

