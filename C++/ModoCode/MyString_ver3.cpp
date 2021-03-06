#include <iostream>
#include <cstring>

class MyString
{
	char* string_content;
	int string_length;
	int memory_capacity;

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);

	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int size);

	void print() const;
	void println() const;

	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	char at(int i) const;

	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
};

MyString::MyString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
	memory_capacity = 1;
}

MyString::MyString(const char* str)
{
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str[i];
}


MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}


MyString::~MyString()
{
	delete[] string_content;
}

int MyString::length() const
{
	return string_length;
}

void MyString::print() const
{
	for (int i = 0; i != string_length; i++)
		std::cout << string_content[i];
}

void MyString::println() const
{
	for (int i = 0; i != string_length; i++)
		std::cout << string_content[i];

	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str)
{
	if (str.string_length > memory_capacity)
	{
		// 이러면 다시 할당해줘야 한다.
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}

	for (int i = 0; i != str.string_length; i++)
		string_content[i] = str.string_content[i];

	/* 중요한 점

	   굳이 str.string_length + 1  ~ string_length 부분은 초기화 시킬 필요가 없다.
	   왜냐하면 거기 까지는 읽어들이지 않기 때문이다.
	*/

	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str)
{
	int str_length = strlen(str);
	if (str_length > memory_capacity)
	{
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}

	for (int i = 0; i != str_length; i++)
		string_content[i] = str[i];

	string_length = str_length;

	return *this;
}

int MyString::capacity() const
{
	return memory_capacity;
}

void MyString::reserve(int size)
{
	if (size > memory_capacity)
	{
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];

		delete[] prev_string_content;
	}

	// 만일 예약하려는 size 가 현재 capacity 보다 작다면
	// 아무것도 안해도 된다. 오히려 하면 비효율적인 비용이 발생.
}

char MyString::at(int i) const
{
	if (i >= string_length || i < 0) return NULL;
	else return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str)
{
	// 범위를 벗어나는 경우, 수행 x
	if (loc < 0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity)
	{
		memory_capacity = string_length + str.string_length;

		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		// insert 되는 부분 직전까지의 내용을 복사
		int i;
		for (i = 0; i < loc; i++)
			string_content[i] = prev_string_content[i];

		// 새롭게 insert 되는 문자열을 넣는다.
		for (int j = 0; j != str.string_length; j++)
			string_content[i + j] = str.string_content[j];

		// 이제 다시 원 문자열의 나머지 뒷 부분을 복사한다.
		for (; i < string_length; i++)
			string_content[i + str.string_length] = prev_string_content[i];

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}

	// 만일 초과하지 않는 경우 굳이 동적 할당을 할 필요가 없게 된다.
	// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
	for (int i = string_length - 1; i >= loc; i--)
		string_content[i + str.string_length] = string_content[i];

	// 그리고 insert 되는 문자 다시 넣기
	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];

	string_length = string_length + str.string_length;
	return *this;
}

MyString& MyString::insert(int loc, const char* str)
{
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c)
{
	MyString temp(c);
	return insert(loc, temp);
}

int main()
{
	MyString str1("very long string");
	MyString str2("<some string inserted between>");
	str1.reserve(30);

	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();

	str1.insert(5, str2);
	str1.println();
	return 0;
}