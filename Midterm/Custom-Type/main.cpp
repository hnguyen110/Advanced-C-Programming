#include <iostream>

using namespace std;

#include "Bouquet.h"

int main() {
    cout << "Testing default constructor" << std::endl;
    Bouquet first;
    if (first.isEmpty()) {
        cout << "Passed" << std::endl;
    } else {
        cout << "Default constructor failed" << std::endl;
    }

    cout << "Testing custom constructor" << std::endl;
    try {
        Bouquet second(nullptr, 3);
    } catch (std::string err) {
        if (err == "Bad Parameters") {
            cout << "Passed" << std::endl;
        } else {
            cout << "Custom constructor exception failed" << std::endl;
        }
    }

    cout << "Testing compare operator" << std::endl;
    try {
        std::string flowerNames[] = {"Iris", "Rose", "Maquia"};
        Bouquet second(flowerNames, 3);
        Bouquet third(flowerNames, 3);
        if (second == third) {
            cout << "Passed" << std::endl;
        } else {
            cout << "Compare failed" << std::endl;
        }
    } catch (std::string err) {
        cout << err;
    }

    try {
        std::string flowerNames[] = {"Iris", "Poison Ivy", "Maquia"};
        Bouquet second(flowerNames, 3);
        Bouquet third(flowerNames, 3);
        if (second == third) {
            cout << "Passed" << std::endl;
        } else {
            cout << "Compare failed" << std::endl;
        }
    } catch (int err) {
        if (err == 1) {
            cout << "Passed" << std::endl;
        } else {
            cout << "Compare failed, should return 1 error code" << std::endl;
        }
    }

    cout << "Testing false compare" << std::endl;
    try {
        std::string flowerNames[] = {"Iris", "Poison", "Maquia"};
        std::string flowerNames2[] = {"Iris", "Poison ", "Maqu"};

        Bouquet second(flowerNames, 3);
        Bouquet third(flowerNames2, 3);
        if (second == third) {
            cout << "Fail" << std::endl;
        } else {
            cout << "Compare passed" << std::endl;
        }
    } catch (int err) {
        if (err == 1) {
            cout << "Passed" << std::endl;
        } else {
            cout << "Compare failed, should return 1 error code" << std::endl;
        }
    }

    try {
        std::string flowerNames[] = {"Poisong Ivy", "Ivy", "Maquia"};
        Bouquet second(flowerNames, 3);
        Bouquet third(flowerNames, 3);
        if (second == third) {
            cout << "Passed" << std::endl;
        } else {
            cout << "Compare failed" << std::endl;
        }
    } catch (int err) {
        if (err == 2) {
            cout << "Passed" << std::endl;
        } else {
            cout << "Compare failed, should return 1 error code" << std::endl;
        }
    }

    try {
        std::string flowerNames[] = {"Poisong Ivy", "Ivy", "Maquia"};
        Bouquet second;
        Bouquet third(flowerNames, 3);
        if (second == third) {
            cout << "Passed" << std::endl;
        } else {
            cout << "Compare failed" << std::endl;
        }
    } catch (int err) {

    }
}
