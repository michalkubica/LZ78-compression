#include "LZ78_compress.h"
#include <string>
#include <map>
#include <algorithm>

std::vector<std::pair<int, char>> LZ78_compress::compress(int s)
{
	std::vector<std::pair<int, char>> out; //output vector of pairs
	std::map<int, std::string> dictionary; 
	int index = 1; //dictionary index
	int found_prev; //index of longest found subsequence
	int i = 0; //input vector index
	int n = data.size(); //input vector size
	std::string subsequence;
	std::map<int, std::string>::iterator it; //found subsequence iterator
	bool flag = true; //aux controlling range

	while (i < n)
	{
		subsequence = data[i];
		flag = true;
		do
		{
			it = std::find_if(dictionary.begin(), dictionary.end(), [&](auto q)->bool { return subsequence == q.second; });
			if (it != dictionary.end() && i != n - 1)
			{
				++i;
				subsequence += data[i];
				found_prev = it->first;
				flag = false;
			}
			else if (flag) found_prev = 0;
			if (i == n - 1) break;
		} while (it != dictionary.end());

		dictionary.insert(std::pair<int, std::string>(index, subsequence));
		out.emplace_back(std::make_pair(found_prev, data[i]));

		++index;
		++i;

		if (dictionary.size() == s)
		{
			dictionary.clear();
			index = 1;
		}
	}
	return out;
}