#include "ShapeNameValidation.hpp" 
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include "ShapeBuildCoordinator.hpp"
#include <functional>
#include <iostream>


    std::string ShapeNameValidation::cleanedShape(std::string shape){
        std::transform(
        shape.begin(),
        shape.end(),
        shape.begin(),
        [](unsigned char c) {
            return std::tolower(c);
        }
    );
    return shape;
    }
    bool ShapeNameValidation::validShapeName(std::string shape_name) const{
        
        for (char letter : shape_name){
        if (int (letter) < 97 || int (letter) > 122){//ascii value comparison
            throw std::invalid_argument( std::string("Shape contained invalid digit: ") + letter );
            }
        }
        
        getShapeFunction(shape_name);
        return true;
    }
    
    std::function<void(ShapeBuildCoordinator&)> ShapeNameValidation::getShapeFunction(std::string shape_name){
        static const std::map<std::string, std::function<void(ShapeBuildCoordinator&)>> current_shapes = {
            {"square", [](ShapeBuildCoordinator& shape) {
                shape.squareBuilder();
            }},
            {"circle", [](ShapeBuildCoordinator& shape) {
                shape.circleBuilder();
            }},
            {"pyramid", [](ShapeBuildCoordinator& shape) {
                shape.pyramidBuilder();
            }},
            {"test", [](ShapeBuildCoordinator& shape){
                shape.testBuilder();
            }}
        };
        auto found = current_shapes.find(shape_name);

        if (found == current_shapes.end()) {
            throw std::invalid_argument(
                "Name provided is not in current shape features " + shape_name 
            );
        }

        return found->second;

    }; 
