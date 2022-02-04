#include "zonemaps.h"

template<typename T>
zonemap<T>::zonemap(std::vector<T> _elements, uint _num_elements_per_zone)
{
    // constructor 
    elements = _elements;
    num_zones = 0;
    num_elements_per_zone = _num_elements_per_zone;
    int num_elements_in_current_zone = 0;
    for (T element : elements) {
        // Create a new zone if current zone is full or there is no zone.
        if (num_elements_in_current_zone >= num_elements_per_zone || num_zones == 0)
        {
            zone<T> current_zone;
            zones.push_back(current_zone);
            num_zones++;
        }
        current_zone.elements.push_back(element);
        
    }
}

template<typename T>
bool zonemap<T>::query(T key)
{
    return false;
}

