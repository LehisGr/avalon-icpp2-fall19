#include "Header.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

namespace book
{
	ifstream in_file;
	ofstream out_file;
	Book buf;
	extern const int SIZE;

	ostream& operator << (ostream& out, Book book)
	{
		out << "Id: " << book.id << ", nazvaniye: " << book.title << ", avtor: " << book.author << ", tcena: " << book.price << ", izdaniy " << book.quantity;
		return out;
	}

	//вспомогательные функции
	int len(char* s)
	{
		int out = 0;
		while (s[out] != '\0')
		{ 
			++out;
		}
		return out;
	}

	void swap(Book& b1, Book& b2)
	{
		Book buf;
		buf = b2;
		b2 = b1;
		b1 = buf;
	}

	char* concatenate(char* first, char* second)//соеденение
	{
		char* out = new char[len(first) + len(second) - 1];
		for (int i = 0; i < len(first); ++i)
		{

			out[i] = first[i];
		}

		for (int i = 0; i < len(second); ++i)
		{
			out[len(first) + i] = second[i];
		}

		out[len(first) + len(second)] = '\0';
		return out;
	}

	void equal(char* reciever, const char* giver)
	{
		int i = 0;
		while (giver[i] != '\0')
		{
			reciever[i] = giver[i];
			++i;
		}
		reciever[i] = '\0';
	}

	void bubble_sort(Book* mass, int size)
	{
		int x = 0;
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < size - 1 - x; ++i)
			{
				if (strcmp(concatenate(mass[i].author, mass[i].title), concatenate(mass[i+1].author, mass[i+1].title)) > 0 )
				{
					swap(mass[i], mass[i + 1]);
					flag = true;
				}
			}
			++x;
		}
	}

	void creat()
	{
		int id = 0;
		Book buf{ 1, "Avtor", "Zagolovok", 150.0, 5 };//можно менять параметры
		char str[20]{ "ya" };
		equal(buf.title, str);
		out_file.open("knigi.bin", istream::out | istream::binary);
		out_file.seekp(sizeof(Book) * id);
		out_file.write(reinterpret_cast<char*>(&buf), sizeof(Book));
		out_file.close();
	}

	Book* read(int& file_size)
	{
		in_file.open("knigi.bin", istream::in | istream::binary);
		in_file.seekg(0, istream::end);
		file_size = (in_file.tellg() / sizeof(Book));
		Book* mass = new Book[file_size];
		in_file.seekg(0);
		for (int i = 0; i < file_size; ++i)
		{
			in_file.read(reinterpret_cast<char*>(mass + i), sizeof(Book));
		}
		in_file.close();
		return mass;
	}

	//основные функции

	//1 - dobavit' knigu
	void add()
	{
		int size;
		cout << "Vvedite zagolovok, avtora, tcenu i kol-vo knig." << endl;
		cin >> buf.title >> buf.author >> buf.price >> buf.quantity;

		in_file.open("knigi.bin", istream::in | istream::binary);
		in_file.seekg(0, istream::end);
		size = (in_file.tellg() / sizeof(Book));
		in_file.close();
		buf.id = size + 1;

		out_file.open("knigi.bin", istream::out | istream::binary | istream::app);
		out_file.seekp(0, istream::end);
		out_file.write(reinterpret_cast<char*>(&buf), sizeof(Book));
		out_file.close();
	}

	//2 - redaktirovat' knigu
	void redact()
	{
		int id;
		int file_size;
		cout << "Vvedite nomer knigi." << endl;
		cin >> id;
		--id;

		Book* mas = read(file_size);
		cout << mas[id] <<endl;
		cout << "Vvedite noviy zagolovok, avtor, tcenu i kol-vo knigi." << endl;
		cin >> mas[id].title >> mas[id].author >> mas[id].price >> mas[id].quantity;
		out_file.open("source.bin", istream::out | istream::binary);
		out_file.write(reinterpret_cast<char*>(mas), sizeof(Book) * file_size);

		out_file.close();
		delete[] mas;
	}

	//3 - nayti kngu po imeni
	void find()
	{
		int file_size;
		char name[SIZE]{};
		bool flag = true;

		cout << "Vvedite nazvaniye knigi." << endl;
		cin >> name;

		in_file.open("knigi.bin", istream::in | istream::binary);
		in_file.seekg(0, istream::end);
		file_size = (in_file.tellg() / sizeof(Book));

		for (int i = 0; i < file_size; ++i)
		{
			in_file.read(reinterpret_cast<char*>(&buf), sizeof(Book));
			if (buf.title == name)
			{
				cout << buf << endl;
				flag = false;
				break;
			}
		}

		in_file.close();

		if (flag)
		{
			cout << "net takoy knigi." << endl;
		}
	}

	//4 - sortirovka po avtoru ili nazvaniyu(просмотр)
	void show_list()
	{
		int file_size;
		Book* mass = read(file_size);

		bubble_sort(mass, file_size);

		for (int i = 0; i < file_size; ++i)
		{
			cout << mass[i] << endl;
		}

		delete[] mass;
	}



	//5- konechnaya tcena i kolichestvo
	void show_stat()
	{
		int file_size;
		int sum_price = 0;
		int sum_quantity = 0;

		in_file.open("knigi.bin", istream::in | istream::binary);
		in_file.seekg(0, istream::end);
		file_size = (in_file.tellg() / sizeof(Book));

		for (int i = 0; i < file_size; ++i)
		{
			in_file.read(reinterpret_cast<char*>(&buf), sizeof(Book));
			sum_price += buf.price;
			sum_quantity += buf.quantity;
		}
		in_file.close();

		cout << "obstchaya stoimost': " << sum_price << ", obstchee kol-vo: " << sum_quantity << endl;
	}
}
