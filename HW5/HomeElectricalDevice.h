#ifndef HOME_ELECTRICAL_DEVICE_H
#define HOME_ELECTRICAL_DEVICE_H
#include <string>

class HomeElectricalDevice {
public:
    std::string name;
    float powerConsumption;
    bool isSmart;

    HomeElectricalDevice(std::string deviceName, float consumption, bool smart);
};
#endif // HOME_ELECTRICAL_DEVICE_H