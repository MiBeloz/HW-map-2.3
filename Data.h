#pragma once
#include <stdexcept>
#include <iostream>
#include <mutex>


class Data {
public:
	Data(const int int_, const double double_);
	~Data() {}

	Data& operator=(const Data&) = delete;
	Data& operator=(Data&&) noexcept = delete;
	Data(const Data&) = delete;
	Data(Data&&) noexcept = delete;

	void set(const int int_, const double double_);
	int get_int() const;
	double get_double() const;

	void print() const;

	void lock();				//метод для варианта "lock"
	void unlock();				//метод для варианта "lock"

	std::mutex& get_mtx();		//метод для варианта "scoped_lock" и "unique_lock"

private:
	int m_int;
	double m_double;
	std::mutex m_mtx;
};

