#include "Ddong_GEN.h"

Ddong_GEN::Ddong_GEN(){
	ddong_gen_period = 0;
	ddong_speed = 0;
}

void Ddong_GEN::update(Score& score){
	/*
		주기적으로 랜덤 속도를 가진 똥이 랜덤 위치에서 생성되도록 하는 코드 작성
	 */
	if (rand() % 60 >= 55 - ddong_gen_period and ddongs.size() < 20 + ddong_gen_period) {
		Ddong ddong(rand() % 680, (float)(rand() % (5 + ddong_speed) + 10) / 10.0f);
		ddongs.push_back(ddong);
	}

	int i = 0;
	for (auto& _e : ddongs){
		_e.update(score);
		if (_e.destroyed == true) {
			ddongs.erase(ddongs.begin() + i);
		}
		i++;
	}
}

void Ddong_GEN::draw(RenderWindow& _window){
	for (auto& _e : ddongs){
		_e.draw(_window);
	}
}

bool Ddong_GEN::checkHit(FloatRect _rect){
	for (auto& _e : ddongs){
		if (_rect.intersects(_e.getArea()) == true && _e.destroyed == false){
			_e.destroyed = true;
			return true;
		}
	}
	return false;
}

void Ddong_GEN::levelUp() {
	ddong_gen_period++;
	ddong_speed += 1.0f;
}