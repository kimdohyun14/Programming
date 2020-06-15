#include <iostream>

class Date
{
	int year_;
	int month_;
	int day_;

public:
	void SetDate(int year, int month, int day);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	// �ش� ���� �� �� ���� ���Ѵ�.
	int GetCurrentMonthTotalDays(int year, int month);

	void ShowDate();

	// ����Ʈ ������
	Date()
	{
		year_ = 2020;
		month_ = 6;
		day_ = 11;
	}

	// ������ (������ �����ε�)
	Date(int year, int month, int day)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}


};

void Date::SetDate(int year, int month, int day)
{
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month)
{
	static int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month != 2)
	{
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		return 29;  // ����
	}
	else
	{
		return 28;
	}
}

void Date::AddDay(int inc)
{
	while (true)
	{
		// ���� ���� �� �� ��
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		// ���� �� �ȿ� ���´ٸ�
		if (day_ + inc <= current_month_total_days)
		{
			day_ += inc;
			return;
		}
		else
		{
			// �����޷� �Ѿ�� �Ѵ�.
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc)
{
	AddYear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc)
{
	year_ += inc;
}

void Date::ShowDate()
{
	std::cout << "������ " << year_ << "�� " << month_ << "�� " << day_ << "�� �Դϴ�." << std::endl;
}

int main()
{
	Date day(2011, 3, 1);
	day.ShowDate();

	day.AddYear(10);
	day.ShowDate();

	Date day2 = Date();
	day2.ShowDate();
	return 0;
}