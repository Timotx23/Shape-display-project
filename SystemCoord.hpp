#pragma once
#include "ShapeBuilder.hpp"
#include "ShapeBuildCoordinator.hpp"
#include "UserCommands.hpp"
#include "ShapeNameValidation.hpp"

class SystemCoord {
private:
    bool test_mode;

public:
    explicit SystemCoord(bool test_mode);

    bool isTestMode() const;
    std::pair< int, std::string> userInput();
    void BuildShape(std::string shape, int size);
    void runSystem();
    
    
};
