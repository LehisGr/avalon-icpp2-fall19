#include<iostream>
#include"Char.hpp"
using namespace std;
using namespace ds;

int main()
{
	CharString* s1 = new CharString{ 'h' };
	CharString* s2 = new CharString{ 'e' };
	CharString* s3 = new CharString{ 'l' };

	CharString* ptr = nullptr;
	ptr = s1;
	s1->nextSymbol = s2;
	s2->nextSymbol = s3;
	print(ptr);//Hel
	std::cout << std::endl;
	append(ptr, 'l');
	print(ptr);//Hell
	std::cout << endl;
	CharString* empty = nullptr;
	std::cout << characterAt(ptr, 1) << std::endl;//h

	CharString* str = new CharString{ 'a' };//abcdefg
	append(str, 'b');
	append(str, 'c');
	append(str, 'd');
	append(str, 'e');
	append(str, 'f');
	append(str, 'g');
	print(str);
	std::cout << std::endl;
	removeChars(str, 2, 3);
	print(str);
	std::cout << std::endl;//aefg

	CharString* str1 = new CharString{ 'a' };
	append(str1, 'b');
	append(str1, 'c');
	CharString* str2 = new CharString{ 'd' };
	append(str2, 'e');
	append(str2, 'f');
	std::cout << std::endl;
	concatenate(str1, str2);
	print(str1);
	std::cout << std::endl;
	std::cout << std::endl;

	append(str1, 'g');
	print(str1);
	std::cout << std::endl;
	print(substring(str1, 3, 4));
}
