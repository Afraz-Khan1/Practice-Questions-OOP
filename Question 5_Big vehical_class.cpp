#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string type_of_car;
    string make;
    string color;
    int model;
    int year;
    int miles_driven;

public:
    Vehicle(string type, string mk, string clr, int mdl, int yr, int miles)
        : type_of_car(type), make(mk), color(clr), model(mdl), year(yr), miles_driven(miles) {}

    void display() {
        cout << "Type: " << type_of_car << "\nMake: " << make 
             << "\nModel: " << model << "\nColor: " << color
             << "\nYear: " << year << "\nMiles Driven: " << miles_driven << endl;
    }
};

class GasVehicle : virtual public Vehicle {
protected:
    string fuel_tank_size;

public:
    GasVehicle(string type, string mk, string clr, int mdl, int yr, int miles, string fuel)
        : Vehicle(type, mk, clr, mdl, yr, miles), fuel_tank_size(fuel) {}

    void display() {
        Vehicle::display();
        cout << "Fuel Tank Size: " << fuel_tank_size << endl;
    }
};

class ElectricVehicle : virtual public Vehicle {
protected:
    string energy_storage;

public:
    ElectricVehicle(string type, string mk, string clr, int mdl, int yr, int miles, string energy)
        : Vehicle(type, mk, clr, mdl, yr, miles), energy_storage(energy) {}

    void display() {
        Vehicle::display();
        cout << "Energy Storage: " << energy_storage << endl;
    }
};

class HighPerformance : public GasVehicle {
protected:
    int horse_power;
    int top_speed;

public:
    HighPerformance(string type, string mk, string clr, int mdl, int yr, int miles, 
                   string fuel, int hp, int speed)
        : Vehicle(type, mk, clr, mdl, yr, miles), 
          GasVehicle(type, mk, clr, mdl, yr, miles, fuel),
          horse_power(hp), top_speed(speed) {}

    void display() {
        GasVehicle::display();
        cout << "Horse Power: " << horse_power << "\nTop Speed: " << top_speed << endl;
    }
};

class HeavyVehicle : public GasVehicle, public ElectricVehicle {
protected:
    int maximum_weight;
    int number_of_wheels;
    int length;

public:
    HeavyVehicle(string type, string mk, string clr, int mdl, int yr, int miles,
                string fuel, string energy, int weight, int wheels, int len)
        : Vehicle(type, mk, clr, mdl, yr, miles),
          GasVehicle(type, mk, clr, mdl, yr, miles, fuel),
          ElectricVehicle(type, mk, clr, mdl, yr, miles, energy),
          maximum_weight(weight), number_of_wheels(wheels), length(len) {}

    void display() {
        GasVehicle::display();
        cout << "Energy Storage: " << energy_storage 
             << "\nMax Weight: " << maximum_weight
             << "\nWheels: " << number_of_wheels
             << "\nLength: " << length << endl;
    }
};

class SportsCar : public HighPerformance {
protected:
    string gearbox;
    string drive_system;

public:
    SportsCar(string type, string mk, string clr, int mdl, int yr, int miles,
             string fuel, int hp, int speed, string gb, string drive)
        : Vehicle(type, mk, clr, mdl, yr, miles),
          HighPerformance(type, mk, clr, mdl, yr, miles, fuel, hp, speed),
          gearbox(gb), drive_system(drive) {}

    void display() {
        HighPerformance::display();
        cout << "Gearbox: " << gearbox << "\nDrive System: " << drive_system << endl;
    }
};

class ConstructionTruck : public HeavyVehicle {
protected:
    string cargo;

public:
    ConstructionTruck(string type, string mk, string clr, int mdl, int yr, int miles,
                     string fuel, string energy, int weight, int wheels, int len, string crg)
        : Vehicle(type, mk, clr, mdl, yr, miles),
          HeavyVehicle(type, mk, clr, mdl, yr, miles, fuel, energy, weight, wheels, len),
          cargo(crg) {}

    void display() {
        HeavyVehicle::display();
        cout << "Cargo: " << cargo << endl;
    }
};

class Bus : public HeavyVehicle {
protected:
    int number_of_seats;

public:
    Bus(string type, string mk, string clr, int mdl, int yr, int miles,
        string fuel, string energy, int weight, int wheels, int len, int seats)
        : Vehicle(type, mk, clr, mdl, yr, miles),
          HeavyVehicle(type, mk, clr, mdl, yr, miles, fuel, energy, weight, wheels, len),
          number_of_seats(seats) {}

    void display() {
        HeavyVehicle::display();
        cout << "Number of Seats: " << number_of_seats << endl;
    }
};

int main() {
    Bus cityBus("City Bus", "Volvo", "Blue", 2022, 5000,500, "Diesel", "N/A", 15000, 6, 40, 50);
    cityBus.display();
    return 0;
}