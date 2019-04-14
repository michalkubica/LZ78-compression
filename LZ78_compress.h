#pragma once
#include "Compress.h"
#include <vector>

class LZ78_compress : public Compress
{
private:
	std::vector<char> data; //input data

public:
	virtual std::vector<std::pair<int, char>> compress(int s);
	virtual void loadData(Files<std::ifstream> &inputfile) { data = inputfile.load(); }
};
