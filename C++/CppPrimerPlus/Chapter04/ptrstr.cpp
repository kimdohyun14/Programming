// ptrstr.cpp -- ���ڿ��� �����ϴ� �������� ���
#include <iostream>
#include <cstring> // strlen(), strcpy()�� ����
int main()
{
	using namespace std;

	char animal[20] = "bear"; // animal�� bear�� ��� �ִ�
	const char* bird = "wren";// bird�� ���ڿ��� �ּҰ� ��� �ִ�
	char* ps;

	cout << animal << " and "; // bear�� ���
	cout << bird << '\n';     // wren�� ���
	// cout << ps <<'\n';     // �����⸦ ����ϰų� ������ �� �� �ִ�

	cout << "������ ������ �Է��Ͻʽÿ�: ";
	cin >> animal;
	// cin >> ps;  // ����� �ؼ��� �� �� ��û�� �Ǽ�
	// ps�� ���Ե� ������ �����ϰ� ���� �ʴ�

	ps = animal;     // ps�� ���ڿ��� �����ϵ��� �����Ѵ�.
	cout << ps << "s!\n";
	cout << "strcpy() �����:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;

	ps = new char[strlen(animal) + 1]; // �� �޸𸮸� �����Ѵ�
	strcpy(ps, animal);                // �� �޸𸮿� ���ڿ��� ����
	cout << "strcpy() �����:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;
	delete[] ps;
	return 0;
}