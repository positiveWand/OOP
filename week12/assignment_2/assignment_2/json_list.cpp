#include "json_list.h"
#include "json_dict.h"
#include "./data/Integer.h"
#include "./data/String.h"

json_list::json_list() {
}

json_object* json_list::parse(const char* jsonString, int length) {
	json_list* aList = new json_list();

	_index++;
	char targetChar = jsonString[_index];

	json_object* anObject = nullptr;
	
	while(jsonString[_index] != ']' && _index < length) {
		anObject = nullptr;
		targetChar = jsonString[_index];

		if(targetChar == '0' || targetChar == '1'|| targetChar == '2'|| targetChar == '3'|| targetChar == '4'|| targetChar == '5'|| targetChar == '6'|| targetChar == '7'|| targetChar == '8' || targetChar == '9') {
			anObject = Integer::parse(jsonString, length);
		} else if(targetChar == '"') {
			anObject = String::parse(jsonString, length, '"');
		} else if(targetChar == '\'') {
			anObject = String::parse(jsonString, length, '\'');
		} else if(targetChar == '[') {
			anObject = json_list::parse(jsonString, length);
		} else if(targetChar == '{') {
			anObject = json_dict::parse(jsonString, length);
		} else {
			_index++;
		}

		if(anObject)
			aList->v.push_back(anObject);

		if(_index >= length)
			break;
	}

	_index++;

	return aList;
}


json_object* json_list::operator[](int key) const {
	return this->v[key];
}

json_object::_type json_list::type() {
	return LIST;
}

std::string json_list::to_string() {
	std::string totalString("[");

	for(int i = 0; i < this->v.size(); i++) {
		totalString += this->v[i]->to_string();
		if(i != this->v.size() - 1)
			totalString += ", ";
	}

	totalString += "]";

	return totalString;
}
