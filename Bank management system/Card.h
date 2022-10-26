#pragma once
#include "Transaction.h"
class Card{
private:
	string card_id;
	string password;
	long long balance;
	string name;
	vector<Transaction> transaction;
public:
	void print_transaction() {
		if (transaction.size() == 0) {
			printf("ÔÝÎÞÊý¾Ý");
			return;
		}
		for (auto it : transaction) {
			cout << it.get_type() << " " << it.get_timestr() << " " << it.get_money() << endl;
		}
	}
	Card() {
		card_id = "";
		password = "";
		balance = 0;
		name = "";
	}
	Card(string password, string name) : password(password),name(name){
		card_id = "";
		balance = 0;
		srand((int)time(0));
		for (int i = 0; i < 9; i++) {
			card_id += char(rand()%10 + '0');
		}
	}
	Card(string password, string name, string card_id, long long balance) : password(password), name(name), card_id(card_id), balance(balance){}
	int get_transaction_size() {
		return transaction.size();
	}
	vector<Transaction>& get_Transaction() {
		return transaction;
	}
	string get_name() {
		return name;
	}
	string get_id() {
		return card_id;
	}
	string get_password() {
		return password;
	}
	long long get_balance() {
		return balance;
	}
	int passwor(string passw) {
		if (passw == password) {
			return 1;
		}
		else {
			return -1;
		}
	}
	void save(long long num) {
		balance += num;
		transaction.push_back(Transaction(1, num));
	}
	int draw(long long num) {
		if (balance < num) {
			return 0;
		}
		else {
			transaction.push_back(Transaction(2, num));
			balance -= num;
			return 1;
		}
	}
	int transfer_roll_out(long long num) {
		if (balance < num) {
			return 0;
		}
		else {
			transaction.push_back(Transaction(3, num));
			balance -= num;
			return 1;
		}
	}
	int transfer_thift_to(long long num) {
		transaction.push_back(Transaction(4, num));
		balance = num;
		return 1;
	}
	~Card() {
		vector<Transaction>().swap(transaction);
	}
};