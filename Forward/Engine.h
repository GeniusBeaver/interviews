#pragma once
#include <array>
const int SIZE = 6;

class Engine {
public:
	const double I = 10; // ������ ������� ���������
	const std::array<double, SIZE> M = { 20, 75, 100, 105, 75, 0 }; // �������� ������
	const std::array<double, SIZE> V = { 0, 75, 150, 200, 250, 300 }; // �������� �������� ���������
	const double T_overheating = 110; // ����������� ���������
	const double Hm = 0.01; // ����������� ����������� �������� ������� �� ��������� �������
	const double Hv = 0.0001; // ����������� ����������� �������� ������� �� �������� �������� ���������
	const double C = 0.1; // ����������� ����������� �������� ���������� �� ����������� ��������� � ���������� �����
	double T_environments; // ����������� ���������� �����
	double current_M = M[0]; // ������� �������� ������
	double current_V = V[0]; // ������� �������� �������� ���������
	double T_engine; // ����������� ���������

	Engine();
	Engine(double T);
	void Reset(); // ������� ������ current_M � current_V
	double Vc(); // ������� ���������� �������� ���������� ���������
	double Vh(); // ������� ���������� �������� ������� ��������� 
};