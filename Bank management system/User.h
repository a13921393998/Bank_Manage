#pragma once
#include "Header_Summary.h"
class User {
private:
	string user_id;
	string pass_word;
	string name;
	string sex;
	string id;
	// Éí·ÝÖ¤ºÅ
	string phone_number;
	string address;
public:
	User() {
		user_id = "";
		pass_word = "";
		name = "";
		sex = "";
		id = "";
		phone_number = "";
		address = "";
	}
	User(string user_id,string pass_word,string name,string sex,string id,string phone_number,string address) : user_id(user_id),pass_word(pass_word),
		name(name),sex(sex),id(id),phone_number(phone_number),address(address) {}
	string get_user_id() {
		return user_id;
	}
	string get_pass_word() {
		return pass_word;
	}
	string get_name() {
		return name;
	}
	string get_sex() {
		return sex;
	}
	string get_id() {
		return id;
	}
	string get_number_phone() {
		return phone_number;
	}
	string get_address() {
		return address;
	}

	void set_user_id(string user_id) {
		this->user_id = user_id;
	}
	void set_pass_word(string pass_word) {
		this->pass_word = pass_word;
	}
	void set_name(string name) {
		this->name = name;
	}
	void set_sex(string sex) {
		this->sex = sex;
	}
	void set_id(string id) {
		this->id = id;
	}
	void set_number_phone(string phone_number) {
		this->phone_number = phone_number;
	}
	void set_address(string address) {
		this->address = address;
	}
	void set_password(string password) {
		this->pass_word = password;
	}
	void Print() {
		//string user_id, string pass_word, string name, string sex, string id, string phone_numer,
		cout << user_id <<  " " << name << " " << sex << " " << id << " " << phone_number << " " << address << endl;
	}
};
