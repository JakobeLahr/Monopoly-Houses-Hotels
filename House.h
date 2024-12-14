#ifndef HOUSE_H
#define HOUSE_H
#include <stdexcept>

class House {
private:
    static const int COST;    //static cost for a house
    static const int MAX_HOUSES; //max number of houses 
    static int houseCount;    //static counter of houses

public:
    //constructor
    House() {
        if (houseCount < MAX_HOUSES) {
            ++houseCount;
        }
        else {
            throw std::runtime_error("Maximum number of houses reached!");
        }
    }

    //destructor
    ~House() {
    }

    static int getCost() {
        return COST;
    }

    static int getHouseCount() {
        return houseCount;
    }

    //check if more houses can be placed
    static bool canPlaceHouse() {
        return houseCount < MAX_HOUSES;
    }
    static void decrementHouseCount() {
        if (houseCount > 0) {
            --houseCount;
        }
        else {
            throw std::runtime_error("No houses to remove!");
        }
    }
};

//initialize static members
const int House::COST = 50;       //cost per house
const int House::MAX_HOUSES = 32; //32 houses max
int House::houseCount = 0;        //0 houses

#endif 

