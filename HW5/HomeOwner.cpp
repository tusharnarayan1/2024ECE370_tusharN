#include "HomeOwner.h"
#include <iostream>

// HomeOwner constructor
HomeOwner::HomeOwner(std::string ownerName)
    : name(ownerName) {}

// Add a new electrical device at a specified index
void HomeOwner::addDevice(const HomeElectricalDevice& device, int index) {
    if (index >= 0 && index <= devices.size()) {
        devices.insert(devices.begin() + index, device);
    } else {
        std::cerr << "Invalid index. Device not added." << std::endl;
    }
}

// Calculate total power consumption
float HomeOwner::getTotalPowerConsumption() const {
    float totalConsumption = 0.0f;
    for (const auto& device : devices) {
        totalConsumption += device.powerConsumption;
    }
    return totalConsumption;
}

// Print out details of all devices
void HomeOwner::printDevices() const {
    for (const auto& device : devices) {
        std::cout << " - Name: " << device.name
                  << ", Power Consumption: " << device.powerConsumption
                  << " Watts, Smart Device: " << (device.isSmart ? "Yes" : "No") << std::endl;
    }
}