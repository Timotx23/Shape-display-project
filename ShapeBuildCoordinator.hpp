#pragma once
#include "ShapeBuilder.hpp"
#include <string>



class ShapeBuildCoordinator {
private:
    int shape_size;
    int left_size;
    int right_size;
    bool is_even;
    ShapeBuilder shape;

public:
    explicit ShapeBuildCoordinator(int size);
    void pyramidBuilder();
    void squareBuilder();
    void circleBuilder();
    void displayRow(std::string row);
};