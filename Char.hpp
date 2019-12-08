#pragma once
namespace ds
{
	struct CharString
	{
		char symbol;
		CharString* nextSymbol;
	};
	void append(CharString* ptr, char symbol);
	void print(CharString* ptr);
	char characterAt(CharString* ptr, int num);
	void removeChars(CharString* ptr, int tar, int dell);
	void concatenate(CharString* str1, CharString* str2);
	CharString* substring(CharString* str, int position, int len);
}
