#pragma once
namespace book

{
	const int SIZE = 20;

	struct Book
	{
		int id;
		char title[SIZE]{};
		char author[SIZE]{};
		float price;
		int quantity;

	};


	void find();

	void add();

	void redact();

	void show_list();

	void show_stat();
}
