#include "UserCommands.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <stdexcept>
#include "ShapeNameValidation.hpp"
#include "ShapeSizePrep.hpp"
#include <map>


std::pair< int, std::string> UserCommands:: getUserInput(){
    int size = 0;
    std::string shape = "";
    std::cout << "Enter size of the shape: ";
    std::cin >> size;
    std::cout << "Enter what shape you want to build: ";
    std::cin >> shape;
    auto[shapes, sizes] = cleanedUserInput(shape, size);
    return {sizes, shapes};
}
std::pair <std::string, int> UserCommands::cleanedUserInput(std::string shape, int size){
    ShapeNameValidation name_validation;
    ShapeSizePrep size_val(size);

    std::string shapes = name_validation.cleanedShape(shape);
    if (name_validation.validShapeName(shapes) && size_val.validateSize(size)){
        return {shapes, size};
        
    }
    throw std::invalid_argument( "Input shape validation failed" ); // just in case but it will never get this far
    
}







