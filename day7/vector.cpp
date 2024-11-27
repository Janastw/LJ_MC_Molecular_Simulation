#include <iostream>
#include <vector>

typedef std::array<double, 3> AtomCoord;
typedef std::vector<AtomCoord> Coordinates;


int main(void)
{
    int n_doubles = 16;

    std::vector<double> data(16);

    std::cout << "Elements in vector: " << data.size() << std::endl;

    data.push_back(1.234);
    std::cout << "Elements in vector: " << data.size() << std::endl;
    std::cout << "0-th element: " << data[0] << std::endl;

    data[0] = 5.678;
    std::cout << "0-th element: " << data[0] << std::endl;

    data.clear();
    std::cout << "Elements in vector: " << data.size() << std::endl;

    std::cout << "1-st element: " << data.at(1) << std::endl;

    //std::cout << "1-st element " << data.at(1) << std::endl;

    //std::array<int, 5> arr;
    // arr[0] = 3.14;
    // arr[1] - 6.28;
    // arr.at(5);

    Coordinates coordinates;
    AtomCoord coord1 = {1.0, 2.0, 3.0};
    coordinates.push_back(coord1);
    
    std::cout << coordinates[0][0];

    return 0;
}