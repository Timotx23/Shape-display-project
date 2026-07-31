#pragma once
#include <utility>

class ShapeSizePrep{
    private:
        int shape_size;
    public:
        explicit ShapeSizePrep(int shape_size);
        bool isEven() const;
        std::pair<int, int> splitEvenly() const;
        bool validateSize(int shape_size) const;

};

