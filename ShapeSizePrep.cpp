#include "ShapeSizePrep.hpp"
#include <stdexcept>
#include <string>


ShapeSizePrep::ShapeSizePrep(int shape)
    //This class is meant to check for invalid user inputs, verify inputs, and prep inputs before the shapes are being built
        : shape_size(shape){

        }
    bool ShapeSizePrep::validateSize(int shape_size) const {
        if (shape_size < 0){
            throw std::invalid_argument( "Invalid shape size. Must be positive" );
        }
        return true;
    }
    
    bool ShapeSizePrep::isEven() const {
        return shape_size%2 == 0;
    }
    std::pair < int, int >ShapeSizePrep::splitEvenly() const{
        
        int right_side = shape_size/2;
        int left_side = shape_size - right_side;
        return {left_side, right_side};
        }
    

