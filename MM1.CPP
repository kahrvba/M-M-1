/*This is code devoloped by Ahmed Mohammed*/
#include <iostream>
#include <cmath>
#include <iomanip> // For tabuler view
#include <fstream>
#include <cstdlib> // For open file and append value to it
using namespace std;

double startRho; // The starting rho that eventually will increment
double endRho;
double stepValue;
int serviceRate;
double ArrivalRate;
double numberCus;
double responceTime;
double MeanNumCusInQueue; // Mean number of customers waiting in the queue

void MM1Calculation(){

    cout << "Start value of Rho= ? ";
    cin >> startRho;
  
    cout << "The end value of Rho= ? ";
    cin >> endRho;
    
    cout << "Step value= ? ";
    cin >> stepValue;
   
    cout << "Service Rate, Mu= ? ";
    cin >> serviceRate;
 
    // Print tabluler header
    cout << left
         << setw(10) << "Rho"
         << setw(15) << "N"
         << setw(10) << "RT"
         << endl;
    cout << string(65, '-') << endl; // Separator line

    if (stepValue == 0.1) {
        // Open output file
        std::ofstream outputFile("NvsRho_s1.txt");
        // vaildation message
        if (!outputFile) {
            cerr << "Error: could not open file NvsRho_s1.txt" << endl;
            return;
        }
        // Open output file2
        std::ofstream outputFile2("RTvsRho_s1.txt");
        // Second validation for the second output file
        if (!outputFile2) {
            cerr << "Error: could not open file RTvsRho_s1.txt" << endl;
            return;
        }
        
        // While loop to generate the corresponding values
        while (startRho <= endRho) {
            ArrivalRate = startRho * serviceRate;
            numberCus = startRho / (1 - startRho);
            responceTime = numberCus / ArrivalRate;
            MeanNumCusInQueue = numberCus - startRho;

            // Print row in the tabluler
            cout << fixed << setprecision(3)
                 << setw(10) << startRho
                 << setw(15) << numberCus
                 << setw(10) << responceTime
                 << endl;
            // Print the rows values to file one
            outputFile << fixed << setprecision(3)
                       << setw(10) << numberCus
                       << setw(10) << startRho
                       << endl;
            // Print the rows values to file two
            outputFile2 << fixed << setprecision(3)
                        << setw(10) << responceTime
                        << setw(10) << startRho
                        << endl;


            // uncomment the following line to display the mean number of customers waiting in queue.
            // cout << "Mean number of customers waiting in queue: " << MeanNumCusInQueue << endl;

            // increment the Rho values ti implement the next values
            startRho += stepValue;

            // Avoid floating-point errors
            startRho = round(startRho * 1000) / 1000.0;
        }

    } else if (stepValue == 0.01) {
        // open the ouputfile
        std::ofstream outputFile("NvsRho_s01.txt");
        if (!outputFile) {
            cerr << "Error: could not open file NvsRho_s01.txt" << endl;
            return;
        }
        std::ofstream outputFile2("RTvsRho_s01.txt");
        if (!outputFile2) {
            cerr << "Error: could not open file RTvsRho_s01.txt" << endl;
            return;
        }
        // Same calculation for the second step value
        while (startRho <= endRho) {
            ArrivalRate = startRho * serviceRate;
            numberCus = startRho / (1 - startRho);
            responceTime = numberCus / ArrivalRate;
            MeanNumCusInQueue = numberCus - startRho;

            // Print row in the table
            cout << fixed << setprecision(3)
                 << setw(10) << startRho
                 << setw(15) << numberCus
                 << setw(10) << responceTime
                 << endl;

            outputFile << fixed << setprecision(3)
                       << setw(10) << numberCus
                       << setw(10) << startRho
                       << endl;

            outputFile2 << fixed << setprecision(3)
                        << setw(10) << responceTime
                        << setw(10) << startRho
                        << endl;
            // uncomment the following line to display the mean number of customers waiting in queue.
            //cout << "Mean number of customers waiting in queue: " << MeanNumCusInQueue << endl;

            startRho += stepValue;
            startRho = round(startRho * 1000) / 1000.0;
        }

    } else if (stepValue == 0.001) {
        std::ofstream outputFile("NvsRho_s001.txt");
        if (!outputFile) {
            cerr << "Error: could not open file NvsRho_s001.txt" << endl;
            return;
        }
        std::ofstream outputFile2("RTvsRho_s001.txt");
        if (!outputFile2) {
            cerr << "Error: could not open file RTvsRho_s001.txt" << endl;
            return;
        }
        // Calculation for the third step value
        while (startRho <= endRho) {
            ArrivalRate = startRho * serviceRate;
            numberCus = startRho / (1 - startRho);
            responceTime = numberCus / ArrivalRate;
            MeanNumCusInQueue = numberCus - startRho;

            // Print row in the table
            cout << fixed << setprecision(3)
                 << setw(10) << startRho
                 << setw(15) << numberCus
                 << setw(10) << responceTime
                 << endl;

            outputFile << fixed << setprecision(3)
                       << setw(10) << numberCus
                       << setw(10) << startRho
                       << endl;

            outputFile2 << fixed << setprecision(3)
                        << setw(10) << responceTime
                        << setw(10) << startRho
                        << endl;

            // uncomment the following line to display the mean number of customers waiting in queue.
            // cout << "Mean number of customers waiting in queue: " << MeanNumCusInQueue << endl;
            

            startRho += stepValue;
            startRho = round(startRho * 1000) / 1000.0;
        }

    } else {
        cout << "Please enter a valid stepValue" << endl;
    } 
}
int main() {
// Variable to check if the user wants to run another calculation 
char runAgain = 'y'; 
    do {
        MM1Calculation();

        // Ask the user if they want to run another calculation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y'); // Continue if the user enters 'y' or 'Y'

    return 0;
}
