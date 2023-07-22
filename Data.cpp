#include "Data.h"


Data::Data(const int int_, const double double_) : m_int(int_), m_double(double_) {}

void Data::set(const int int_, const double double_) {
	m_int = int_;
	m_double = double_;
}

int Data::get_int() const {
	return m_int;
}

double Data::get_double() const {
	return m_double;
}

void Data::print() const {
	std::cout << "\t\tINT: " << m_int << std::endl;
	std::cout << "\t\tDOUBLE: " << m_double << std::endl << std::endl;
}

void Data::lock() {					//метод для варианта "lock"
	m_mtx.lock();
}

void Data::unlock() {				//метод для варианта "lock"
	m_mtx.unlock();
}

std::mutex& Data::get_mtx() {		//метод для варианта "scoped_lock" и "unique_lock"
	return m_mtx;
}
