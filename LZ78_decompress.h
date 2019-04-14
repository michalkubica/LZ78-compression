#pragma once
#include <vector>
#include <fstream>
#include "Parameters.h"
#include "Decompress.h"

class LZ78_decompress : public Decompress
{
private:
	std::vector<std::pair<int, char>> data; //input data

public:
	virtual std::vector<char> decompress(int s);
	virtual void loadData(Files<std::ifstream> &inputfile, Parameters &p) { data = inputfile.load(p); }
};