#pragma once

#include <string>
#include <vector>
#include <cmath>

using IOException = java::io::IOException;

class RocketStages
{
public:
	static constexpr int N = 11000;
	static constexpr double G = 9.8;
	static std::vector<double> A;

	static int to_i(const std::wstring &s);

	static void main(std::vector<std::wstring> &args);
};
