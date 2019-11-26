#include "json_dict.h"
#include "json_list.h"
#include "./data/Integer.h"
#include "./data/String.h"

json_dict::json_dict() {
}

void json_dict::put(json_object* key, json_object* val) {

	bool found = false;

	for(int i = 0; i < this->v.size(); i++) {
		if(this->v[i].first->to_string() == key->to_string()) {
			this->v[i].second = val;
			found = true;
		}
	}

	if(!found) {
		this->v.push_back(std::make_pair(key, val));
	}
}

int json_dict::find(json_object* key) {
	int targetIndex = 0;
	bool found = false;

	for(int i = 0; i < this->v.size(); i++) {
		if(this->v[i].first->to_string() == key->to_string()) {
			targetIndex = i;
			found = true;
			break;
		}
	}

	if(found)
		return targetIndex;
	else
		return -1;
}


json_object* json_dict::parse(const char* jsonString, int length) {
	json_dict* aDict = new json_dict();
	_index++;
	char targetChar = jsonString[_index];

	//std::cout<< targetChar << std::endl;
	//std::cout<< _index <<" " <<length << std::endl;

	json_object* keyObject = nullptr;
	json_object* valueObject = nullptr;

	while(jsonString[_index] != '}' && _index < length) {
		//std::cout<< "in" <<  std::endl;
		keyObject = nullptr;
		valueObject = nullptr;
		while(jsonString[_index] != ':'  && _index < length) {
			targetChar = jsonString[_index];
			if(targetChar == '0' || targetChar == '1'|| targetChar == '2'|| targetChar == '3'|| targetChar == '4'|| targetChar == '5'|| targetChar == '6'|| targetChar == '7'|| targetChar == '8'|| targetChar == '9') {
				keyObject = Integer::parse(jsonString, length);
			} else if(targetChar == '"') {
				keyObject = String::parse(jsonString, length, '"');
			} else if(targetChar == '\'') {
				keyObject = String::parse(jsonString, length, '\'');
			} else {
				_index++;
			}
			if(_index >= length)
				break;
		}

		while(jsonString[_index] != ',' && jsonString[_index] != '}' && _index < length) {
			targetChar = jsonString[_index];
			if(targetChar == '0' || targetChar == '1' || targetChar == '2'  || targetChar == '3' || targetChar == '4' || targetChar == '5' || targetChar == '6' || targetChar == '7' || targetChar == '8' || targetChar == '9' ) {
				valueObject = Integer::parse(jsonString, length);
			} else if(targetChar == '"') {
				valueObject = String::parse(jsonString, length, '"');
			} else if(targetChar == '\'') {
				valueObject = String::parse(jsonString, length, '\'');
			} else if(targetChar == '[') {
				valueObject = json_list::parse(jsonString, length);
			} else if(targetChar == '{') {
				valueObject = json_dict::parse(jsonString, length);
			} else {
				_index++;
			}
			if(_index >= length)
				break;
		}

		if(keyObject != nullptr && valueObject != nullptr) {
			aDict->put(keyObject, valueObject);
		}

		if(_index >= length)
			break;
	}

	_index++;

	//std::cout << _index << std::endl;

	return aDict;
}

json_object* json_dict::operator[](json_object* key) const {
	json_object* aValue = nullptr;

	for(int i = 0; i < this->v.size(); i++) {
		if(this->v[i].first->to_string() == key->to_string())
			aValue = this->v[i].second;
	}

	return aValue;
}

json_object* json_dict::operator[](const std::string& key) const {
	json_object* aValue = nullptr;

	for(int i = 0; i < this->v.size(); i++) {
		if(this->v[i].first->to_string() == "'"+key+"'" || this->v[i].first->to_string() == "\""+key+"\"")
			aValue = this->v[i].second;
	}

	return aValue;
}


json_object* json_dict::operator[](int key) const {
	json_object* aValue = nullptr;

	for(int i = 0; i < this->v.size(); i++) {
		if(this->v[i].first->to_string() == std::to_string(key))
			aValue = this->v[i].second;
	}

	return aValue;
}

json_object::_type json_dict::type() {
	return DICT;
}

std::string json_dict::to_string() {
	std::string totalString("{");

	for(int i = 0; i < this->v.size(); i++) {
		totalString += this->v[i].first->to_string();
		totalString += ": ";
		totalString += this->v[i].second->to_string();
		if(i != this->v.size()-1)
			totalString += ", ";
	}

	totalString += "}";

	return totalString;
}
