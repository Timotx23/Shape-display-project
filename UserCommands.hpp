#pragma once
#include <iostream>
class UserCommands {

public:
    std::pair< int, std::string> getUserInput();
    
    int getShapeSize();
    std::string  getShapeName();


};
