#pragma once
#include <string>

#include <utility>
class ShapeBuilder{
    public:
    
    std::string buildSquare(int shape_size,int left_size, int right_size);
    std::string buildPyramid(int shape_size);
    std::string buildCircle(int shape_size, bool is_even);

    std::string buildGeneralRight(int row_size);
    std::string buildGeneralLeft(int row_size, int pi_size);
    std::pair<int,std::string> buildCircleTop( int width, int width_middle, int height_middle,int height,bool is_even, int row);
    std::string buildCircleLower(int width_middle,int width, int row);
    };

