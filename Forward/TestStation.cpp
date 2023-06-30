#include "TestStation.h"
double eps = 0.000001;
int MAX_TIME = 600;

TestStation::TestStation() = default;

TestStation::TestStation(double T) : engine(T) {}

double TestStation::Interpolation() {
	double slope_tangent = (engine.M[index] - engine.M[index - 1]) / (engine.V[index] - engine.V[index - 1]);
	double present_value = engine.M[index - 1] - slope_tangent * engine.V[index - 1];
	engine.current_M = slope_tangent * engine.current_V + present_value;

	return engine.current_M / engine.I;
}

void TestStation::ChangeT(double T) {
	engine.T_environments = T;
}

int TestStation::StartTest1() {
	int time = 0;
	double a = engine.current_M / engine.I;
	
	while (engine.T_overheating - engine.T_engine > eps && MAX_TIME > time) {
		++time;
		engine.current_V += a;

		if (index < SIZE - 1)
			index += engine.current_V > engine.V[index] ? 1 : 0;

		a = Interpolation();

		engine.T_engine += engine.Vc() + engine.Vh();
	}

	engine.Reset();
	return time;
}

std::pair<double, double> TestStation::StartTest2() {
	double max_N = 0;
	double max_V = 0;
	double a = engine.current_M / engine.I;
	
	while (engine.current_M > eps) {
		engine.current_V += a;

		if (index < SIZE - 1)
			index += engine.current_V > engine.V[index] ? 1 : 0;

		a = Interpolation();

		double tempN = engine.current_M * engine.current_V / 1000;
		if (tempN > max_N) {
			max_N = tempN;
			max_V = engine.current_V;
		}
	}

	engine.Reset();
	return std::pair<double, double>(max_N, max_V);
}