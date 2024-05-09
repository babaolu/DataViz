#pragma once

#include "IOmatters.h"
#include "ErrorHandle.h"

double add_sub(std::vector<Token>&, unsigned int&);
double div_mult(std::vector<Token>&, unsigned int&);
double primary(std::vector<Token>&, unsigned int&);
