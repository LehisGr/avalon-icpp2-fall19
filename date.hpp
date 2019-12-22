#pragma once
#include <iostream>
namespace ext
{
	enum Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};
  
	enum class DateFormat
	{
		MonthAsInt,
		MonthAsString
	};
  
	enum class Season
	{
		Winter,
		Spring,
		Summer,
		Autumn
	};
  
	enum class SortBy
	{
		Date,
		Season
	};
  
	struct Date
	{
		int year;
		Month month;
		int day;
	};
  
	struct TimeDelta
	{
		int delta;
	};
  
	TimeDelta countJND(Date date) {
		int a, y, m, day = date.day, month = date.month, year = date.year;
		TimeDelta JDN;
		a = (14 - month) / 12;
		y = year + 4800 - a;
		m = month + (12 * a) - 3;
		JDN.delta = day + int((153 * m + 2) / 5) + int(365 * y) + int(y / 4) - int(y / 100) + int(y / 400) - 32045;
		return JDN;
	}
  
	TimeDelta countDistance(Date from, Date to) {
		TimeDelta CountJND;
		CountJND.delta = countJND(to).delta - countJND(from).delta;
		return CountJND;
	}
  
	void print(Month month, DateFormat format) {
		if (format != DateFormat::MonthAsString) {
			int output = static_cast<int>(month);
			cout << output;
		}
		else {
			switch (static_cast<int>(month)) {
			case 1:
				cout << "January";
				break;
			case 2:
				cout << "February";
				break;
			case 3:
				cout << "March";
				break;
			case 4:
				cout << "April";
				break;
			case 5:
				cout << "May";
				break;
			case 6:
				cout << "June";
				break;
			case 7:
				cout << "July";
				break;
			case 8:
				cout << "August";
				break;
			case 9:
				cout << "September";
				break;
			case 10:
				cout << "October";
				break;
			case 11:
				cout << "November";
				break;
			case 12:
				cout << "December";
				break;
			}
		}
	}
  
	void print(Date data, DateFormat format) {
		if (format != DateFormat::MonthAsString) {
			cout << data.day << "." << data.month << "." << data.year;
		}
		else {
			cout << data.day << " ";
			print(data.month, DateFormat::MonthAsString);
			cout << " " << data.year;
		}
	}
	void print(TimeDelta delta) {
		cout << delta.delta;
	}
  
	Season getSeason(Date date) {
		Month month = date.month;
		switch (static_cast<int>(month)) {
		case 1:
		case 2:
		case 12:
			return Season::Winter;
			break;
		case 3:
		case 4:
		case 5:
			return Season::Spring;
			break;
		case 6:
		case 7:
		case 8:
			return Season::Summer;
			break;
		case 9:
		case 10:
		case 11:
			return Season::Autumn;
			break;
		}
	}
  
	Season getSeason(Month month) {
		switch (static_cast<int>(month)) {
		case 1:
		case 2:
		case 12:
			return Season::Winter;
			break;
		case 3:
		case 4:
		case 5:
			return Season::Spring;
			break;
		case 6:
		case 7:
		case 8:
			return Season::Summer;
			break;
		case 9:
		case 10:
		case 11:
			return Season::Autumn;
			break;
		}
	}
  
	bool operator == (const Date lhs, const Date rhs) {
		if ((lhs.year == rhs.year) && ((static_cast<int>(lhs.month)) == (static_cast<int>(rhs.month))) && (lhs.day == rhs.day)) {
			return true;
		}
		else {
			return false;
		}
	}
  
	bool operator != (const Date lhs, const Date rhs) {
		return !(lhs == rhs);
	}
  
	bool operator < (const Date lhs, const Date rhs) {
		if ((lhs.year < rhs.year) || ((lhs.year == rhs.year) && (static_cast<int>(lhs.month)) < (static_cast<int>(rhs.month))) || ((lhs.year==lhs.year) && ((static_cast<int>(lhs.month)) == (static_cast<int>(rhs.month)) && (lhs.day < rhs.day)))) {
			return true;
		}
		else {
			return false;
		}
	}
  
	bool operator <= (const Date lhs, const Date rhs) {
		if ((lhs < rhs) || (lhs == rhs)) {
			return true;
		}
		else {
			return false;
		}
	}
  
	bool operator > (const Date lhs, const Date rhs) {
		return !(lhs < rhs);
	}
  
	bool operator >= (const Date lhs, const Date rhs) {
		if ((lhs > rhs) || (lhs == rhs)) {
			return true;
		}
		else {
			return false;
		}
	}
  
	Date ToDate(TimeDelta delta) {
		Date output;
		int a = delta.delta + 32044;
		int b = ((4 * a) + 3) / 146097;
		int c = a - ((146097 * b) / 4);
		int d = ((4 * c) + 3) / 1461;
		int e = c - ((1461 * d) / 4);
		int m = ((5 * e) + 2) / 153;
		output.day = e - ((153 * m + 2) / 5) + 1;
		output.month = static_cast<Month>(m + 3 - 12 * (m / 10));
		output.year = (100 * b) + d - 4800 + (m / 10);
		return output;
	}
  
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta delta1;
		delta1.delta = lhs.delta + rhs.delta;
		return delta1;
	}
  
	Date operator + (const Date date, const TimeDelta delta) {
		TimeDelta delta1 = countJND(date);
		return ToDate(delta1 + delta);
	}
  
	Date operator + (const TimeDelta delta, const Date date) {
		TimeDelta delta1 = countJND(date);
		return ToDate(delta1 + delta);
	}
  
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta delta1;
		delta1.delta = lhs.delta - rhs.delta;
		return delta1;
	}
  
	Date operator - (const Date date, const TimeDelta delta) {
		TimeDelta delta1 = countJND(date);
		return ToDate(delta1 - delta);
	}
  
	Date operator - (const TimeDelta delta, const Date date) {
		TimeDelta delta1 = countJND(date);
		return ToDate(delta - delta1);
	}
  
	TimeDelta operator * (const TimeDelta delta, int multiplier) {
		TimeDelta delta1;
		delta1.delta = (delta.delta * multiplier);
		return delta1;
	}
  
	TimeDelta operator / (const TimeDelta delta, int multiplier) {
		TimeDelta delta1;
		delta1.delta = (delta.delta / multiplier);
		return delta1;
	}
  
	TimeDelta operator ++ (TimeDelta& delta) {
		delta.delta += 1;
		return delta;
	}
  
	TimeDelta operator ++ (TimeDelta& delta, int) {
		delta.delta += 1;
		return delta;
	}
  
	TimeDelta operator -- (TimeDelta& delta) {
		delta.delta -= 1;
		return delta;
	}
  
	TimeDelta operator -- (TimeDelta& delta, int) {
		delta.delta -= 1;
		return delta;
	}
  
	Date operator ++ (Date& delta) {
		TimeDelta delta1;
		delta1 = countJND(delta);
		delta1.delta += 1;
		return ToDate(delta1);
	}
  
	Date operator ++ (Date& delta, int) {
		TimeDelta delta1;
		delta1 = countJND(delta);
		delta1.delta += 1;
		return ToDate(delta1);
	}
  
	Date operator -- (Date& delta) {
		TimeDelta delta1;
		delta1 = countJND(delta);
		delta1.delta -= 1;
		return ToDate(delta1);
	}
  
	Date operator -- (Date& delta, int) {
		TimeDelta delta1;
		delta1 = countJND(delta);
		delta1.delta -= 1;
		return ToDate(delta1);
	}

	void swap(Date& lhs, Date& rhs) {
		Date temp;
		temp.day = lhs.day;
		temp.month = lhs.month;
		temp.year = lhs.year;
		lhs.day = rhs.day;
		lhs.month = rhs.month;
		lhs.year = rhs.year;
		rhs.day = temp.day;
		rhs.month = temp.month;
		rhs.year = temp.year;
	}


	void swap(TimeDelta& lhs, TimeDelta& rhs) {
		Date lhs1, rhs1;
		lhs1 = ToDate(lhs);
		rhs1 = ToDate(rhs);
		swap(lhs1, rhs1);
	}

	Date & max(Date & lhs, Date & rhs) {
		if (lhs > rhs) {
			return lhs;
		}
		else{
			return rhs;
		}
	}

	Date & min(Date & lhs, Date & rhs) {
		if (rhs < lhs) {
			return rhs;
		}
		else {
			return lhs;
		}
	}

	Date & getMinDate(Date dates[], int size) {
		Date min;
		min = dates[0];
		for (int i = 1; i < size; i++) {
			if (min > dates[i]) {
				min = dates[i];
			}
		}
		return min;
	}

	Date & getMaxDate(Date dates[], int size) {
		Date max;
		max = dates[0];
		for (int i = 1; i < size; i++) {
			if (max < dates[i]) {
				max = dates[i];
			}
		}
		return max;
	}

	void sort(Date dates[], SortBy sortBy) {
		if (sortBy == SortBy::Date) {
			for (int i = 0; i < (sizeof(dates) / sizeof(*dates)) - 1; i++) {
				for (int j = 0; j < static_cast<int>(sizeof(dates) / sizeof(*dates)) - 1 - i; j++) {
					if (dates[i] < dates[i + 1]) {
						swap(dates[i], dates[i + 1]);
					}
				}
			}
		}
		else {
			int sequence[] = { 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 1 };
			for (int i = 0; i < (sizeof(dates) / sizeof(*dates)) - 1; i++) {
				for (int j = 0; j < static_cast<int>(sizeof(dates) / sizeof(*dates)) - 1 - i; j++) {
					if (sequence[dates[i].month] > sequence[dates[i + 1].month]) {
						swap(dates[i], dates[i + 1]);
					}
				}
			}
		}	
	}
  
	Date * tryFillDate(int year, int month, int day) {
		Date date;
		Date *date1 =& date;
		(*date1).day = day;
		(*date1).month = static_cast<Month>(month);
		(*date1).year = year;
		bool isVisokosniy = ((year % 4 == 0) && (year & 100 != 0)) || (year % 400 == 0);
		if ((month > 12) || (month < 1)) {
			return nullptr;
		}
		else {
			switch (month) {
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) {
					return nullptr;
				}
				else {
					cout << "true" << endl;
					return date1;
				}
				break;
			case 2:
				if ((isVisokosniy && day <= 29) || (day <= 28)) {
					cout << "true" << endl;
					return date1;
				}
				else {
					return nullptr;
				}
				break;
			default:
				if (day > 31) {
					return nullptr;
				}
				else {
					cout << "true" << endl;
					return date1;
				}
				break;
			}
		}
	}
} 
