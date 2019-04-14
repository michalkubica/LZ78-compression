#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Parameters.h"

template <class T>
class Files
{
private:
	T file; //input or output file
	std::string filename;

public:
	Files(std::string fn) : filename(fn) {}

	std::vector<char> load() //load file into data structure for compression (vector)
	{
		std::vector<char> vec; //vector containing loaded data (text)
		file.open(filename);
		if (file.is_open())
		{
			auto ss = std::ostringstream{};
			ss << file.rdbuf();
			auto s = ss.str();
			file.close();
			std::copy(s.begin(), s.end(), std::back_inserter(vec));
		}
		else std::cout << "Error opening input file\n";
		return vec;
	}

	std::vector<std::pair<int, char>> load(Parameters &p) //load file into data structure for decompression (vector of pairs)
	{
		std::vector<std::pair<int, char>> vec; //vector containing loaded data (pairs <index,character>)
		std::string buffer; //temporary
		int index; //loaded index
		std::string is; //aux
		char c; //loaded character
		std::string control; //aux, checking whether the file is possible to decompress
		int s; //aux, loaded dictionary size
		file.open(filename);
		if (file.is_open())
		{
			file >> control;
			if (strcmp(control.c_str(), "lz78decompressible") != 0) { std::cout << "File not decompressible\n"; return vec; }
			file >> s;
			p.setDictionarySize(s);
			while (file >> buffer)
			{

				is = "";
				for (int i = 0; buffer[i] != ','; ++i) is += buffer[i];
				index = std::stoi(is);
				if (buffer[buffer.size() - 1] == ',') c = ' ';
				else c = buffer[buffer.size() - 1];
				vec.emplace_back(std::make_pair(index, c));
			}
			file.close();
		}
		else std::cout << "Error opening input file\n";
		return vec;
	}

	void save(std::vector<char> const &vec) //export processed data (vector) to file
	{
		file.open(filename);
		if (file.is_open())
		{
			std::ofstream ofs(filename);
			std::copy(vec.begin(), vec.end(), std::ostreambuf_iterator<char>(ofs));
			file.close();
		}
		else std::cout << "Error opening output file\n";
	}

	void save(std::vector<std::pair<int, char>> const &vec, int s) //export processed data (vector of pairs) to file
	{
		file.open(filename);
		if (file.is_open())
		{
			file << "lz78decompressible\n" << s << "\n";
			std::ofstream ofs(filename);
			std::for_each(vec.begin(), vec.end(), [&](auto q)->void { file << q.first << "," << q.second << " "; });
			file.close();
		}
		else std::cout << "Error opening output file\n";
	}
};
