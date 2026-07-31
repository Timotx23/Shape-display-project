#include <string>
#pragma once
class ShapeBuilder{
    public:
    std::string buildGeneralRight(int row_size);
    std::string buildGeneralLeft(int row_size, int pi_size);
    std::pair<int,std::string> buildCircleTop( int width, int width_middle, int height_middle,int height,bool is_even, int row);
    std::string buildCircleLower(int width_middle,int width, int row);
    };

