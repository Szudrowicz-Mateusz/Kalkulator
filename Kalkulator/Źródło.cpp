#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline void variable(double& a)
{
	cout << "Give your second number" << endl;
	cin >> a;
}

template<typename T>inline T dodawanie(const T &a,const T &b, vector<string>& h)
{
	h.push_back(to_string(a) + "+" + to_string(b) + "=" + to_string(a + b));
	return a + b;
}

template<typename T>inline T odejmowanie(const T& a,const T& b, vector<string>& h)
{
	h.push_back(to_string(a) + "-" + to_string(b) + "=" + to_string(a - b));
	return a - b;
}

template<typename T>inline T mnozenie(const T& a, const T& b, vector<string>& h)
{
	h.push_back(to_string(a) + "*" + to_string(b) + "=" + to_string(a * b));
	return a * b;
}

template<typename T>inline T dzielenie(const T& a, const T& b, vector<string> &h)
{
	h.push_back(to_string(a) + "/" + to_string(b)+"="+to_string(a/b));
	return a / b;
}

void show_result(const double& r)
{
	cout <<"Result is: " << r << endl;
}

int main()
{

	double nd_nr, result;

	cout << "Give the first number:" << endl;
	cin >> result;

	vector<string> history{""};

//Pêtla naszego kalkulatora
	while (true)
	{
		int choice;
		

		
		
		cout << "0. Dodawanie" << endl;
		cout << "1. Odejmowanie" << endl;
		cout << "2. Mnozenie" << endl;
		cout << "3. Dzielenie" << endl;
		cout << "4. Czyszczenie" << endl;
		cout << "5. Exit" << endl;
		cout << "6. Pokaz historie" << endl;
		cout << "Co chcialbys zrobic: ";
		cin>>choice;

		switch(choice)
		{
			//Dodawanie
			case 0:
				variable(nd_nr);
				result = dodawanie(result, nd_nr, history);
				break;
			//Odjemowanie
			case 1:
				variable(nd_nr);
				result = odejmowanie(result, nd_nr, history);
				break;
			//Mno¿enie
			case 2:
				variable(nd_nr);
				result = mnozenie(result, nd_nr, history);
				break;
			//Dzielenie
			case 3:
				variable(nd_nr);
				result = dzielenie(result, nd_nr,history);
				break;
			//Czyszczenie wyników z poprzedniych dzia³añ
			case 4:
				for (int i = 0; i <= history.size(); i++) history.pop_back();
				cout << "Give the first number:" << endl;
				cin >> result;
				break;
			//Zakoñczenie programu
			case 5:
				exit(1);
				break;
			case 6:
				for (auto elemnt : history)
				{
					cout << elemnt << endl;
				}
				char exit_variable;
				cout << "Press anything to continue"<<endl;
				cin >> exit_variable;
				break;
		}
		system("cls");
		show_result(result);
		
		
	}

	return 0;
}