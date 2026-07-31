#include <string>
#include <iostream>
#include "ShapeBuilder.hpp"
    //This class actually build the shapes row by row
   
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
                std::cout << local_row << "\n"; //fix this
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
    

