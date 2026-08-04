#pragma once
#include "ShapeBuilder.hpp"
#include <string>

struct ShapeParameters{
    int shape_size = 0;
    int left_size = 0;
    int right_size = 0;
    bool is_even = false;
    
    std::string printable = "#";//might be usefull in the future if i decide to add different printables ie more than just # 
    std::string spacer = " "; // same here future proofing

};


class ShapeBuildCoordinator {
private:
    static ShapeParameters makeParameters(int size);
    ShapeParameters parameters;
    

    ShapeBuilder shape;

public:
    explicit ShapeBuildCoordinator(int size);
    void pyramidBuilder();
    void squareBuilder();
    void circleBuilder();
    void testBuilder();
    void displayShape(const std::string& shape) const;
};