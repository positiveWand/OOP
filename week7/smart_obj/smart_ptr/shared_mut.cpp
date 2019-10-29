//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"
#include <iostream>
namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
	//std::cout <<"이게 호출이 되네" << std::endl;
    _mgr = new mgr(_obj);
}

shared_mut::~shared_mut() {
	//std::cout << "소멸자 호출" << std::endl;
	release();
	
}


//내가 한 영역
Object* shared_mut::get() const { // mgr의 object 포인터 리턴
	if(_mgr == nullptr){
		return nullptr;
	}
	else{
		return _mgr->ptr;
	}
}

int shared_mut::count() { // mgr의 count를 리턴
	return _mgr->count;
}

void shared_mut::increase() { // mgr의 count를 1증가
	_mgr->count++;
}

void shared_mut::release() { // mgr의 count 1감소, count == 0 이면 mgr 초기화
	_mgr->count--;
	//std::cout << "삭제 스타트" << std::endl;
	if(_mgr->count == 0){
		delete(_mgr);
	}
	_mgr = nullptr;
	//std::cout << "삭제 끝" << std::endl;
}

shared_mut shared_mut::operator+(const shared_mut &shared){
	shared_mut l = *this;
	int newVar = l.get()->get() + shared.get()->get();
	Object* newObj = new Object(newVar);
	shared_mut* sharedMut = new shared_mut(newObj);
	//std::cout << "생성 완료!" << std::endl;
	return *sharedMut;
}

shared_mut shared_mut::operator-(const shared_mut &shared){
	shared_mut l = *this;
	int newVar = l.get()->get() - shared.get()->get();
	Object* newObj = new Object(newVar);
	shared_mut sharedMut(newObj);
	return sharedMut;
}
shared_mut shared_mut::operator*(const shared_mut &shared){
	shared_mut l = *this;
	int newVar = l.get()->get() * shared.get()->get();
	Object* newObj = new Object(newVar);
	shared_mut sharedMut(newObj);
	return sharedMut;
}
shared_mut shared_mut::operator/(const shared_mut &shared){
	shared_mut l = *this;
	int newVar = l.get()->get() / shared.get()->get();
	Object* newObj = new Object(newVar);
	shared_mut sharedMut(newObj);
	return sharedMut;
}

Object* shared_mut::operator->(){
	return _mgr->ptr;
}

shared_mut& shared_mut::operator=(const shared_mut &r){
	release();
	_mgr = r._mgr;
	increase();
}
} // end of namespace ptr
