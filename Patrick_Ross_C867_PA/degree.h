#pragma once
#include <iostream>
#include <string>

#ifndef DEGREE_H
#define DEGREE_H


using namespace std;

enum Degree { SECURITY, NETWORK, SOFTWARE };
static const string degreeString[] = { "Security", "Network", "Software" };

#endif
