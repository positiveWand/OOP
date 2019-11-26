#include "json_object.h"
#include "json_list.h"
#include "json_dict.h"
#include "./data/Integer.h"
#include "./data/String.h"

int json_object::_index = 0;

json_object* json_object::parse(const char* jsonString, int length) {
	json_object* anObject = nullptr;

	char targetChar = jsonString[_index];

	while(_index < length) {
		targetChar = jsonString[_index];
		if(targetChar == '0' || targetChar == '1' || targetChar == '2'|| targetChar == '3'|| targetChar == '4'|| targetChar == '5'|| targetChar == '6'|| targetChar == '7'|| targetChar == '8'|| targetChar == '9') {
			anObject = Integer::parse(jsonString, length);
		} else if(targetChar == '"') {
			anObject = String::parse(jsonString, length, '"');
		} else if(targetChar == '\'') {
			anObject = String::parse(jsonString, length, '\'');
		} else if(targetChar == '[') {
			anObject = json_list::parse(jsonString, length);
		} else if(targetChar == '{') {
			//std::cout << "df" << std::endl;
			anObject = json_dict::parse(jsonString, length);
		} else {
			_index++;
		}
	}

	return anObject;
}

json_object* json_object::parse(const std::string& jsonString) {
	json_object::_index = 0;
	return json_object::parse(jsonString.c_str(), jsonString.length());
}


