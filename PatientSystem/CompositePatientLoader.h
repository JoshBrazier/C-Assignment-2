#pragma once

#include <memory>
#include <vector>

#include "AbstractPatientDatabaseLoader.h"


class CompositePatientLoader : public AbstractPatientDatabaseLoader {
public:
	CompositePatientLoader();

	void addLoader(std::unique_ptr<AbstractPatientDatabaseLoader> loader);

	virtual void initialiseConnection() override;
	virtual void loadPatients(std::vector<Patient*>& patientIn) override;
	virtual void closeConnection() override;

private:
	std::vector<std::unique_ptr<AbstractPatientDatabaseLoader>> _loaders;
};
