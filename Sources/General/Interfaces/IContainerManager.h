#pragma once

#include "IManagerIterator.h"

template<class TypeObject> class IManager
{
public:
	virtual IManagerIterator<TypeObject> begin() = 0;
	virtual IManagerIterator<TypeObject> end() = 0;
	
	//virtual IManagerIterator<TypeObject> next() = 0;

	//virtual IManagerIterator<TypeObject> First() const = 0;
	//virtual IManagerIterator<TypeObject> Last() const = 0;
	//virtual IManagerIterator<TypeObject> Current() const = 0;

	virtual int Count() const = 0;
	
	virtual void add(TypeObject* object) = 0;
	virtual void checkElements() = 0;

};



