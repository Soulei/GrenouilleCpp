#include "include/StrategieNutritive.hpp"
using namespace grenouilloland;

void StrategieNutritive::appliquerEffet(unsigned int& pv, bool& malade) const
{
	pv+=1;
	malade=false;
}

StrategieNutritive::StrategieNutritive()
{
}
