#pragma once
/*
	statistics.h
	Declaration file for class Statistics.
*/

#ifndef STATISTICS_H
#define STATISTICS_H

#include "ksuPatient.h"
#include <vector>

/**
	@author Matthew Oster moster@kent.edu
*/

class Statistics {
public:
	Statistics();
	Statistics(const Statistics& src) : patientCount(src.patientCount), fluCount(src.fluCount), coronaCount(src.coronaCount),
		counselingCount(src.counselingCount), fluPercent(src.fluPercent), coronaPercent(src.coronaPercent), counselingPercent(src.counselingPercent) {}

	void setPatientCount(int num) { patientCount = num; }
	/**
	Increments fluCount.
	*/
	void incrementFluCount() { fluCount++; if (patientCount > 0) calculatePercentages();}
	/**
	Increments coronaCount.
	*/
	void incrementCoronaCount() { coronaCount++; if (patientCount > 0) calculatePercentages();}
	/**
	Increments counselingCount.
	*/
	void incrementCounselingCount() { counselingCount++; if (patientCount > 0) calculatePercentages();}

	/**
	Calculates the percentages of patients who exhibit flu-like symptoms, the percentage who have contracted Coronavirus,
	and the percentage who have sought counseling for Coronavirus-related reasons.
	*/
	void calculatePercentages();

	/**
	Simple accessor methods.
	*/
	int getPatientCount() { return patientCount; }
	int getFluCount() { return fluCount; }
	int getCoronaCount() { return coronaCount; }
	int getCounselingCount() { return counselingCount; }
	double getFluPercent() { return fluPercent; }
	double getCoronaPercent() { return coronaPercent; }
	double getCounselingPercent() { return counselingPercent; }

private:

	int patientCount; /*!< Number of unique patients registered in the system. */
	int fluCount; /*!< Number of patients exhibiting flu-like symptoms. */
	int coronaCount; /*!< Number of patients who have contracted Coronavirus. */
	int counselingCount; /*!< Number of patients who have sought counseling for Coronavirus related reasons. */
	double fluPercent; /*!< Percentage of patients exhibiting flu-like symptoms. */
	double coronaPercent; /*!< Percentage of patients who've contracted Coronavirus.*/
	double counselingPercent; /*!< Percentage of patients who've sought counseling for Coronavirus-related reasons. */

};

#endif