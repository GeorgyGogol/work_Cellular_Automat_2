#pragma once

template<class TypeObject> class IManager;

template<class TypeObject>
class IManagerIterator : public std::iterator<std::input_iterator_tag, TypeObject>
{
	friend class IManager<TypeObject>;
	// TODO: add friend class

protected:
	IManagerIterator(TypeObject* objectPtr) : ObjectPtr(objectPtr) {}

public:
	IManagerIterator(const IManagerIterator& it) : ObjectPtr(it.ObjectPtr) {}
    IManagerIterator& operator=(const IManagerIterator& it) {
        if (this != &it){
            ObjectPtr = it.ObjectPtr;
        }
        return *this;
    }

	bool operator==(IManagerIterator const& it) const { return it.ObjectPtr == ObjectPtr; }
	bool operator!=(IManagerIterator const& it) const { return it.ObjectPtr != ObjectPtr; }

	typename IManagerIterator::reference operator*() const { return *ObjectPtr; }

	IManagerIterator& operator++() { ++ObjectPtr; return *this; }
	IManagerIterator& operator++(int) {
		IManagerIterator outPtr = this;
		++ObjectPtr;
		return *outPtr;
	}

	IManagerIterator& operator--() { --ObjectPtr; return *this; }
	IManagerIterator& operator--(int) {
		IManagerIterator outPtr = this;
		--ObjectPtr;
		return *outPtr;
	}

private:
	TypeObject* ObjectPtr;

};

template<typename TypeObject> 
typename const IManagerIterator<TypeObject> const_IManagerIterator;
