#include "PatientFileLoaderAdapter.h"


PatientFileLoaderAdapter::PatientFileLoaderAdapter(const std::string& filename) :
	_filename(filename)
{ }

void PatientFileLoaderAdapter::initialiseConnection()
{
	// file-based; no persistent connection needed
}

void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn)
{
	auto loaded = _fileLoader.loadPatientFile(_filename);
	patientIn.insert(patientIn.end(), loaded.begin(), loaded.end());
}

void PatientFileLoaderAdapter::closeConnection()
{
	// file-based; no persistent connection needed
}
