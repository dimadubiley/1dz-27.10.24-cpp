#include <iostream>
#include <string>

using namespace std;

class Airplane
{
    string type;
    int pass;
    int maxPass;

public:
    Airplane(string type, int maxPassengers) : type(type), pass(0), maxPass(maxPassengers) {}

    bool operator==(const Airplane& other) const
    {
        return this->type == other.type;
    }

    Airplane& operator++()
    {
        if (pass < maxPass)
        {
            ++pass;
        }
        return *this;
    }

    Airplane& operator--()
    {
        if (pass > 0)
        {
            --pass;
        }
        return *this;
    }

    bool operator>(const Airplane& other) const
    {
        return this->maxPass > other.maxPass;
    }

    void Display() const
    {
        cout << "Type: " << type << ", Passengers: " << pass
            << "/" << maxPass << endl;
    }
};

int main()
{
    int max1, max2;

    cout << "Enter max passengers for Boeing: ";
    cin >> max1;

    cout << "Enter max passengers for Airbus: ";
    cin >> max2;

    Airplane plane1("Boeing", max1);
    Airplane plane2("Airbus", max2);

    if (plane1 == plane2)
    {
        cout << "The planes are of the same type." << endl;
    }
    else
    {
        cout << "The planes are of different types." << endl;
    }

    ++plane1;
    ++plane1;
    plane1.Display();

    --plane1;
    plane1.Display();

    if (plane1 > plane2)
    {
        cout << "Plane 1 can carry more passengers than Plane 2." << endl;
    }
    else
    {
        cout << "Plane 2 can carry more passengers than Plane 1." << endl;
    }
}