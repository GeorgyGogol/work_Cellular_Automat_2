#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	for (it = ObjectsList.begin(); it != ObjectsList.end(); ++it)
	{
		delete* it;
	}
}

void ObjectManager::AddObject(Object* object) {
	ObjectsList.push_back(object);
	it = ObjectsList.end();
	--it;
}

void ObjectManager::RefreshObjects()
{
	std::list<Object*>::iterator itRefr = ObjectsList.begin();
	std::list<Object*> ToDelete;
	Object* current;

	for (itRefr; itRefr != ObjectsList.end(); ++itRefr) {
		current = *itRefr;

		if (!current->isAlive()) {
			current->addExistancePoints(-1);
		}

		if (!current->isExists()) {
			ToDelete.push_back(current);
		}
	}

	for (itRefr = ToDelete.begin(); itRefr != ToDelete.end(); ++itRefr) {
		delete *itRefr;
		ObjectsList.remove(*itRefr);
	}
}

Object* ObjectManager::Begin() {
	it = ObjectsList.begin();
	return *it;
}

Object* ObjectManager::End() {
	it = ObjectsList.end();
	return *it;
}

Object* ObjectManager::Next() {
	if (it != ObjectsList.end()) ++it;
	return *it;
}

Object* ObjectManager::First() const {
	return *ObjectsList.begin();
}

Object* ObjectManager::Last() const {
	return *ObjectsList.end();
}

Object* ObjectManager::Current() const {
	if (ObjectsList.size() < 1) return nullptr;
	return *it;
}

int ObjectManager::Count() const {
	return ObjectsList.size();
}

