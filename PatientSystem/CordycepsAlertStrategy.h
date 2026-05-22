#pragma once

#include "AbstractAlertStrategy.h"


class CordycepsAlertStrategy : public AbstractAlertStrategy {
public:
	virtual AlertLevel calculate(const Patient& patient, const Vitals& vitals) const override;
};
