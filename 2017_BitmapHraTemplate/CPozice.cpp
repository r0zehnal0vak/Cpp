#include "stdafx.h"
#include "CPozice.h"

CPozice::CPozice(void)
{
	x = 0;
	y = 0;
}

CPozice::~CPozice(void)
{
}

bool CPozice::operator==(CPozice pozice)
{
	if ((x == pozice.x) && (y == pozice.y)) return(true);
	else return(false);
}

bool CPozice::operator>=(CPozice pozice)
{
	if ((x >= pozice.x) && (y >= pozice.y)) return true;
	else return false;
}

bool CPozice::operator<=(CPozice pozice)
{
	if ((x <= pozice.x) && (y <= pozice.y)) return true;
	else return false;
}
