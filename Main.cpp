#include "Header.h"
#include <iostream>
using namespace std;

int main()
{
	int input;
	bool i = true;


	while (i)
	{
		cout << "Vibereti punkt:" << endl << " 1-dobavit' knigu." << endl << "2 -redaktirovat' knigu. " << endl << "3 -nayti kngu po imeni. " << endl << "4 - sortirovka po avtoru ili nazvaniyu."<<endl;
			cout<<"5- konechnaya tcena i kolichestvo."<<endl<<"0 - vixod." << endl;
		cin >> input;


		switch (input)
		{
		case 0:
			i = false;
			break;

		case 1:		
            book::add();
			break;
	
		case 2:
			book::redact();
			break;

		case 3:
			book::find();
			break;

		case 4:
			book::show_list();
			break;

		case 5:
			book::show_stat();
			break;
		}
	}
	return 0;
}
