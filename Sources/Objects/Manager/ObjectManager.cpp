#include "stdafx.h"
#include "ObjectManager.h"

#include "Object.h"
#include "UniqueIDController.h"

automat::automat::ObjectManager::ObjectManager()
	: BaseManager(1000)
{
}

automat::automat::ObjectManager::~ObjectManager()
{
	for (it = ObjectsList.begin(); it != ObjectsList.end(); ++it)
	{
		delete* it;
	}
}

int automat::ObjectManager::createObject(ObjectData &objectInfo)
{
	objectInfo.ID = IDStorage->getNextID();
	Object* p = new Object(objectInfo);

	int out = -1;
	if (p) {
		ObjectsList.push_back(p);
		out = objectInfo.ID;
	}
	return out;
}

void automat::ObjectManager::AddObject(Object *object)
{
    ObjectsList.push_back(object);
	it = ObjectsList.end();
	--it;
}

void automat::ObjectManager::RefreshObjects()
{
	std::list<Object*>::iterator itRefr = ObjectsList.begin();
	std::list<Object*> ToDelete;
	Object* current;

	for (itRefr; itRefr != ObjectsList.end(); ++itRefr) {
		current = *itRefr;

		/*if (!current->isAlive()) {
			current->addExistancePoints(-1);
		}*/

		if (!current->isExists()) {
			ToDelete.push_back(current);
		}
	}

	for (itRefr = ToDelete.begin(); itRefr != ToDelete.end(); ++itRefr) {
		delete *itRefr;
		ObjectsList.remove(*itRefr);
	}
}

/*
Object* automat::ObjectManager::Begin() {
	it = ObjectsList.begin();
	return *it;
}

Object* automat::ObjectManager::End() {
	it = ObjectsList.end();
	return *it;
}

Object* automat::ObjectManager::Next() {
	if (it != ObjectsList.end()) ++it;
	return *it;
}

Object* automat::ObjectManager::First() const {
	return *ObjectsList.begin();
}

Object* automat::ObjectManager::Last() const {
	return *ObjectsList.end();
}

Object* automat::ObjectManager::Current() const {
	if (ObjectsList.size() < 1) return nullptr;
	return *it;
}
*/

int automat::ObjectManager::Count() const {
	return ObjectsList.size();
}

