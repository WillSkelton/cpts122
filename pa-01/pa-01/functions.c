#include "functions.h"

void NewFitbitData(FitbitData *f) {

	FitbitData FBD;
	for (int i = 0; i < PATIENTNAMELENGTH; ++i) FBD.patient[i] = '\0';
	for (int i = 0; i < PATIENTMINUTES; ++i) FBD.minute[i] = '\0';


	FBD.calories = 0.0;
	FBD.distance = 0.0;
	FBD.floors = 0;
	FBD.heartRate = 0;
	FBD.steps = 0;
	FBD.sleepLevel = 0;
}