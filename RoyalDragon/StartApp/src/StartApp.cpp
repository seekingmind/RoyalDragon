#include "RoyalDragon.h"

class StartApp : public RoyalDragon::Application
{
public:
	StartApp()
	{
		RD_TRACE("StartApp Hello!");
	}

	~StartApp()
	{

	}
};

RoyalDragon::Application* RoyalDragon::CreateApplication()
{
	return new StartApp();
}