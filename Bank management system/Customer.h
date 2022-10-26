#pragma once
#include "User.h"
#include "Card.h"
map<string, Card*> Card_List;
class Customer : public User {
private:
	map<string, Card> Card_List;
public:
	Customer(string user_id, string pass_word, string name, string sex, string id, string phone_numer, string address) : User(user_id,pass_word,name,sex,id,phone_numer,address) {}
	Customer(){}
	int Get_Size() {
		return Card_List.size();
	}
	string create_card(string pass_word) {
		string names = this->get_name();
		Card temp(pass_word,names);
		//Card_List.push_back(temp);
		Card_List[temp.get_id()] = temp;
		return temp.get_id();
	}
	bool judge_Card(string ID) {
		if (Card_List.find(ID) != Card_List.end()) {
			return true;
		}
		else {
			return false;
		}
	}
	void Insert_Card_List(string Card_id, Card &a) {
		//Card_List[Card_id] = a;
		this->Card_List[Card_id] = a;
	}
	Card* get_card(string i) {
		return &Card_List[i];
	}
	void print_Card_id() {
		for (auto iter : Card_List) {
			cout << iter.first << endl;
		}
	}
	void delete_Card(string id) {
		Card_List[id].~Card();
		Card_List.erase(id);
	}
	void Set_Name(string password) {
		set_password(password);
	}
	~Customer() {
		//if (Card_List.size() == 0) {
		//	return;
		//}
		//for (auto it : Card_List) {
		//	Card_List.erase(it.first);
		//	//delete_Card(it.first);
		//}
	}
	void Print_All_Information() {
		Print();
		print_Card_id();
	}
	map<string, Card>& get_Card_List() {
		return Card_List;
	}
};