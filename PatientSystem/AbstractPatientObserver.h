#pragma once

// forward declaration
class Patient;


class AbstractPatientObserver {
public:
	virtual void onAlertLevelChanged(Patient* p) = 0;
	virtual ~AbstractPatientObserver() = default;
};
