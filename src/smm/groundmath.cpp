#include "smm/groundmath.h"


float nextExpRand(float expect){
	return -(log(rand()/(float)RAND_MAX)/log(2.78281828)) * expect;
}
