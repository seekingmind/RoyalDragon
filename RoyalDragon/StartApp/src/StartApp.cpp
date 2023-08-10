#include "RoyalDragon.h"

class StartApp : public RoyalDragon::Application
{
public:
	StartApp()
	{

	}

	~StartApp()
	{

	}
};

RoyalDragon::Application* RoyalDragon::CreateApplication()
{
	return new StartApp();
}