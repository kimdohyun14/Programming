// 생성자 초기화 리스트(initializer list)
// 클래스의 const, static 변수
// 레퍼런스 타입을 리턴하는 함수
// this 포인터
// const 멤버 함수

// 생성자 초기화 리스트(initializer list)
#include <iostream>

class Marine {
	int hp;
	int coord_x, coord_y;
	bool is_dead;

	//중요한 값들을 상수로 처리하는 것은 중요하다.
	const int default_damage; //실수로 마린의 데미지를 변경하는 것을 막기위해

public:
	Marine();
	Marine(int x, int y);

	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);

	void show_status();
};

//이니셜라이져를 이용해서 변수를 업데이트한다.
//초기화 리스트를 사용하는 것이 조금 더 효율적인 작업이다.
//생성과 동시에 초기화가 되므로
//const변수도 처음에 초기화가 가능하며, 한 번 초기화하면 변경될 수 없다.
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) { }

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << ", " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "마린1이 마린2를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
	return 0;
}