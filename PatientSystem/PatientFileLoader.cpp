#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            if (line.empty()) continue;

            // format: uid|lastName,firstName|dd-mm-yyyy|diagnosis|BT,BP,HR,RR;...
            std::istringstream lineStream(line);
            std::string uid, nameStr, dateStr, diagnosis, vitalsStr;
            std::getline(lineStream, uid, '|');
            std::getline(lineStream, nameStr, '|');
            std::getline(lineStream, dateStr, '|');
            std::getline(lineStream, diagnosis, '|');
            std::getline(lineStream, vitalsStr, '|');

            std::istringstream nameStream(nameStr);
            std::string lastName, firstName;
            std::getline(nameStream, lastName, ',');
            std::getline(nameStream, firstName, ',');

            std::tm t{};
            std::istringstream dateStream(dateStr);
            dateStream >> std::get_time(&t, "%d-%m-%Y");

            Patient* p = new Patient(firstName, lastName, t);
            p->addDiagnosis(diagnosis);

            if (!vitalsStr.empty()) {
                std::istringstream vitalsStream(vitalsStr);
                std::string record;
                while (std::getline(vitalsStream, record, ';')) {
                    if (record.empty()) continue;
                    std::istringstream vStream(record);
                    std::string btStr, bpStr, hrStr, rrStr;
                    std::getline(vStream, btStr, ',');
                    std::getline(vStream, bpStr, ',');
                    std::getline(vStream, hrStr, ',');
                    std::getline(vStream, rrStr, ',');
                    p->addVitals(new Vitals(std::stof(btStr), std::stoi(bpStr), std::stoi(hrStr), std::stoi(rrStr)));
                }
            }

            patients.push_back(p);
        }
    }

    return patients;
}
