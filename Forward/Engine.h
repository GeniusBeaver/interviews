#pragma once
#include <array>
const int SIZE = 6;

class Engine {
public:
	const double I = 10; // Момент инерции двигателя
	const std::array<double, SIZE> M = { 20, 75, 100, 105, 75, 0 }; // крутящий момент
	const std::array<double, SIZE> V = { 0, 75, 150, 200, 250, 300 }; // скорость вращения коленвала
	const double T_overheating = 110; // температура перегрева
	const double Hm = 0.01; // Коэффициент зависимости скорости нагрева от крутящего момента
	const double Hv = 0.0001; // Коэффициент зависимости скорости нагрева от скорости вращения коленвала
	const double C = 0.1; // Коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей среды
	double T_environments; // температура окружающей среды
	double current_M = M[0]; // текущий крутящий момент
	double current_V = V[0]; // текущая скорость вращения коленвала
	double T_engine; // температура двигателя

	Engine();
	Engine(double T);
	void Reset(); // функция сброса current_M и current_V
	double Vc(); // функция вычисления скорость охлаждения двигателя
	double Vh(); // функция вычисления скорости нагрева двигателя 
};