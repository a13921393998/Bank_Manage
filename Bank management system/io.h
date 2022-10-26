#pragma once
#include "Windows_Manage.h"
using namespace std;
class I_And_O {
public:
	bool SaveData();
	bool LoadData();
};


bool I_And_O::SaveData() {
	fstream out;
	out.open("User.txt", fstream::out | fstream::trunc); //用户信息
	if (!out.is_open()) {
		return 1;
	}
	out << Customer_List.size() << endl; //数据数量
	for (map<string, Customer>::iterator it = Customer_List.begin(); it != Customer_List.end(); it++){
		Customer& u = it->second;
		out << u.get_user_id() << "\t" << u.get_pass_word() << "\t" << u.get_name() << "\t" << u.get_sex() << "\t"
			<< u.get_id() << "\t" << u.get_number_phone() << "\t" << u.get_address() << endl;
		out << u.Get_Size() << endl; //卡数量
		map<string, Card> &temp = u.get_Card_List();
		for (auto it = temp.begin(); it != temp.end(); it++) {
			out << it->second.get_id() << "\t" << it->second.get_password() << "\t" << it->second.get_balance() << "\t" << it->second.get_name() << endl;
		}
	}
	out.close();
	out.open("Card.txt", fstream::out | fstream::trunc); //卡信息
	if (!out.is_open())
		return 1;
	out << Card_List.size() << endl; //数据数量
	for (auto it : Card_List) {
		out << it.first << endl;
		out << it.second->get_transaction_size() << endl; // 操作数量
		for (int i = 0; i < it.second->get_transaction_size(); i++) {
			out << it.second->get_Transaction()[i].get_timestr() << "\t" << it.second->get_Transaction()[i].get_type() << "\t" << it.second->get_Transaction()[i].get_money() << endl;
		}
	}
	return 0;
}

bool I_And_O::LoadData() {
	fstream in;
	in.open("User.txt", fstream::in);
	if (!in.is_open())
		return 1;
	int n, m; //数据数量
	in >> n;
	string user_id; string pass_word; string name; string sex; string id; string phone_numer; string address;
	for (int i = 0; i < n; i++){
		in >> user_id >> pass_word >> name >> sex >> id >> phone_numer >> address;
		Customer *s = new Customer(user_id, pass_word, name, sex, id, phone_numer, address);
		Customer_List[user_id] = *s;
		in >> m;
		string card_id;string password;long long balance;string name;
		/*out << u.get_user_id() << "\t" << u.get_pass_word() << "\t" << u.get_name() << "\t" << u.get_sex() << "\t"
			<< u.get_id() << "\t" << u.get_number_phone() << "\t" << u.get_address() << endl;*/
		for (int j = 0; j < m; j++){
			in >> card_id >> password >> balance >> name;
			//Card a(password, name, card_id, balance);
			Card* a = new Card(password, name, card_id, balance);
			s->Insert_Card_List(card_id, *a);
			Card_List[card_id] = a;
		}
	}
	in.close();
	in.open("Card.txt", fstream::in);
	if (!in.is_open()) {
		return 1;
	}
	in >> n;
	for (int i = 0; i < n; i++) {
		string card_id;
		in >> card_id;
		in >> m;
		for (int i = 0; i < m; i++) {
			string timestr;
			string ty;
			long long money;
			in >> timestr >> ty >> money;
			Transaction *temp = new Transaction(timestr,ty, money);
			Card_List[card_id]->get_Transaction().push_back(*temp);
		}
	}
	in.close();
	return 0;
}
