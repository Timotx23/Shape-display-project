#include <string>
#include <iostream>

#include "ShapeBuilder.hpp"
#include "ShapeSizePrep.hpp"
#include "ShapeBuildCoordinator.hpp"



ShapeBuildCoordinator::ShapeBuildCoordinator(int size)
    : shape_size(size),
      left_size(0),
      right_size(0),
      is_even(false) {

    ShapeSizePrep prep(size);

    auto [left, right] = prep.splitEvenly();

    left_size = left;
    right_size = right;
    is_even = prep.isEven();
    right_size = right;
        }
    //this part is like the def __init__() in python initializing the variable shape_size to this instance of the class
    
    void ShapeBuildCoordinator::pyramidBuilder()  {
        for (int j = 1; j <= shape_size; j ++ ){
            
            std::string build_left = shape.buildGeneralLeft(j,shape_size);
            std::string build_right = shape.buildGeneralRight(j);
            std::string row = build_left + " " + build_right;
            displayRow(row); 
        }

        }
    void ShapeBuildCoordinator::squareBuilder()  {

        for (int row = 1; row <= shape_size; row ++){
            std::string build_left = shape.buildGeneralLeft(left_size, left_size);
            std::string build_right = shape.buildGeneralRight(right_size);
            std::string rows = build_left  + build_right;
            displayRow(rows);
        }
            
    }
    void ShapeBuildCoordinator::circleBuilder(){
        int height = shape_size;
        int height_middle = height/2;
        int width = shape_size+2;
        int width_middle = (width/2)+1;
    
        for (int j = 1; j <= height; j ++){
            if (j <=(height_middle) ){
                //Build upper part of circle
                auto [row, local_row]  = shape.buildCircleTop(width, width_middle, height_middle, height,is_even, j);
                j = row;// very bad ediquite 
                displayRow(local_row);
            }
            else{
                //build lower part of cirlce
                std::string local_row = shape.buildCircleLower(width_middle,width, j);
                displayRow(local_row);
                
            }
        }
    }
    void ShapeBuildCoordinator::displayRow(std::string row){
        std::cout << row << '\n';


    }