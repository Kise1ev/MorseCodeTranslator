#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& str, char delimiter);

vector<string> translateMorseToLatin(const string& message);