#include <iostream>
#include <fstream>
#include <cstdint>

#include "./Bdl.hpp"

uint32_t swapEndian(uint32_t val) {
    return ((val >> 24) & 0x000000ff) |
           ((val << 8) & 0x00ff0000) |
           ((val >> 8) & 0x0000ff00) |
           ((val << 24) & 0xff000000);
};

uint16_t swapEndian(uint16_t val) {
    return ((val >> 8) | (val << 8));
}

void BDLFile::load(std::ifstream &file)
{
	file.seekg(BDL_MAGIC, std::ios::beg);
	file.read((char*)&this->header.magic, sizeof(this->header.magic));
        std::cout << "magic: " << this->header.magic << std::endl;

        file.seekg(BDL_LENGTH, std::ios::beg);
        file.read((char*)&this->header.length, sizeof(this->header.length));
        this->header.length = swapEndian(this->header.length);
        std::cout << "length: " << this->header.length << std::endl;

        file.seekg(BDL_SECTIONS, std::ios::beg);
        file.read((char*)&this->header.sections, sizeof(this->header.sections));
        this->header.sections = swapEndian(this->header.sections);
        std::cout << "sections: " << this->header.sections << std::endl;

        file.seekg(BDL_SVR, std::ios::beg);
        file.read((char*)&this->header.svr, sizeof(this->header.svr));
        std::cout << "svr: " << this->header.svr << std::endl;

	//Reading INF1;
	file.seekg(INF1_NAME, std::ios::beg);
	file.read((char*)&this->inf1.name, sizeof(this->inf1.name));
	std::cout << "inf1.name: " << this->inf1.name << std::endl;

	file.seekg(INF1_LENGTH, std::ios::beg);
        file.read((char*)&this->inf1.length, sizeof(this->inf1.length));
	this->inf1.length = swapEndian(this->inf1.length);
        std::cout << "inf1.length: " << this->inf1.length << std::endl;

	file.seekg(INF1_NOPACKETS, std::ios::beg);
        file.read((char*)&this->inf1.noPackets, sizeof(this->inf1.noPackets));
	this->inf1.noPackets = swapEndian(this->inf1.noPackets);
        std::cout << "inf1.noPackets: " << this->inf1.noPackets << std::endl;

	file.seekg(INF1_NOCOORDINATES, std::ios::beg);
        file.read((char*)&this->inf1.noCoordinates, sizeof(this->inf1.noCoordinates));
	this->inf1.noCoordinates = swapEndian(this->inf1.noCoordinates);
        std::cout << "inf1.noCoordinates: " << this->inf1.noCoordinates << std::endl;

	file.seekg(INF1_OFFSET, std::ios::beg);
        file.read((char*)&this->inf1.offset, sizeof(this->inf1.offset));
	this->inf1.offset = swapEndian(this->inf1.offset);
        std::cout << "inf1.offset: " << this->inf1.offset << std::endl;

	file.seekg(0x38, std::ios::beg);
	uint16_t type;
	file.read((char*)&type, sizeof(uint16_t));
	type = swapEndian(type);
	std::cout << "type: " << type << std::endl;
};
