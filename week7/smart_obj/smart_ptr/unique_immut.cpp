//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}

//내가 한 영역
Object* unique_immut::get() const { // mgr의 object포인터를 리턴한다
	if(_mgr == nullptr) {
		return nullptr;
	}
	else{
		return _mgr->ptr;
	}
}

void unique_immut::release() { // mgr이 nullptr이 아닌 경우 mgr을 delete함
	if(_mgr != nullptr){
		_mgr->~mgr();
		_mgr = nullptr;
	}
}

unique_immut unique_immut::operator+(unique_immut &unique){
	unique_immut l = *this;
	int newVar = l._mgr->ptr->get() + unique._mgr->ptr->get();
	l.release();
	unique.release();
	Object* newObj = new Object(newVar);
	unique_immut* newUniqueObj = new unique_immut(newObj);
	return *newUniqueObj;
}

unique_immut unique_immut::operator-(unique_immut &unique){
	unique_immut l = *this;
	int newVar = l._mgr->ptr->get() - unique._mgr->ptr->get();
	l.release();
	unique.release();
	Object* newObj = new Object(newVar);
	unique_immut* newUniqueObj = new unique_immut(newObj);
	return *newUniqueObj;
}
unique_immut unique_immut::operator*(unique_immut &unique){
	unique_immut l = *this;
	int newVar = l._mgr->ptr->get() * unique._mgr->ptr->get();
	l.release();
	unique.release();
	Object* newObj = new Object(newVar);
	unique_immut* newUniqueObj = new unique_immut(newObj);
	return *newUniqueObj;
}
unique_immut unique_immut::operator/(unique_immut &unique){
	unique_immut l = *this;
	int newVar = l._mgr->ptr->get() / unique._mgr->ptr->get();
	l.release();
	unique.release();
	Object* newObj = new Object(newVar);
	unique_immut* newUniqueObj = new unique_immut(newObj);
	return *newUniqueObj;
}



Object* unique_immut::operator->(){
	return _mgr->ptr;
}

unique_immut& unique_immut::operator=(unique_immut &r){
	if((*this).get() != r.get()){
		(*this).release();
		Object* newObj = new Object(r.get()->get());
		(*this)._mgr = new mgr(newObj);
	}
	else{
		
	}
	return *this;
}
} // end of namespace ptr
