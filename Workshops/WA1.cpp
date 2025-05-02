#include <iostream>
#include <vector>


int avgTemp(std::vector<int> temps,int limit);
double avgTemp(std::vector<double> temps,double limit);

int avgTemp(std::vector<int> temps,int lowerLimit,int upperLimit);
double avgTemp(std::vector<double> temps,double lowerLimit,double upperLimit);

template <typename X>
auto avgTemp(const std::vector<X> temps,X limit);

template <typename X>
auto avgTemp(std::vector<X> temps,X lowerLimit,X upperLimit);


int main() {
    std::vector<double> temperatureData = {36.5, 37.2, 15.4, -10.5, -45.0, -55.0, 40.0, 39.8, 38.1, -20.3};
    std::vector<int> intTemperatures = {36, 37, 15, -10, -45, -55, 40, 39, 38, -20};

    std::cout << "Average high-temperature anomaly (using int value method): " << avgTemp(intTemperatures,35) << std::endl;
    std::cout << "Average high-temperature anomaly (using double value method): " << avgTemp(temperatureData,35) << std::endl;

    std::cout << "Average low-temperature anomaly (using int value method): " << avgTemp(intTemperatures,0,-50) << std::endl;
    std::cout << "Average low-temperature anomaly (using double value method): " << avgTemp(temperatureData,0,-50) << std::endl;

    std::cout << "Average high-temperature anomaly (using template function for int values): " << avgTemp(intTemperatures,35) << std::endl;
    std::cout << "Average high-temperature anomaly (using template function for double values): " << avgTemp(temperatureData,35) << std::endl;

    std::cout << "Average low-temperature anomaly (using template function for int values): " << avgTemp(intTemperatures,0,-50) << std::endl;
    std::cout << "Average low-temperature anomaly (using template function for double values): " << avgTemp(temperatureData,0,-50) << std::endl;
    return 0;
}

template <typename X>
auto avgTemp(const std::vector<X>& temps,X limit) {
    X count{0};
    X avgHi{0};
    X sum{0};
    for(const auto& num : temps){
        if(num > limit){
            count++;
            sum += num;
        }
    }
    avgHi = sum/count;
    return (count > 0) ? sum / count : 0; // for faulty sensors //return avgHi;
}

template <typename X>
auto avgTemp(const std::vector<X>& temps,X lowerLimit,X upperLimit){
    X count{0};
    X avgLo{0};
    X sum{0};
    for(const auto& num : temps){
        if(num < lowerLimit && num > upperLimit){
            count++;
            sum += num;
        }
    }
    avgLo = sum/count;
    return (count > 0) ? sum / count : 0; // for faulty sensors//return avgLo;
}


int avgTemp(std::vector<int> temps,int limit){
    int count{0};
    int avgHi{0};
    int sum{0};
    for(int num:temps){
        if(num > limit){
            count++;
            sum += num;
        }
    }
    avgHi = sum/count;
    return (count > 0) ? sum / count : 0; // for faulty sensors //return avgHi;
}

double avgTemp(std::vector<double> temps,double limit){
    double count{0};
    double avgHi{0};
    double sum{0};
    for(double num:temps){
        if(num > limit){
            count++;
            sum += num;
        }
    }
    avgHi = sum/count;
    return (count > 0) ? sum / count : 0; // for faulty sensors //return avgHi;
}

int avgTemp(std::vector<int> temps,int lowerLimit,int upperLimit){
    int count{0};
    int avgLo{0};
    int sum{0};
    for(int num:temps){
        if(num < lowerLimit && num > upperLimit){
            count++;
            sum += num;
        }
    }
    avgLo = sum/count;
    return (count > 0) ? sum / count : 0; // for faulty sensors //return avgLo;
}

double avgTemp(std::vector<double> temps,double lowerLimit,double upperLimit){
    double count{0};
    double avgLo{0};
    double sum{0};
    for(double num:temps){
        if(num < lowerLimit && num > upperLimit){
            count++;
            sum += num;
        }
    }
    avgLo = sum/count;
    return (count > 0) ? sum / count : 0; // for faulty sensors //return avgLo;
}



// g++ -std=c++2b WA1.cpp -o WA1