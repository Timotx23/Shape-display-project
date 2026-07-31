#include "UserCommands.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <stdexcept>
#include "ShapeBuildCoordinator.hpp"
#include "ShapeNameValidation.hpp"
#include "SystemCoord.hpp"
#include <map>




SystemCoord::SystemCoord(bool test_mode)  

    : test_mode(test_mode) {
}
    std::string shape = "";
    int size = 0;

bool SystemCoord::isTestMode() const {
    return test_mode;
}
std::pair< int, std::string> SystemCoord::userInput(){
    //add some test mode verification later
    UserCommands user_input;
    auto[size, shape_name] =  user_input.getUserInput();
    return {size, shape_name};

}



void SystemCoord::BuildShape(std::string shape, int size){
    ShapeBuildCoordinator shape_constructor(size);
    auto shape_function = ShapeNameValidation::getShapeFunction(shape);
    shape_function(shape_constructor);

}
void SystemCoord::runSystem(){
    auto[size, shape_name] = SystemCoord::userInput();
    SystemCoord::BuildShape(shape_name,size);
    
}






