#pragma once
#include "Customer.h"
map<string, Customer> Customer_List;
class Window_Manage {

public:
	Window_Manage(){}
	void welcome() {
		system("cls");
		int temp = 0;
		printf("银行管理系统\n");
		printf("1.用户登录\n");
		printf("2.Admin登录\n");
		printf("3.退出\n");
		printf("请输入操作编号:\n");
		/*scanf("%d", &temp);*/
		cin >> temp;
		string t;
		switch (temp) {
		case 1: {
			Login();
			break;
		}
		case 2:
			Admin_login();
			break;
		case 3:
			exit(0);
			break;
		default:
			Error_Handle();
			break;
		}
	}
	void Login();
	void Admin_login();
	void Register_m();
	void Reset_Password();
	void Manage_Card(string t);
	void New_Card();
	void Operation_Card(string t, string card_id);
	void Error_Handle();
	void Delete_Customer();
	void Admid_Operator();
	void Delete_Card();
	void Print_Customer_Info();
};

void Window_Manage::Error_Handle() {
	system("cls");
	printf("请按照屏幕提示操作:\n");
	system("pause");
}

void Window_Manage::Login() {
	string user_id, password;
	string temp = "";
	int type = 0;
	while (1) {
		int type;
		system("cls");
		printf("1.登录账号\n");
		printf("2.忘记密码\n");
		printf("3.退出\n");
		printf("输入操作编号:\n");
		cin >> type;
		if (type == 1) {
			printf("请输入账号:\n");
			cin >> user_id;
			printf("请输入密码:\n");
			cin >> password;
			if (Customer_List.find(user_id) != Customer_List.end()) {
				if (Customer_List[user_id].get_pass_word() == password) {
					Manage_Card(user_id);
					return;
				}
				else {
					printf("密码错误\n");
					printf("1.重新登录:\n");
					printf("2.退出:\n");
					printf("输入操作编号:\n");
					//system("pause");
					cin >> type;
					if (type == 2) {
						break;
					}
					else if (type == 1) {
						continue;
					}
					else {
						Error_Handle();
					}
				}
			}
			else {
				printf("账号不存在\n");
				printf("1.重新登录:\n");
				printf("2.退出:\n");
				printf("输入操作编号:\n");
				cin >> type;
				//system("pause");
				if (type == 2) {
					break;
				}
				else if (type == 1) {
					continue;
				}
				else {
					Error_Handle();
				}
			}
		}
		else if (type == 2) {
			Reset_Password();
		}
		else if (type == 3) {
			break;
		}
		else {
			Error_Handle();
		}
	}
}

void Window_Manage::Admin_login() {
	string user_id, password;
	string temp = "";
	int type = 0;
	while (1) {
		int type;
		system("cls");
		printf("1.登录账号\n");
		printf("2.退出\n");
		printf("输入操作编号:\n");
		cin >> type;
		if (type == 1) {
			printf("请输入账号:\n");
			cin >> user_id;
			printf("请输入密码:\n");
			cin >> password;
			if (user_id=="123456789") {
				if (password == "123456789") {
					Admid_Operator();
					return;
				}
				else {
					printf("密码错误\n");
					printf("1.重新登录:\n");
					printf("2.退出:\n");
					printf("输入操作编号:\n");
					//system("pause");
					cin >> type;
					if (type == 2) {
						break;
					}
					else if (type == 1) {
						continue;
					}
					else {
						Error_Handle();
					}
				}
			}
			else {
				printf("账号不存在\n");
				printf("1.重新登录:\n");
				printf("2.退出:\n");
				printf("输入操作编号:\n");
				cin >> type;
				//system("pause");
				if (type == 2) {
					break;
				}
				else if (type == 1) {
					continue;
				}
				else {
					Error_Handle();
				}
			}
		}
		else if (type == 2) {
			break;
		}
		else {
			Error_Handle();
		}
	}
}


void Window_Manage::Register_m() {
	system("cls");
	string user_id, pass_word, name, sex, id, phone_number, address;
	//Customer a("13921393998", "13921393998", "cyf", "m", "411525200102273615", "13665178289", "abc");
	//m["13921393998"] = a;
	printf("请输入登录账号:\n");
	cin >> user_id;
	printf("请输入登录密码:\n");
	cin >> pass_word;
	printf("请输入名字:\n");
	cin >> name;
	printf("请输入性别:\n");
	cin >> sex;
	printf("请输入身份证号:\n");
	cin >> id;
	printf("请输入电话号码:\n");
	cin >> phone_number;
	printf("请输入地址:\n");
	cin >> address;
	Customer a(user_id, pass_word, name, sex, id, phone_number, address);
	Customer_List[user_id] = a;
}


