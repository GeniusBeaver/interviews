#pragma once
#include "Engine.h"

class TestStation {
private:
	Engine engine;
	int index = 1;

	double Interpolation(); // функция вычисления точки методом интерполяции

public:
	TestStation();
	TestStation(double T);
	void ChangeT(double T); // метод изменения температуры окружающей среды
	int StartTest1(); // старт Теста на перегрев
	std::pair<double, double> StartTest2(); // старт теста на поиск максимальной мощности
};