#include "zonemaps.h"
#include <algorithm>

template<typename T>
zonemap<T>::zonemap(std::vector<T> _elements, uint _num_elements_per_zone)
{
    // constructor 
    elements = _elements;
    num_zones = 0;
    num_elements_per_zone = _num_elements_per_zone;
    build();
}

template<typename T>
void zonemap<T>::build ()
{
    std::cout << "building" << std::endl;
    // Create the first zone and push it into zone list. 
    zone<T> current_zone;
    current_zone.max = elements[0];
    current_zone.min = elements[0];
    current_zone.size = 0;
    for (T element : elements) {
        // Create a new zone if current zone is full. 
        // Create new zones at the beginning of each iteration. 
        // Have to check whether the element is the last one if do so at the end.
        if (current_zone.size >= num_elements_per_zone)
        {
            zones.push_back(current_zone);
            zone<T> new_zone;
            current_zone = new_zone;
            current_zone.max = element;
            current_zone.min = element;
            current_zone.size = 0;
            num_zones++;
        }

        current_zone.elements.push_back(element);
        current_zone.size++;
        // Update min and max value
        if (element < current_zone.min) 
            current_zone.min = element;
        if (element > current_zone.max)
            current_zone.max = element;
    }
    // Save the last zone into zonemap. 
    zones.push_back(current_zone);
    // Sort each zone at last. 
    sort_elements();
}

template<typename T>
bool zonemap<T>::query(T key)
{
    // Loop through the zones to see if the key is contained in the range. 
    for (zone<T> z : zones) {
        if (z.min <= key && z.max >= key) {
            // If so, apply binary search in the zone. And if the key is contained, return true. 
            if (std::binary_search(z.elements.begin(), z.elements.end(), key))
                return true;
        }
    }
    // If the key is not contained in all zones, return false.
    return false;
}

template<typename T>
std::vector<T> zonemap<T>::query(T low, T high)
{
    std::vector<T> result;
    // Loop through all zones.
    for (zone<T> z : zones) {
        // If the maximum of a zone is greater than lower bound
        // or the minimum of a zone is less than upper bound, 
        // loop through the zone and add every qulified element to result. 
        if (z.min <= high || z.max >= low) 
            for (T element : z.elements)
                if (element >= low && element <= high)
                    result.push_back(element);
    }
    return result;
}

// Sort elements in each zone to apply binary search. 
template<typename T>
void zonemap<T>::sort_elements()
{
    for (zone<T> z : zones) {
        std::sort(z.elements.begin(), z.elements.end());
    }
}