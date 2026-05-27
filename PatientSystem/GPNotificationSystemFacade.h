#pragma once

#include "AbstractPatientObserver.h"
#include "Patient.h"


class GPNotificationSystemFacade : public AbstractPatientObserver {
public:
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();

	virtual void onAlertLevelChanged(Patient* p) override;
	void sendGPNotificationForPatient(Patient* p);
};

