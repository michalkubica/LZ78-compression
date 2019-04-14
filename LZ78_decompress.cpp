#include "LZ78_decompress.h"
#include <string>
#include <map>

std::vector<char> LZ78_decompress::decompress(int s)
{
	std::vector<char> out; //output vector
	std::map<int, std::string> dictionary;
	int i = 0; //input vector of pairs index
	int n = data.size(); //input vector of pairs size
	int index = 1; //dictionary index
	std::string subsequence;
	std::map<int, std::string>::iterator it; //found subsequence iterator

	while (i < n)
	{
		if (data[i].first == 0)
		{
			out.push_back(data[i].second);
			subsequence = data[i].second;
			dictionary.insert(std::pair<int, std::string>(index, subsequence));
		}
		else
		{
			it = dictionary.find(data[i].first);
			subsequence = it->second;
			subsequence += data[i].second;
			for (int j = 0; j < subsequence.size(); ++j) out.push_back(subsequence[j]);
			dictionary.insert(std::pair<int, std::string>(index, subsequence));
		}
		++i;
		++index;

		if (dictionary.size() == s)
		{
			dictionary.clear();
			index = 1;
		}
	}
	return out;
}