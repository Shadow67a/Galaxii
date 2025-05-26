#ifndef INF1_HPP
#define INF1_HPP

#include <cstdint>

#define INF1_BEGIN 0x20
#define INF1_NAME INF1_BEGIN + 0x0
#define INF1_LENGTH INF1_BEGIN + 0x4
#define INF1_NOPACKETS INF1_BEGIN + 0x0c
#define INF1_NOCOORDINATES INF1_BEGIN + 0x10
#define INF1_OFFSET INF1_BEGIN + 0x14

struct Node
{
	uint16_t type;
	uint16_t index;
};

struct INF1
{
	char name[4];
	uint32_t length;
	uint32_t noPackets;	
	uint32_t noCoordinates;
	uint32_t offset;
};

#endif
