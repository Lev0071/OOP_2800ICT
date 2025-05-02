// StreetType.cpp

#include "StreetType.hpp"
#include <string>

std::string to_string(StreetType type) {
    switch (type) {
        case StreetType::Road: return "Road";
        case StreetType::Street: return "Street";
        case StreetType::Avenue: return "Avenue";
        case StreetType::Boulevard: return "Boulevard";
        case StreetType::Drive: return "Drive";
        case StreetType::Lane: return "Lane";
        case StreetType::Court: return "Court";
        case StreetType::Crescent: return "Crescent";
        case StreetType::Place: return "Place";
        case StreetType::Parade: return "Parade";
        case StreetType::Circuit: return "Circuit";
        case StreetType::Terrace: return "Terrace";
        case StreetType::Esplanade: return "Esplanade";
        case StreetType::Close: return "Close";
        case StreetType::Way: return "Way";
        case StreetType::Highway: return "Highway";
        default: return "Unknown";
    }
}
