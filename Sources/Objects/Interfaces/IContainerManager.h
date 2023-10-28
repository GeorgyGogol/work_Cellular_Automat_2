#pragma once

template<class TypeObject> class IManager
{
public:
	virtual TypeObject* Begin() = 0;
	virtual TypeObject* End() = 0;
	virtual TypeObject* Next() = 0;

	virtual TypeObject* First() const = 0;
	virtual TypeObject* Last() const = 0;
	virtual TypeObject* Current() const = 0;

	virtual int Count() const = 0;
	
	virtual void Add(TypeObject* object) = 0;
};

