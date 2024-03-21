#include <iostream>
#include "HomeElectricalDevice.h"
#include "HomeOwner.h"


int main() {
    HomeElectricalDevice heater("Space Heater", 1200.0f, false);
    HomeElectricalDevice microwave("Microwave", 900.0f, false);
    HomeElectricalDevice therm("Smart Thermostat", 15.0f, true);

    HomeOwner homeowner("Tushar Narayan");

    homeowner.addDevice(heater, homeowner.devices.size());
    homeowner.addDevice(microwave, homeowner.devices.size());
    homeowner.addDevice(therm, homeowner.devices.size());

    std::cout << "Homeowner: " << homeowner.name << std::endl;
    std::cout << "Total Power Consumption: " << homeowner.getTotalPowerConsumption() << " Watts" << std::endl;
    std::cout << "Devices Owned:" << std::endl;
    homeowner.printDevices();
    
    return 0;
}