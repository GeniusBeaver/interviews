#pragma once
#include "Engine.h"

class TestStation {
private:
	Engine engine;
	int index = 1;

	double Interpolation(); // ������� ���������� ����� ������� ������������

public:
	TestStation();
	TestStation(double T);
	void ChangeT(double T); // ����� ��������� ����������� ���������� �����
	int StartTest1(); // ����� ����� �� ��������
	std::pair<double, double> StartTest2(); // ����� ����� �� ����� ������������ ��������
};