#include<iostream>
#include"Char.hpp"
using namespace std;
namespace ds
{
	void print(CharString* ptr)
	{
		while (ptr != nullptr)
		{
			cout << ptr->symbol;
			ptr = ptr->nextSymbol;
		}
	}
	void append(CharString* ptr, char symbol)
	{
		CharString* newSymbol = new CharString{ symbol };
		if (ptr == nullptr)
		{
			throw std::exception("Nullptr");
		}

		while (ptr->nextSymbol != nullptr)
		{
			ptr = ptr->nextSymbol;
		}
		ptr->nextSymbol = newSymbol;
	}
	char characterAt(CharString* ptr, int num)
	{
		int count = 1;
		char result;
		if (ptr == nullptr)
		{
			throw std::exception("Nullptr");
		}
		while ((ptr->nextSymbol != nullptr) && (count < num))
		{
			++count;
			ptr = ptr->nextSymbol;
		}
		result = ptr->symbol;
		return result;
	}
	void removeChars(CharString* ptr, int tar, int dell)
	{
		CharString* temp = ptr;
		if (ptr == nullptr)
		{
			throw std::exception("Nullptr");
		}
		int count = 1;
		while (count < tar - 1)
		{
			++count;
			temp = temp->nextSymbol;
			ptr = ptr->nextSymbol;
		}
		temp = temp->nextSymbol;
		CharString* dele;
		for (int i = 0; i < dell; ++i)
		{
			dele = temp;
			if (temp->nextSymbol != nullptr)
			{
				temp = temp->nextSymbol;
				delete dele;
				ptr->nextSymbol = temp;
			}
			else
			{
				delete temp;
				ptr->nextSymbol = nullptr;
				break;
			}
		}
	}
	void concatenate(CharString* str1, CharString* str2)
	{
		while (str1->nextSymbol != nullptr)
		{
			str1 = str1->nextSymbol;
		}
		str1->nextSymbol = str2;
	}
	CharString* substring(CharString* str, int position, int len)
	{
		for (int i = 1; i < position; ++i)
		{
			str = str->nextSymbol;
		}
		CharString* temp;
		temp = str;
		for (int i = 1; i < len; ++i)
		{
			temp = temp->nextSymbol;
		}
		temp->nextSymbol = nullptr;
		return str;
	}
}
