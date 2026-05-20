#include "CompositePatientLoader.h"

#include "PatientDatabaseLoader.h"
#include "PatientFileLoaderAdapter.h"


CompositePatientLoader::CompositePatientLoader()
{
	_loaders.push_back(std::make_unique<PatientDatabaseLoader>());
	_loaders.push_back(std::make_unique<PatientFileLoaderAdapter>("patients.txt"));
}

void CompositePatientLoader::addLoader(std::unique_ptr<AbstractPatientDatabaseLoader> loader)
{
	_loaders.push_back(std::move(loader));
}

void CompositePatientLoader::initialiseConnection()
{
	for (auto& loader : _loaders)
		loader->initialiseConnection();
}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientIn)
{
	for (auto& loader : _loaders)
		loader->loadPatients(patientIn);
}

void CompositePatientLoader::closeConnection()
{
	for (auto& loader : _loaders)
		loader->closeConnection();
}
