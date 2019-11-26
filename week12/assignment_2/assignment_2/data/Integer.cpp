#include "Integer.h"

#define isDecimal(x) (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9')

Integer::Integer(int value) {
	this->_val = value;
}

int Integer::val() {
	return this->_val;
}

void Integer::set_val(const int& value) {
	this->_val = value;
}

json_object* Integer::parse(const char* jsonString, int length) {
	Integer* anObject = new Integer(0);

	char decimal[10];
	int i = 0;

	while(_index < length) {
		if(!isDecimal(jsonString[_index])){
			break;
		}
		decimal[i] = jsonString[_index];
		_index++;
		i++;
	}

	decimal[i] = '\0';
	int parsedInt = atoi(decimal);

	anObject->set_val(parsedInt);

	return anObject;
}

json_object::_type Integer::type() {
	return INT;
}

std::string Integer::to_string() {
	return std::to_string(this->_val);
}
