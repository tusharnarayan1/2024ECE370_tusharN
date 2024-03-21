#include "HomeElectricalDevice.h"


HomeElectricalDevice::HomeElectricalDevice(std::string deviceName, float consumption, bool smart)
    : name(deviceName), powerConsumption(consumption), isSmart(smart) {}