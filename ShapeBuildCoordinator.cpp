#include <string>
#include <iostream>

#include "ShapeBuilder.hpp"
#include "ShapeSizePrep.hpp"
#include "ShapeBuildCoordinator.hpp"

//change this so its only responsibility is for displauing


ShapeBuildCoordinator::ShapeBuildCoordinator(int size)
    : shape_size(size),
      left_size(0),
      right_size(0),
      is_even(false),
      Shape(""), shape(Shape) {

    ShapeSizePrep prep(size);

    auto [left, right] = prep.splitEvenly();

    left_size = left;
    right_size = right;
    is_even = prep.isEven();
    right_size = right;
    Shape = "";
    
        }
    //this part is like the def __init__() in python initializing the variable shape_size to this instance of the class
    
    void ShapeBuildCoordinator::pyramidBuilder()  {
        std::string get_pyramid = shape.buildPyramid(shape_size);
        displayShape(get_pyramid);
        

        }
    void ShapeBuildCoordinator::squareBuilder()  {
        std::string get_square = shape.buildSquare(shape_size,left_size, right_size);
        displayShape(get_square);
            
    }
    void ShapeBuildCoordinator::circleBuilder(){
        std::string get_circle = shape.buildCircle(shape_size,is_even); //builds the shape -> will always recieve a fully built shape not just rows
        displayShape(get_circle); // displays the shape -> future expandability to display the shape any way i need
        
    }
    void ShapeBuildCoordinator::displayShape(std::string shape){
        std::cout << shape;
    }
