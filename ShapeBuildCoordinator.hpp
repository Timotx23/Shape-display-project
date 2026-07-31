#pragma once
#include "ShapeBuilder.hpp"
#include <string>



class ShapeBuildCoordinator {
private:
    int shape_size;
    int left_size;
    int right_size;
    bool is_even;
    std::string Shape;
    ShapeBuilder shape;

public:
    explicit ShapeBuildCoordinator(int size);
    void pyramidBuilder();
    void squareBuilder();
    void circleBuilder();
    void displayShape(std::string shape);
};