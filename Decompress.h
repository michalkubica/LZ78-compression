#pragma once
#include <fstream>
#include <vector>
#include "Files.h"
#include "Parameters.h"

class Decompress
{
public:
	virtual std::vector<char> decompress(int s) = 0; //decompression algorithm
	virtual void loadData(Files<std::ifstream> &inputfile, Parameters &p) = 0; //loading data from file
	virtual ~Decompress() {}
};