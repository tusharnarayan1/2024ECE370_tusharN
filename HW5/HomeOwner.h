#include <vector>
#include "HomeElectricalDevice.h" // Include the HomeElectricalDevice header

// Class representing a homeowner
class HomeOwner {
    public: 

    std::vector<HomeElectricalDevice> devices; // Moved to private to enforce encapsulation
    std::string name;

    // Constructor
    HomeOwner(std::string ownerName);

    // Methods
    void addDevice(const HomeElectricalDevice& device, int index);
    float getTotalPowerConsumption() const;
    void printDevices() const; // Added to encapsulate iterating over devices
};
