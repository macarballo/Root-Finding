#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

// function prototypes
void mainMenu();
double testFunction(double x);
double absoluteDifference(double x);
void falsePosition(double leftInterval, double rightInterval, int iterationNum);
void bisection(double leftInterval, double rightInterval, int iterationNum);
void secant(double leftInterval, double rightInterval, int iterationNum);

int main()
{
    char menuChoice;
    double leftInterval, rightInterval;
    int iterationNum;

    cout << "CMSC 191 - Root Finding Methods\n";
    cout << "\nProponents: Carballo, Meekah Yzabelle A. (2021-05127)\n";
    cout << "            Pelayo, Khublei Mo Satori (2021-00529)\n";
    cout << "\nA program dedicated to implementing the Bisection, Secant,\nand False Position Methods in C++ for solving equations,\nwith a focus on performance analysis using a simple function.\n";

    // Main program loop
    while (1)
    {
        mainMenu();
        cout << "\nEnter choice: ";

        // Input validation for menu choice
        while (!(cin >> menuChoice))
        {
            // Reset buffer
            cin.clear();
            // Empty buffer
            cin.ignore(std::numeric_limits<std::streamsize>::max());
            cout << "\nInvalid input!";
            cout << "\nEnter a valid choice: ";
        }

        switch (menuChoice) {
        case 'a':
            cout << "\nYou chose Bisection Method!\n";

            cout << "\nEnter LEFT interval endpoint: ";
            cin >> leftInterval;

            cout << "\nEnter RIGHT interval endpoint: ";
            cin >> rightInterval;

            cout << "\nEnter number of iterations: ";
            cin >> iterationNum;

            // Call falsePosition function with user input
            bisection(leftInterval, rightInterval, iterationNum);
            break;
            break;
        case 'b':
            cout << "\nYou chose Secant Method!\n";

            cout << "\nEnter LEFT interval endpoint: ";
            cin >> leftInterval;

            cout << "\nEnter RIGHT interval endpoint: ";
            cin >> rightInterval;

            cout << "\nEnter number of iterations: ";
            cin >> iterationNum;

            // Call falsePosition function with user input
            secant(leftInterval, rightInterval, iterationNum);
            break;
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
void mainMenu() {
    cout << "\n--------------------++--------------------";
    cout << "\nChoose which root finding method to use.\n";
    cout << "   [a] Bisection Method\n";
    cout << "   [b] Secant Method\n";
    cout << "   [c] False Position Method\n";
    cout << "   [d] Exit\n";
}

// Define the test function
double testFunction(double x) {
    return x - cos(x);
}

double absoluteDifference(double x) {
    return abs(0.73908513321516-x);
}

// Implement the Bisection method
void bisection(double a, double b, int maxIterations) {
    int counter = 0;
    double mid, p, f1, f2, f3, diff;

    //calculate function values at the interval
    f1 = testFunction(a); //f(a)
    f2 = testFunction(b); //f(b)

    //perform iterations of the bisection method
    while (counter < maxIterations)
    {
        if ((f2 - f1) == 0) {
            cout << "\nCannot proceed. Division by zero. Exiting...\n";
            return;
        } else {   
            //calculate the midpoint 
            //to find the next approximation
            mid = (a + b) / 2;
            p = mid;
            cout << "\nIteration: " << counter << " Approx: " << p;
            counter++;

            //calculate the function at new approximation
            f3 = testFunction(p);

            //update intervals
            if ((f3 * f1) > 0) {
                a = p; 
                f1 = f3; //updating their respective function values
            } else {
                b = p;
                f2 = f3;
            }
            cout << "\nNew Interval is [" << a << "," << b << "]\n";
        }
    } 
    diff = absoluteDifference(p);
    //output results upon reaching max iterations
    cout << "\nNumber of iterations: " << counter;
    cout << "\nThe root of the equation is: " << p;
    cout << "\nThe absolute difference from the solution: "<<diff;
}

// Implement the secant method
void secant(double p0, double p1, int maxIterations) {
    int counter = 0;
    double p2, f1, f0, f2, diff;

    //getting the function values of p0 and p1
    f1 = testFunction(p1);
    f0 = testFunction(p0);

    while (counter < maxIterations)
    {
        if ((f1 - f0) == 0) {
            cout << "\nCannot proceed. Division by zero. Exiting...\n";
            return;
        } else {
            //the equation to find the next approximation of the secant method
            p2 = p1 - ((f1 * (p1 - p0)) / (f1 - f0));
            f2 = testFunction(p2);
            cout << "\nIteration : " << counter << " Approx: " << p2;
            counter++;

            //updating the values as well as function values of each variable
            p0 = p1;
            f0 = f1;
            p1 = p2;
            f1 = f2;
            
            //output the new interval after every iteration
            cout << "\nNew Interval is [" << p0 << ", " << p1 << "]\n";
        }
    }
    //output the results after reaching the maximum number of iterations
    diff = absoluteDifference(p2);
    cout << "\nNumber of iterations: " << counter;
    cout << "\nThe root of the equation is: " << p2;
    cout << "\nThe absolute difference from the solution: "<<diff;
}

// Implement the false position method
void falsePosition(double a, double b, int maxIterations) {
    double p, f1, f2, f3, diff;
    int i = 0;

    // Calculate function values at the interval
    f1 = testFunction(a); // f(a)
    f2 = testFunction(b); // f(b)

    // Perform iterations of the false position method
    while (i < maxIterations) {
        if (f2 - f1 == 0) {
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
            if ((f1 * f3) < 0) {
                b = p;
                f2 = f3; // Update f(b) to f(p)
            } else {
                a = p;
                f1 = f3; // Update f(a) to f(p)
            }
            cout << "\nNew interval is [" << a << ", " << b << "]\n";
        }
    }
    // Output the result after reaching the maximum number of iterations
    diff = absoluteDifference(p);
    cout << "\nNumber of iterations: " << i;
    cout << "\nThe root of the equation is: " << p;
    cout << "\nThe absolute difference from the solution: "<<diff;
}