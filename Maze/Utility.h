#pragma once
#include <time.h>
#include <cstdlib>

public class Utility {
public:
	static int getRand() { srand((int)time(0)); return rand() % 4; }; //0-3
};
