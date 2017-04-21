#pragma once
#ifndef CELL
#define CELL

#include <vector>

using namespace std;

//transmitter definitions
#define LOW_POS		0x01
#define MID_POS		0x02
#define HI_POS		0x03

#define LOW_NEG		0x04
#define MID_NEG		0x05
#define HI_NEG		0x06

struct Neuron
{
	Neuron * handle;

	vector <Neuron **> targets;
	vector <float> weights;

	//charge states
	float restingPotential;
	float charge;
	float decayRate;
	float influxRate;
	float threshold;
	float stabilization;

	//binary states
	unsigned long carryTransmitter;		//Propogating temporary transmitters
	unsigned long fireTransmitter;		//Default fire transmitters
	unsigned long recieveTransmitter;	//recievable transmitters

	Neuron();
	virtual ~Neuron();

	//virtual methods
	virtual void Receive(unsigned long transmitter, float w);
	virtual void Fire();
	virtual void Update();
	
	//required
	void Bind(Neuron ** handle, float weight);
	void Prune(int index);
};


#endif