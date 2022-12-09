#include "equipment.h"
#include "jobtitle.h"

float costcomparison(jobtitle jtitle, equipment equip) {
	float percent;
	float a = equip.cost;
	float b = jtitle.monthcost;
	percent = a / (b / 100) - 100;
	return percent;
}