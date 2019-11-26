#include "String.h"

String::String(const std::string& str) {
	this->_val = str;
}

std::string String::val() {
	return this->_val;
}

void String::set_val(const std::string& str) {
	this->_val = str;
}


json_object* String::parse(const char* jsonString, int length, char base) {
	String* anObject = new String("");

	std::string anString("");
	_index++;

	char nextChar = jsonString[_index];
	while(nextChar != base && _index != length) {
		anString += nextChar;
		_index++;
		if(_index != length)
			nextChar = jsonString[_index];
	}

	anObject->set_val(anString);
	anString = '\'' + anString + '\'';
	//anObject->set_val(anString);

	_index++;

	//std::cout<< anString << std::endl;
	//std::cout<< _index << std::endl;
	return anObject;
}

json_object::_type String::type() {
	return STRING;
}

std::string String::to_string() {
	return '\''+this->_val+'\'';
}
