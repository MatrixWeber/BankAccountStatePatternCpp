#pragma once
#include "ICallbackable.h"

class Bank : public ICallbackable
{
public:
	~Bank() override = default;

	bool wasCallbackInvoked() 
	{
		auto read = callbackInvoked;
		if(callbackInvoked)
			callbackInvoked = false;
		return read;
	}

private:
	bool callbackInvoked = false;

	// Geerbt über ICallbackable
	virtual void callback() override;

};