void Window_Manage::Reset_Password() {
	string user_id, name, id, phone_number,pass_word;
	int type = 0;
	while (1) {
		system("cls");
		printf("请输入登录账号:\n");
		cin >> user_id;
		printf("请输入名字:\n");
		cin >> name;
		printf("请输入电话号码:\n");
		cin >> phone_number;
		printf("请输入身份证:\n");
		cin >> id;
		//bool user_id_bool = false, name_bool = false, id_bool = false, phone_number_bool = false;
		if (user_id != Customer_List[user_id].get_user_id()) {
			printf("用户名不存在\n");
			printf("1.重新输入信息\n");
			printf("2.退出\n");
			printf("输入操作编号:\n");
			cin >> type;
			if (type == 2) {
				break;
			}
			else  if (type == 1) {
				continue;
			}
			else {
				Error_Handle();
			}
		}
		if (name != Customer_List[user_id].get_name()) {
			printf("姓名错误\n");
			printf("1.重新输入信息\n");
			printf("2.退出\n");
			printf("输入操作编号:\n");
			cin >> type;
			if (type == 2) {
				break;
			}
			else  if(type==1){
				continue;
			}
			else {
				Error_Handle();
			}
		}
		if (id != Customer_List[user_id].get_id()) {
			printf("身份证错误\n");
			printf("1.重新输入信息\n");
			printf("2.退出\n");
			printf("输入操作编号:\n");
			cin >> type;
			if (type == 2) {
				break;
			}
			else  if (type == 1) {
				continue;
			}
			else {
				Error_Handle();
			}
		}
		if (phone_number != Customer_List[user_id].get_number_phone()) {
			printf("电话号码错误\n");
			printf("1.重新输入信息\n");
			printf("2.退出\n");
			printf("输入操作编号:\n");
			cin >> type;
			if (type == 2) {
				break;
			}
			else  if (type == 1) {
				continue;
			}
			else {
				Error_Handle();
			}
		}
		printf("请输入新密码:\n");
		cin >> pass_word;
		Customer_List[user_id].Set_Name(pass_word);
		printf("重置密码成功\n");
		system("pause");
		break;
	}
}


void Window_Manage::Manage_Card(string t) {
	while (1) {
		int len = 0, type;
		string tt;
		len = Customer_List[t].Get_Size();
		system("cls");
		printf("您的银行卡列表:\n");
		if (len == 0) {
			printf("暂无银行卡\n");
			printf("1.注销账户登录\n");
			printf("输入操作编号:\n");
			cin >> type;
			if (type == 1) {
				break;
			}
			else {
				Error_Handle();
			}
		}
		else {
			Customer_List[t].print_Card_id();
			printf("1.操作银行卡\n");
			printf("2.注销账户登录\n");
			printf("请输入操作编号:\n");
			cin >> type;
			if (type == 1) {
				printf("请输入操作的银行卡号:\n");
				cin >> tt;
				Operation_Card(t, tt);
			}
			else if (type == 2) {
				break;
			}
			else {
				Error_Handle();
			}
		}
	}
}

void Window_Manage::New_Card() {
	while (1) {
		system("cls");
		
		printf("1.开卡\n");
		printf("2.退出\n");
		int type;
		printf("请输入操作数:\n");
		cin >> type;
		if (type == 1) {
			string temp;
			printf("请输入需要开卡的账户:\n");
			cin >> temp;
			if (Customer_List.find(temp) == Customer_List.end()) {
				printf("需要开卡的账户不存在");
				system("pause");
				continue;
			}
			else {
				string pass_word, card_id;
				printf("请输入卡的密码:\n");
				cin >> pass_word;
				card_id = Customer_List[temp].create_card(pass_word);
				Card_List[card_id] = Customer_List[temp].get_card(card_id);
				printf("您的新卡号为: ");
				cout << card_id;
				system("pause");
			}
		}
		else if (type == 2) {
			break;
		}
		else {
			Error_Handle();
		}
	}
}


