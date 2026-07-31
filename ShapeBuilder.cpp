#include <string>
#include <iostream>
#include "ShapeBuilder.hpp"
    //This class actually build the shapes row by row



ShapeBuilder::ShapeBuilder(std::string shape)
    : Shape(shape) {
}
   
std::string ShapeBuilder::buildSquare(int shape_size,int left_size, int right_size){

    for (int row = 1; row <= shape_size; row ++){
            std::string build_left = buildGeneralLeft(left_size, left_size);
            std::string build_right = buildGeneralRight(right_size);
            std::string current_line = build_left  + build_right;
            Shape += current_line;
            Shape += "\n";      
        }
    return Shape;
}

std::string ShapeBuilder::buildPyramid(int shape_size){
    for (int j = 1; j <= shape_size; j ++ ){
            std::string build_left = buildGeneralLeft(j,shape_size);
            std::string build_right = buildGeneralRight(j);
            std::string row = build_left + build_right;
            Shape += row;
            Shape += "\n";
        }
        return Shape;

}
std::string ShapeBuilder::buildCircle(int shape_size, bool is_even){
    int height = shape_size;
    int height_middle = height/2;
    int width = shape_size+2;
    int width_middle = (width/2)+1;
    
        for (int j = 1; j <= height; j ++){
            if (j <=(height_middle) ){
                //Build upper part of circle
                auto [row, local_row]  = buildCircleTop(width, width_middle, height_middle, height,is_even, j);
                j = row;// very bad ediquite 
                Shape += local_row;
                Shape += "\n";
            }
            else{
                //build lower part of cirlce
                std::string local_row = buildCircleLower(width_middle,width, j);
                Shape+=local_row;
                Shape += "\n";
                
            }
        }
    return Shape;

}



std::string ShapeBuilder::buildGeneralRight(int row_size){
        std::string right(row_size, '#');
        return right;
    }
std::string ShapeBuilder::buildGeneralLeft(int row_size, int pi_size){
        int empty_space = pi_size-row_size;
        std::string left(empty_space, ' ');
        while (left.length() < pi_size){
            left += "#";
        }
        return left;
    }


    
std::pair<int, std::string> ShapeBuilder::buildCircleTop( int width, int width_middle, int height_middle,int height,bool is_even, int row){
        int left = width_middle + row;
        int right = width_middle - row;
        std::string local_row = "";
        for (int i = 1; i <= width; i ++) {
            
            if (is_even){
                right = width_middle-1 - row;
                left = width_middle + row;
                }
            if (i == left || i == right){
                local_row += "#";
                }
            else{
                local_row += ".";
                }
            
            if (i == width && row == height_middle && is_even){
                Shape+= local_row;
                Shape += "\n"; 
                row +=1;

                }
        }
        return {row, local_row}; 
        }
std::string ShapeBuilder::buildCircleLower(int width_middle,int width, int row){
        std::string local_row = "";
        int right = row - width_middle + 1;
        int left = row - width_middle + 2;
        for (int l = 1; l <= width; l ++){
            if ( l == left  ||  width-l == right   ){
                local_row += "#";
                }
            else{
                local_row += ".";
                }
            }
        return local_row;
        
        }
    

