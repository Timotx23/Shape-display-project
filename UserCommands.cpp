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

    std::string shape_name = getShapeName();
    int size = getShapeSize();
    return {size, shape_name};
}


std::string UserCommands:: getShapeName(){
    std::string shape_name = "";
    std::cout << "Enter what shape you want to build: ";
    std::cin >> shape_name;
    ShapeNameValidation name_validation;
    std::string cleaned_shape_name = name_validation.cleanedShape(shape_name);
    
    if (name_validation.validShapeName(cleaned_shape_name)){
        
         return cleaned_shape_name;
    }
    throw std::invalid_argument( "Input shape name validation failed" ); // just in case but it will never get this far
}
int UserCommands:: getShapeSize(){
    
    int size = 0;
    std::cout << "Enter size of the shape: ";
    std::cin >> size;
    ShapeSizePrep size_val(size);
    
    //if (!(std::cin >> size)) {
       // throw std::invalid_argument("Shape size must be a number");
    //}
    
    if(size_val.validateSize(size)){
        return size;
    }
    throw std::invalid_argument( "Input shape size validation failed" ); // just in case but it will never get this far
    


}







