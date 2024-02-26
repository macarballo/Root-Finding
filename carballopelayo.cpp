#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

// function prototypes
void mainMenu();
double testFunction(double x);
void falsePosition(double leftInterval, double rightInterval, int iterationNum);

int main(){
    char menuChoice;
    double leftInterval, rightInterval;
    int iterationNum;

    cout << "CMSC 191 - Root Finding Methods\n";
    cout << "\nProponents: Carballo, Meekah Yzabelle A. (2021-05127)\n";
    cout << "            Pelayo, Khublei Mo Satori (2021-00529)\n";
    cout << "\nA program dedicated to implementing the Bisection, Secant,\nand False Position Methods in C++ for solving equations,\nwith a focus on performance analysis using a simple function.\n";
    
    // Main program loop
    while(1){
        mainMenu();
        cout << "\nEnter choice: ";

        // Input validation for menu choice
        while(!(cin >> menuChoice)){
            // Reset buffer
            cin.clear();
            // Empty buffer
            cin.ignore(std::numeric_limits<std::streamsize>::max());
            cout << "\nInvalid input!";
            cout << "\nEnter a valid choice: ";
        }

        switch (menuChoice)
        {
        case 'a':
            cout << "\nYou chose Bisection Method!\n";
            break;
        case 'b':
            cout << "\nYou chose Secant Method!\n";
            break;
        case 'c': 
            cout << "\nYou chose False Position Method!\n";

            cout << "\nEnter LEFT interval endpoint: ";
            cin >> leftInterval;

            cout << "\nEnter RIGHT interval endpoint: ";
            cin >> rightInterval;

            cout << "\nEnter number of iterations: ";
            cin >> iterationNum;

            // Call falsePosition function with user input
            falsePosition(leftInterval, rightInterval, iterationNum);
            break;
        case 'd':   
            cout << "\nExiting program..";
            exit(0);
            break;
        default:
            cout << "\nInvalid input! Please try again." << endl;
			break;
        }
    }
    return 0;
}

// Display the main menu
void mainMenu(){
    cout << "\n--------------------++--------------------";
    cout << "\nChoose which root finding method to use.\n";
    cout << "   [a] Bisection Method\n";
    cout << "   [b] Secant Method\n";
    cout << "   [c] False Position Method\n";
    cout << "   [d] Exit\n";
}

// Define the test function 
double testFunction(double x){
    return x - cos(x);
}

// Implement the false position method
void falsePosition(double a, double b, int maxIterations){
    double p, f1, f2, f3;
    int i = 0;

    // Calculate function values at the interval
    f1 = testFunction(a); // f(a)
    f2 = testFunction(b); // f(b)

    // Perform iterations of the false position method
    while (i < maxIterations){
        if (f2 - f1 == 0){
            cout << "\nCannot proceed. Division by zero. Exiting...\n";
            return;
        } else {
            // Calculate new approximation
            // Equation to find next approximation
            // p2 = a1 - ((f(a)*(b-a))/(f(b)-f(a)))
            p = a - ((f1 * (b - a)) / (f2 - f1));

            cout << "\nIteration: " << i << " Approx: " << p;
            
            // Calculate function value at the new approximation
            f3 = testFunction(p);
            i++;

            // Update interval based on the sign of the function value
            if ((f1 * f3) < 0){
                b = p;
                f2 = f3; // Update f(b) to f(p)
            } else {
                a = p;
                f1 = f3; // Update f(a) to f(p)
            }
            cout << "\nNew interval is [" << b << ", " << a << "]\n";
        }
    }
    // Output the result after reaching the maximum number of iterations
    cout << "\nNumber of iterations: " << i;
    cout << "\nThe root of the equation is: " << p;
}