#pragma once

#include "PatientAlertLevels.h"

// forward declarations
class Patient;
class Vitals;


class AbstractAlertStrategy {
public:
	virtual AlertLevel calculate(const Patient& patient, const Vitals& vitals) const = 0;
	virtual ~AbstractAlertStrategy() = default;
};
