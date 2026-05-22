#pragma once

#include "AbstractAlertStrategy.h"


class KepralsSyndromeAlertStrategy : public AbstractAlertStrategy {
public:
	virtual AlertLevel calculate(const Patient& patient, const Vitals& vitals) const override;
};
