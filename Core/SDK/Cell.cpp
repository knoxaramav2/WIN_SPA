#include "Cell.h"

Neuron::Neuron()
{
	handle = this;

	//initialize default values
	//TODO implement variable defaults/base values
	restingPotential = -70.0f;
	charge = restingPotential;
	decayRate = .95f;
	influxRate = 0.0f;
	threshold = -55.0f;
	stabilization = .5f;
}

Neuron::~Neuron()
{
	handle = NULL;
}


void Neuron::Receive(unsigned long transmitter, float w)
{
	for (int i = 0; i < 32; ++i)
	{
		switch(i)
		{
		case 0: if (transmitter & (1 << i)); break;
		}
	}
}

void Neuron::Fire()
{
	unsigned long payload = fireTransmitter | carryTransmitter;

	for (size_t i=0; i < targets.size(); ++i)
	{
		//prune dead connections
		if (*targets[i] == NULL)
		{
			Prune(i);
			--i;
			continue;
		}

		(**targets[i]).Receive(payload, weights[i]);

		carryTransmitter = 0;
	}
}

void Neuron::Update()
{
	charge += (influxRate);
	influxRate *= decayRate;

	if (charge >= threshold)
	{
		Fire();
		//drop influx rate
	}

}

void Neuron::Bind(Neuron ** handle, float weight=1)
{
	targets.push_back(handle);
	weights.push_back(weight);
}

void Neuron::Prune(int index)
{
	targets.erase(targets.begin() + index);
	weights.erase(weights.begin() + index);
}
