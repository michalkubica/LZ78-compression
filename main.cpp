#include "parameters.h"
#include "Compress.h"
#include "Decompress.h"
#include "LZ78_compress.h"
#include "LZ78_decompress.h"
#include <iostream>

int main(int argc, char** argv)
{
	Parameters params; //input parameters
	params.loadInputValues(argc, argv);

	Compress *compressible_data; //compression input data pointer
	Decompress *decompressible_data; //decompression input data pointer
	std::vector<std::pair<int, char>> compressed; //comperssed data
	std::vector<char> decompressed; //decompressed data

	Files<std::ifstream> inputfile(params.getInFilename());
	Files<std::ofstream> outputfile(params.getOutFilename());

	if (params.getWhatToDo() == 'c')
	{
		compressible_data = new LZ78_compress;
		compressible_data->loadData(inputfile);
		compressed = compressible_data->compress(params.getDictionarySize());
		delete compressible_data;
		outputfile.save(compressed, params.getDictionarySize());
	}
	else if (params.getWhatToDo() == 'd')
	{
		decompressible_data = new LZ78_decompress;
		decompressible_data->loadData(inputfile, params);
		decompressed = decompressible_data->decompress(params.getDictionarySize());
		delete decompressible_data;
		if (decompressed.empty()) std::exit(EXIT_FAILURE);
		outputfile.save(decompressed);
	}

	return 0;
}