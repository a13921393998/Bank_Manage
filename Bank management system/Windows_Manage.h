#pragma once
#include "Customer.h"
map<string, Customer> Customer_List;
class Window_Manage {

public:
	Window_Manage(){}
	void welcome() {
		system("cls");
		int temp = 0;
		printf("���й���ϵͳ\n");
		printf("1.�û���¼\n");
		printf("2.Admin��¼\n");
		printf("3.�˳�\n");
		printf("������������:\n");
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
	printf("�밴����Ļ��ʾ����:\n");
	system("pause");
}

void Window_Manage::Login() {
	string user_id, password;
	string temp = "";
	int type = 0;
	while (1) {
		int type;
		system("cls");
		printf("1.��¼�˺�\n");
		printf("2.��������\n");
		printf("3.�˳�\n");
		printf("����������:\n");
		cin >> type;
		if (type == 1) {
			printf("�������˺�:\n");
			cin >> user_id;
			printf("����������:\n");
			cin >> password;
			if (Customer_List.find(user_id) != Customer_List.end()) {
				if (Customer_List[user_id].get_pass_word() == password) {
					Manage_Card(user_id);
					return;
				}
				else {
					printf("�������\n");
					printf("1.���µ�¼:\n");
					printf("2.�˳�:\n");
					printf("����������:\n");
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
				printf("�˺Ų�����\n");
				printf("1.���µ�¼:\n");
				printf("2.�˳�:\n");
				printf("����������:\n");
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
		printf("1.��¼�˺�\n");
		printf("2.�˳�\n");
		printf("����������:\n");
		cin >> type;
		if (type == 1) {
			printf("�������˺�:\n");
			cin >> user_id;
			printf("����������:\n");
			cin >> password;
			if (user_id=="123456789") {
				if (password == "123456789") {
					Admid_Operator();
					return;
				}
				else {
					printf("�������\n");
					printf("1.���µ�¼:\n");
					printf("2.�˳�:\n");
					printf("����������:\n");
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
				printf("�˺Ų�����\n");
				printf("1.���µ�¼:\n");
				printf("2.�˳�:\n");
				printf("����������:\n");
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
	printf("�������¼�˺�:\n");
	cin >> user_id;
	printf("�������¼����:\n");
	cin >> pass_word;
	printf("����������:\n");
	cin >> name;
	printf("�������Ա�:\n");
	cin >> sex;
	printf("���������֤��:\n");
	cin >> id;
	printf("������绰����:\n");
	cin >> phone_number;
	printf("�������ַ:\n");
	cin >> address;
	Customer a(user_id, pass_word, name, sex, id, phone_number, address);
	Customer_List[user_id] = a;
}


void Window_Manage::Reset_Password() {
	string user_id, name, id, phone_number,pass_word;
	int type = 0;
	while (1) {
		system("cls");
		printf("�������¼�˺�:\n");
		cin >> user_id;
		printf("����������:\n");
		cin >> name;
		printf("������绰����:\n");
		cin >> phone_number;
		printf("���������֤:\n");
		cin >> id;
		//bool user_id_bool = false, name_bool = false, id_bool = false, phone_number_bool = false;
		if (user_id != Customer_List[user_id].get_user_id()) {
			printf("�û���������\n");
			printf("1.����������Ϣ\n");
			printf("2.�˳�\n");
			printf("����������:\n");
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
			printf("��������\n");
			printf("1.����������Ϣ\n");
			printf("2.�˳�\n");
			printf("����������:\n");
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
			printf("���֤����\n");
			printf("1.����������Ϣ\n");
			printf("2.�˳�\n");
			printf("����������:\n");
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
			printf("�绰�������\n");
			printf("1.����������Ϣ\n");
			printf("2.�˳�\n");
			printf("����������:\n");
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
		printf("������������:\n");
		cin >> pass_word;
		Customer_List[user_id].Set_Name(pass_word);
		printf("��������ɹ�\n");
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
		printf("�������п��б�:\n");
		if (len == 0) {
			printf("�������п�\n");
			printf("1.ע���˻���¼\n");
			printf("����������:\n");
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
			printf("1.�������п�\n");
			printf("2.ע���˻���¼\n");
			printf("������������:\n");
			cin >> type;
			if (type == 1) {
				printf("��������������п���:\n");
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
		
		printf("1.����\n");
		printf("2.�˳�\n");
		int type;
		printf("�����������:\n");
		cin >> type;
		if (type == 1) {
			string temp;
			printf("��������Ҫ�������˻�:\n");
			cin >> temp;
			if (Customer_List.find(temp) == Customer_List.end()) {
				printf("��Ҫ�������˻�������");
				system("pause");
				continue;
			}
			else {
				string pass_word, card_id;
				printf("�����뿨������:\n");
				cin >> pass_word;
				card_id = Customer_List[temp].create_card(pass_word);
				Card_List[card_id] = Customer_List[temp].get_card(card_id);
				printf("�����¿���Ϊ: ");
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
	printf("����������:\n");
	cin >> pass_word;
	while (1) {
		system("cls");
		printf("1.��Ǯ\n");
		printf("2.ȡǮ\n");
		printf("3.ת��\n");
		printf("4.��ӡ����ϸ��\n");
		printf("5.��ѯ���\n");
		printf("6.�˳�\n");
		printf("�����������:\n");
		Card* p = Customer_List[t].get_card(card_id);
		cin >> type;
		if (type == 1) {
			printf("�������Ǯ����:\n");
			cin >> num;
			p->save(num);
			cout << p->get_balance() << endl;
			system("pause");
		}
		else if (type == 2) {
			printf("������ȡǮ����:\n");
			cin >> num;
			if (p->draw(num) == 0) {
				printf("����\n");
				system("pause");
			}
			else {
				printf("ȡǮ�ɹ�\n");
				cout << p->get_balance() << endl;
				system("pause");
			}
		}
		else if (type == 3) {
			printf("������ת������:\n");
			cin >> num;
			printf("������ת�뿨��:\n");
			string temp;
			cin >> temp;
			if (p->transfer_roll_out(num) == 0) {
				printf("����\n");
				system("pause");
			}
			else if(Card_List.find(temp)==Card_List.end()){
				printf("���Ų�����\n");
				system("pause");
			}
			else {
				int i = Card_List[temp]->transfer_thift_to(num);
				printf("ת�˳ɹ�\n");
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
		printf("1.ɾ���˻�\n");
		printf("2.�˳�\n");
		printf("�����������:\n");
		int type;
		cin >> type;
		if (type == 1) {
			printf("��������Ҫɾ���˻����˺�:\n");
			string Customer_ID;
			cin >> Customer_ID;
			printf("��������Ҫɾ���˻�������:\n");
			string PassWord;
			cin >> PassWord;
			if (Customer_List.find(Customer_ID) == Customer_List.end()) {
				printf("���˻�������");
				system("pause");
				continue;
			}
			else {
				if (Customer_List[Customer_ID].get_pass_word() != PassWord) {
					printf("�������");
					system("pause");
					continue;
				}
				else {
					Customer_List.erase(Customer_ID);
					/*Customer_List[Customer_ID].~Customer();*/
					printf("ɾ���ɹ�");
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
		printf("1.����\n");
		printf("2.����\n");
		printf("3.����\n");
		printf("4.����\n");
		printf("5.��ѯ�û���Ϣ\n");
		printf("6.�˳�\n");
		printf("�����������:\n");
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
		printf("1.����\n");
		printf("2.�˳�\n");
		printf("�����������:\n");
		cin >> type;
		if (type == 1) {
			string temp, card_id, password;
			printf("��������Ҫɾ�������˻�:\n");
			cin >> temp;
			printf("��������Ҫɾ�����Ŀ���:\n");
			cin >> card_id;
			printf("��������Ҫɾ����������:\n");
			cin >> password;
			if (Customer_List.find(temp) == Customer_List.end()) {
				printf("���˻�������");
				system("pause");
				continue;
			}
			else {
				if (Card_List.find(card_id) == Card_List.end()) {
					printf("�ÿ�������");
					system("pause");
					continue;
				}
				else {
					if (Card_List[card_id]->get_password() != password) {
						printf("�������");
						system("pause");
						continue;
					}
					else {
						Customer_List[temp].delete_Card(card_id);
						Customer_List.erase(temp);
						printf("ɾ���ɹ�");
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
		printf("1.�鿴��Ϣ\n");
		printf("2.�˳�\n");
		printf("�����������:\n");
		int type;
		cin >> type;
		if (type == 1) {
			string temp;
			printf("��������Ҫ�鿴��Ϣ���˻�:\n");
			cin >> temp;
			if (Customer_List.find(temp) == Customer_List.end()) {
				printf("���˻�������");
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
