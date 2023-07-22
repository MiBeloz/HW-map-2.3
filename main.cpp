#include <iostream>

#include "Data.h"


void swap(Data& obj_one, Data& obj_two);

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tЗащищенный обмен данными\n\n" << std::endl;

	Data obj_one(5, 5.5);
	Data obj_two(7, 7.7);

	std::cout << "\tПервый объект:" << std::endl;
	obj_one.print();
	std::cout << "\tВторой объект:" << std::endl;
	obj_two.print();

	std::cout << "Метод swap()..." << std::endl << std::endl;
	swap(obj_one, obj_two);

	std::cout << "\tПервый объект:" << std::endl;
	obj_one.print();
	std::cout << "\tВторой объект:" << std::endl;
	obj_two.print();

	system("pause > nul");
	return 0;
}

//функция для варианта "lock"
//void swap(Data& obj_one, Data& obj_two) {
//	obj_one.lock();
//	obj_two.lock();
//
//	int i = obj_one.get_int();
//	double d = obj_one.get_double();
//
//	obj_one.set(obj_two.get_int(), obj_two.get_double());
//	obj_two.set(i, d);
//
//
//	obj_one.unlock();
//	obj_two.unlock();
//}

//функция для варианта "scoped_lock"
//void swap(Data& obj_one, Data& obj_two) {
//	std::scoped_lock sl(obj_one.get_mtx(), obj_two.get_mtx());
//
//	int i = obj_one.get_int();
//	double d = obj_one.get_double();
//
//	obj_one.set(obj_two.get_int(), obj_two.get_double());
//	obj_two.set(i, d);
//}

//функция для варианта "unique_lock"
void swap(Data& obj_one, Data& obj_two) {
	std::unique_lock ul1(obj_one.get_mtx(), std::defer_lock);
	std::unique_lock ul2(obj_two.get_mtx(), std::defer_lock);
	std::lock(ul1, ul2);

	int i = obj_one.get_int();
	double d = obj_one.get_double();

	obj_one.set(obj_two.get_int(), obj_two.get_double());
	obj_two.set(i, d);
}
