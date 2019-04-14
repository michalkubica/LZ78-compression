#pragma once
#include <string>

struct InputValues //input prameters
{
	char what_to_do; //compress or decompress
	std::string input_filename;
	std::string output_filename;
	int dictionary_size;
};

class Parameters
{
private:
	InputValues parameters; //input parameters
	public:
	void loadInputValues(int argc, char** argv); //handling input parameters
	char getWhatToDo() { return parameters.what_to_do; }
	std::string getInFilename() { return parameters.input_filename; }
	std::string getOutFilename() { return parameters.output_filename; }
	int getDictionarySize() { return parameters.dictionary_size; }
	void setDictionarySize(int s) { parameters.dictionary_size = s; }
};