void Window_Manage::Operation_Card(string t,string card_id) {
	string pass_word;
	int type,num;
	printf("请输入密码:\n");
	cin >> pass_word;
	while (1) {
		system("cls");
		printf("1.存钱\n");
		printf("2.取钱\n");
		printf("3.转账\n");
		printf("4.打印交易细则\n");
		printf("5.查询余额\n");
		printf("6.退出\n");
		printf("请输入操作数:\n");
		Card* p = Customer_List[t].get_card(card_id);
		cin >> type;
		if (type == 1) {
			printf("请输入存钱数量:\n");
			cin >> num;
			p->save(num);
			cout << p->get_balance() << endl;
			system("pause");
		}
		else if (type == 2) {
			printf("请输入取钱数量:\n");
			cin >> num;
			if (p->draw(num) == 0) {
				printf("余额不足\n");
				system("pause");
			}
			else {
				printf("取钱成功\n");
				cout << p->get_balance() << endl;
				system("pause");
			}
		}
		else if (type == 3) {
			printf("请输入转账数量:\n");
			cin >> num;
			printf("请输入转入卡号:\n");
			string temp;
			cin >> temp;
			if (p->transfer_roll_out(num) == 0) {
				printf("余额不足\n");
				system("pause");
			}
			else if(Card_List.find(temp)==Card_List.end()){
				printf("卡号不存在\n");
				system("pause");
			}
			else {
				int i = Card_List[temp]->transfer_thift_to(num);
				printf("转账成功\n");
				cout << p->get_balance() << endl;
				system("pause");
			}
		}
		else if(type==4) {
			p->print_transaction();
			system("pause");
		}
		else if (type == 5) {
			cout << p->get_balance();
			system("pause");
		}
		else if (type == 6) {
			break;
		}
		else {
			Error_Handle();
		}
	}
}

void Window_Manage::Delete_Customer() {
	while (1) {
		system("cls");
		printf("1.删除账户\n");
		printf("2.退出\n");
		printf("请输入操作数:\n");
		int type;
		cin >> type;
		if (type == 1) {
			printf("请输入需要删除账户的账号:\n");
			string Customer_ID;
			cin >> Customer_ID;
			printf("请输入需要删除账户的密码:\n");
			string PassWord;
			cin >> PassWord;
			if (Customer_List.find(Customer_ID) == Customer_List.end()) {
				printf("该账户不存在");
				system("pause");
				continue;
			}
			else {
				if (Customer_List[Customer_ID].get_pass_word() != PassWord) {
					printf("密码错误");
					system("pause");
					continue;
				}
				else {
					Customer_List.erase(Customer_ID);
					/*Customer_List[Customer_ID].~Customer();*/
					printf("删户成功");
					system("puase");
					continue;
				}
			}
			
		}
		else if (type == 2) {
			break;
		}
		else {
			Error_Handle();
		}
	}
	
}

void Window_Manage::Admid_Operator()
{
	string temp,password,card_id;
	while (1) {
		system("cls");
		printf("1.开户\n");
		printf("2.销户\n");
		printf("3.开卡\n");
		printf("4.销卡\n");
		printf("5.查询用户信息\n");
		printf("6.退出\n");
		printf("请输入操作数:\n");
		int type;
		cin >> type;
		switch (type) {
		case 1:
			Register_m();
			break;
		case 2:
			Delete_Customer();
			break;
		case 3: {
			New_Card();
			break;
		}
		case 4: {
			Delete_Card();
			break;
		}
		case 5: {
			Print_Customer_Info();
			break;
		}
		case 6:
			return;
		default:
			Error_Handle();
			break;
		}
	}
}

void Window_Manage::Delete_Card()
{
	while (1) {
		int type;
		system("cls");
		printf("1.销卡\n");
		printf("2.退出\n");
		printf("请输入操作数:\n");
		cin >> type;
		if (type == 1) {
			string temp, card_id, password;
			printf("请输入需要删除卡的账户:\n");
			cin >> temp;
			printf("请输入需要删除卡的卡号:\n");
			cin >> card_id;
			printf("请输入需要删除卡的密码:\n");
			cin >> password;
			if (Customer_List.find(temp) == Customer_List.end()) {
				printf("该账户不存在");
				system("pause");
				continue;
			}
			else {
				if (Card_List.find(card_id) == Card_List.end()) {
					printf("该卡不存在");
					system("pause");
					continue;
				}
				else {
					if (Card_List[card_id]->get_password() != password) {
						printf("密码错误");
						system("pause");
						continue;
					}
					else {
						Customer_List[temp].delete_Card(card_id);
						Customer_List.erase(temp);
						printf("删卡成功");
						system("pause");
					}
				}
			}
		}
		else if(type==2){
			break;
		}
		else {
			Error_Handle();
		}
	}
}

void Window_Manage::Print_Customer_Info()
{
	while (1) {
		system("cls");
		printf("1.查看信息\n");
		printf("2.退出\n");
		printf("请输入操作数:\n");
		int type;
		cin >> type;
		if (type == 1) {
			string temp;
			printf("请输入需要查看信息的账户:\n");
			cin >> temp;
			if (Customer_List.find(temp) == Customer_List.end()) {
				printf("该账户不存在");
				system("pause");
				continue;
			}
			else {
				Customer_List[temp].Print_All_Information();
				system("pause");
			}
		}
		else if(type==2){
			break;
		}
		else {
			Error_Handle();
		}
	}
}
