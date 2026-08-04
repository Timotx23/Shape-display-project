#include <string>
#include <iostream>

#include "ShapeBuilder.hpp"
#include "ShapeSizePrep.hpp"
#include "ShapeBuildCoordinator.hpp"


//change this so its only responsibility is for validating the input (just in case it was done before but for redundency its done again), constructing the shape and in the end displaying it



ShapeBuildCoordinator::ShapeBuildCoordinator(int size)
    
    : parameters(makeParameters(size)){

    }
        
    ShapeParameters ShapeBuildCoordinator::makeParameters(int size) {
        ShapeSizePrep prep(size);
        prep.validateSize(size);
        auto [left, right] = prep.splitEvenly();
        return { // order matters in here
        size,
        left,
        right,
        prep.isEven()
    };
    }
    
    
    
    void ShapeBuildCoordinator::pyramidBuilder()  {
        std::string get_pyramid = shape.buildPyramid(parameters.shape_size);
        displayShape(get_pyramid);
        }
    
    void ShapeBuildCoordinator::squareBuilder()  {
        std::string get_square = shape.buildSquare(parameters.shape_size,parameters.left_size, parameters.right_size);
        displayShape(get_square);    
    }
    
    void ShapeBuildCoordinator::circleBuilder(){
        std::string get_circle = shape.buildCircle(parameters.shape_size,parameters.is_even); //builds the shape -> will always recieve a fully built shape not just rows
        displayShape(get_circle); // displays the shape -> future expandability to display the shape any way i need
        
    }
    
    void ShapeBuildCoordinator::testBuilder(){
        squareBuilder();
        circleBuilder();
        pyramidBuilder();
    }
    
    void ShapeBuildCoordinator::displayShape(const std::string& shape) const{
         std::cout << shape;
}
    
    
