#pragma once


class ICallbackable
{
public:
	virtual ~ICallbackable() = default;
	virtual void callback() = 0;

};
