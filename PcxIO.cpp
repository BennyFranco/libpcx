#include "PcxIO.h"
#include <fstream>
#include <iostream>

PCXImage ReadPCX(char * fileName)
{
	PCXImage image;
	PCXHeader header;
	char* memblock;
	std::streampos streamPosition;
	int size;

	std::ifstream file(fileName, std::ios::in | std::ios::binary | std::ios::ate);

	if (file.is_open())
	{
		streamPosition = file.tellg();
		size = static_cast<int>(streamPosition) - 128;

		memblock = new char[size];

		file.seekg(0, std::ios::beg);
		file.read(reinterpret_cast<char *>(&header), sizeof(header));

		std::cout << "Header in memory" << std::endl;

		std::cout << "Manufacturer: " << static_cast<int>(header.manufacturer) << std::endl
			<< "Version: " << static_cast<int>(header.version) << std::endl
			<< "X: " << static_cast<long>(header.window.Xmax) << std::endl
			<< "Y: " << static_cast<long>(header.window.Ymax) << std::endl
			<< "ColorMap " << (header.colorMap) << std::endl;

		file.read(memblock, size);
		file.close();

		std::cout << "Image file in memory" << std::endl;
		std::cout << "Size: " << size << std::endl;

		image = PCXImage(header, memblock, size);

	}
	else
	{
        std::cout << "Unable to open file" << std::endl
        << "Filename: " << fileName << std::endl;
	}
	return image;
}

void WritePCX(char * fileName, PCXImage image)
{
	std::ofstream file(fileName, std::ios::binary);

	if (file.is_open())
	{
		PCXHeader header = image.GetHeader();
		char * memblock = image.GetMemblock();

		file.write(reinterpret_cast<char *>(&header), sizeof(header));
		file.write(memblock, image.GetMemSize());

		std::cout << "Image saved!" << std::endl;
	}
	else
	{
		std::cout << "Unable create file" << std::endl;
	}

	file.close();
}

std::string TestMethod()
{
    return "Hello World";
}
