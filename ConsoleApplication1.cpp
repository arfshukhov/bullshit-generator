#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <windows.h>

#define len 4

using namespace std;
int number;

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

string password(){
	srand(time(NULL));
	string pass = "";
	string symbols = "!#$%&'()*+,-./:;<=>?[`{|}~]^_";
	string num = "0123456789";
	string upper_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lower_alpha = "abcdefghijklmnopqrstuvwxyz";
	string res[len] = {symbols, num, upper_alpha, lower_alpha};
	for (int i = 0; i < 8; i++) {
		for (int a = 0; a < 4; a++)
		{
			int c = rand()%33;
			pass += (res[a][c]);
		}
	}
	return pass;
}

void run_generator(int times) {
for (int b = 0; b < times; b++)
	{
		Sleep(1000);
		cout << password()<< endl;
	}
}

void main_func() {
	cout << "1 - return to home page" << endl
	<< "2 - entry the number of passwords that you want and run" << endl
	<< "3 - generate passwords one more time";
	char answer;
	cin >> answer;
	switch (answer)
	{
	case '1':
		system("clear"); sketch(); main_func();
	case '2':
		cout << "number of passwords: "; cin >> number; 
	case '3':
		if(number > 0) {
			run_generator(number);	
		}
		else{
			cout << "number is empty!" << endl<< "entry now: ";
			cin >> number;
			run_generator(number);
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