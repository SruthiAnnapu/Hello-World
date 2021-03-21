#pragma once

#include <string>
#include <vector>
#include "test.h"

int main(int argc, char **argv)
{
    std::vector<std::wstring> args(argv + 1, argv + argc);
    RocketStages::main(args);
}

