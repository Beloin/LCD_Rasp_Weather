//
// Created by beloin on 12/10/23.
//

#include "drivers/WeatherStatusTask.h"
#include "string"

std::string Sensors::StatusToString(Status status) {
    switch (status) {
        case Error:
            return "Error";
        case Imprecise:
            return "Imprecise";
        case Ok:
            return "Ok";
    }
}