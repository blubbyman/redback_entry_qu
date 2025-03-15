#include <iostream>
#include <fstream>
#include <string>

// Question 3: This is an extension task that requires you to decode sensor data from a CAN log file.
// CAN (Controller Area Network) is a communication standard used in automotive applications (including Redback cars)
// to allow communication between sensors and controllers.
//
// Your Task: Using the definition in the Sensors.dbc file, extract the "WheelSpeedRR" values
// from the candump.log file. Parse these values correctly and store them in an output.txt file with the following format:
// (<UNIX_TIME>): <DECODED_VALUE>
// eg:
// (1705638753.913408): 1234.5
// (1705638754.915609): 6789.0
// ...
// The above values are not real numbers; they are only there to show the expected data output format.
// You do not need to use any external libraries. Use the resources below to understand how to extract sensor data.
// Hint: Think about manual bit masking and shifting, data types required,
// what formats are used to represent values, etc.
// Resources:
// https://www.csselectronics.com/pages/can-bus-simple-intro-tutorial
// https://www.csselectronics.com/pages/can-dbc-file-database-intro


// steps to take to solve this problem

int main() {
    // scan in the candump.log file and initialise text output file
    ifstream inputFile("candump.log");
    ofstream outputFile("output.txt");

    // reading the file line by line
    string line, timestamp, canID, payload;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        iss >> timestamp >> canID >> payload;

        // check if the canID is the one we are interested in
        if (canID != "0x705") continue

        int raw_value;
        double decoded_value;

        if (canID == "0x705") {
            payload = line.substr(10, 16);
            raw_value = stoi(payload, nullptr, 16);
            decoded_value = raw_value * 0.1;
        }

        outputFile << "(" << timestamp << "): " << decoded_value << endl;
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}
