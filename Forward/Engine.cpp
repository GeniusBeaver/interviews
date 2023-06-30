#include "Engine.h"

Engine::Engine() : T_environments(0) {}

Engine::Engine(double T) : T_environments(T), T_engine(T) {}

void Engine::Reset() {
	T_engine = T_environments;
	current_M = M[0];
	current_V = V[0];
}

double Engine::Vc() {
	return C * (T_environments - T_engine);
}

double Engine::Vh() {
	return current_M * Hm + current_V * current_V * Hv;
}