#ifndef BDL_HPP
#define BDL_HPP

#include <fstream>
#include <cstdint>

#include "./Inf1.hpp"

uint32_t swapEndian(uint32_t val);

#define BDL_MAGIC 0x00
#define BDL_LENGTH 0x08
#define BDL_SECTIONS 0x0c
#define BDL_SVR 0x10

struct BDLHeader
{
	char magic[8];
	uint32_t length;	
	uint32_t sections;
	char svr[4];
};

struct BDLFile
{
	//std::ifstream file;
	BDLHeader header;
	INF1 inf1;
	void load(std::ifstream &file);
};

#endif
