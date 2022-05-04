#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <windows.h>
#include <list>
#include <string>
#include <iterator>

#define len 4



using namespace std;
int *number;
char* answer;

string symbols = "!@#$%^&*()-_+=;:,./?|`~[]{}";
string num = "0123456789";
string upper_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lower_alpha = "abcdefghijklmnopqrstuvwxyz";

void sketch() {
	cout << "       ,";
	cout << "       \`-._           __"<< endl;
	cout << "        \\  `-..____,.'  `."<< endl;
	cout << "         :`.         /    \`." <<endl;
	cout << "         :  )       :      : \\" << endl;
	cout << "          ;'        '   ;  |  :" <<endl;
	cout << "          )..      .. .:.`.;  :" << endl;
	cout << "         /::...  .:::...   ` ;" << endl;
	cout << "         ; _ '    __        /:\\" << endl;
	cout << "         `:o>   /\o_>      ;:. `." << endl;
	cout << "        `-`.__ ;   __..--- /:.   \\" << endl;
	cout << "        === \_/   ;=====_.':.     ;" << endl;
	cout << "         ,/'`--'...`--....        ;" <<endl;
	cout << "              ;                    ;" <<endl;
	cout << "            .'                      ;" <<endl;
	cout << "          .'                        ;" << endl;
	cout << "        .'     ..     ,      .       ;" << endl;
	cout << "      :       ::..  /      ;::.     |" << endl;
	cout << "      /      `.;::.  |       ;:..    ;" << endl;
	cout << "     :         |:.   :       ;:.    ;" << endl;
	cout << "     :         ::     ;:..   |.    ;" << endl;
	cout << "      :       :;      :::....|     |" << endl;
	cout << "      /\     ,/ \      ;:::::;     ;" << endl;
	cout << "    .:. \:..|    :     ; '.--|     ;" << endl;
	cout << "   ::.  :''  `-.,,;     ;'   ;     ;" << endl;
	cout << ".-'. _.'\      / `;      \,__:      \\" << endl;
	cout << "`---'    `----'   ;      /    \,.,,,/" << endl;
	cout << "                   `----`              " << endl;
	cout << "=========WELCOME!=========" << endl;
}
string key_generator() {
	string key = ""; 
	string symbols = upper_alpha+num;
	srand(time(NULL));
	for (int a = 1; a <= 19; a++) {
		if (a % 5 == 0) {
			key += "-";
		}
		else {
			key += symbols[rand() % 36 + 1];
		}
	}
	return key;

}
string password(){
	string pass = "";
	string res[len] = {symbols, num, upper_alpha, lower_alpha};
	srand(time(NULL));
	for (int i = 0; i < 8; i++) {
		for (int a = 0; a < 4; a++)
		{
			int c = rand()%36+1;
			pass += (res[a][c]);
		}
	}
	return pass;
}

void run_key_generator(int times){
	list <string> keys_list;
	while(keys_list.size() < times) {
		string key = key_generator();
		keys_list.push_front(key);
		keys_list.unique();
		Sleep(1);
	}
	for (auto i = keys_list.begin(); i != keys_list.end(); i++) {
		cout << *i << endl;
	}
	keys_list.clear();
}

void run_generator_passwords(int times) {
for (int b = 0; b < times; b++)
	{
		Sleep(10);
		cout << password()<< endl;
	}
}

void main_func() {
	cout << "1 - return to home page" << endl
		<< "2 - generate passwords" << endl
		<< "3 - generate keys (XXXX-XXXX-XXXX-XXXX)" << endl
		<< "entry here:  ";
	answer = new char;
	cin >> answer;
	cout << endl;
	switch (*answer)
	{
	case '1':
		system("clear");
		sketch();
		main_func();
		delete answer;
		delete number;
	case '2':
		cout << "number of passwords: ";
		number = new int;
		cin >> *number;
		if(number > 0) {
			run_generator_passwords(*number);
		}
		else{
			cout << "number is empty!" << endl
				<< "entry now: ";
			cin >> *number;
			run_generator_passwords(*number);
		}
		cout << "1 - return to home page" << endl
		<< "2 - generate passwords one more time" << endl 
		<< "entry here:  ";
		cin >> answer;
		switch (*answer)
		{
		case '1':
		{system("clear");
		sketch();
		main_func();
		delete answer;
		delete number; }
		case'2': run_generator_passwords(*number);
			cout << "1 - return to home page" << endl
				<< "2 - generate passwords one more time" << endl
				<< "entry here:  ";
			cin >> answer;
		default:
			break;
		}
	case '3':
		cout << "number of keys: ";
		number = new int;
		cin >> *number;
		if(number > 0){
			run_key_generator(*number);
		}
		else {
			cout << "number is empty!" << endl << "entry now: ";
			cin >> *number;
			run_key_generator(*number);
		}
		cout << "1 - return to home page" << endl
			<< "2 - generate keys one more time" << endl << "entry here:  ";
		cin >> answer;
		switch (*answer)
		{
		case '1':
			system("clear");
			sketch();
			main_func();
			delete answer;
			delete number;
		case '2':
			run_key_generator(*number);
			cout << "1 - return to home page" << endl
				<< "2 - generate keys one more time" << endl << "entry here:  ";
			cin >> answer;
		default:
			break;
		}
	default:
		break;
	}
}
int main(){
	sketch();
	while (true) {
		main_func();
	}
	return 0;
}