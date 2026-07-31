#pragma once
#include <iostream>
class UserCommands {

public:
    std::pair< int, std::string> getUserInput();
    std::pair<std::string, int> cleanedUserInput(std::string shape, int size);
};
