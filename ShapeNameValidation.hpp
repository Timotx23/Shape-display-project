#pragma once
#include <string>
#include "ShapeBuildCoordinator.hpp"
#include <functional>


class ShapeNameValidation {
    public:
    std::string cleanedShape(std::string shape);
    bool validShapeName(std::string shape_name) const;
    
    static std::function<void(ShapeBuildCoordinator&)> getShapeFunction(std::string shape_name);
};