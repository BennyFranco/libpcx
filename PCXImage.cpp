#include "PCXImage.h"

PCXImage::PCXImage(PCXHeader p_header, char * p_memblock, int p_size):
	m_header(p_header),
	m_memblock(p_memblock),
	m_size(p_size)
{
}

PCXImage::PCXImage()
{
}


PCXImage::~PCXImage()
{
}
