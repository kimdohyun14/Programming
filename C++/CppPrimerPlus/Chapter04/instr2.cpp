// instr2.cpp -- getline() �Լ��� �� ���� �д´�.
#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "�̸��� �Է��ϼ���:\n";
	cin.getline(name, ArSize); // ���� ���ڰ� �ִ� ������ �д´�.
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ�:\n";
	cin.getline(dessert, ArSize);
	cout << "���ִ� " << dessert;
	cout << " ����Ʈ�� �غ��ϰڽ��ϴ�. " << name << " ��!\n";
	return 0;
}