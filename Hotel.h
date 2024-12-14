#ifndef HOTEL_H
#define HOTEL_H
#include <stdexcept>
#include "House.h"

class Hotel {
private:
    static const int COST;      //hotel cost
    static const int MAX_HOTELS; //maximum number of hotels
    static int hotelCount;      //static counter for hotels
    static const int HOUSES_PER_HOTEL; //number of houses needed for a hotel

public:
    //constructor
    Hotel() {
        //check if we can place a hotel
        if (hotelCount < MAX_HOTELS) {
            //check if there are enough houses to replace
            if (House::getHouseCount() >= HOUSES_PER_HOTEL) {
                //replace houses with a hotel
                for (int i = 0; i < HOUSES_PER_HOTEL; ++i) {
                    House::decrementHouseCount(); //custom method to decrement house count
                }
                ++hotelCount;
            }
            else {
                throw std::runtime_error("Not enough houses to build a hotel!");
            }
        }
        else {
            throw std::runtime_error("Maximum number of hotels reached!");
        }
    }

    //destructor
    ~Hotel() {
    }

    static int getCost() {
        return COST;
    }

    static int getHotelCount() {
        return hotelCount;
    }

    static bool canPlaceHotel() {
        return hotelCount < MAX_HOTELS && House::getHouseCount() >= HOUSES_PER_HOTEL;
    }
};

//statics
const int Hotel::COST = 200;           //cost of a hotel
const int Hotel::MAX_HOTELS = 12;      //12 hotel max
const int Hotel::HOUSES_PER_HOTEL = 4; //4 houses per hotel
int Hotel::hotelCount = 0;             //Start 

#endif
