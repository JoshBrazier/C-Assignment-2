#pragma once

#include "AbstractPatientObserver.h"
#include "Patient.h"


class HospitalAlertSystemFacade : public AbstractPatientObserver
{
public:
	HospitalAlertSystemFacade();
	virtual ~HospitalAlertSystemFacade();

	virtual void onAlertLevelChanged(Patient* p) override;
	void sendAlertForPatient(Patient* p);

};

