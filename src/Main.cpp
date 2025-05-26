#include <iostream>
#include <fstream>
#include <cstdint>

#include "./Bdl.hpp"

int main()
{
	std::ifstream file("../ObjectData/Mario/mario.bdl", std::ios::binary);
	file.seekg(0, std::ios::beg);

	BDLFile mario;
	mario.load(file);

	return 0;
};
