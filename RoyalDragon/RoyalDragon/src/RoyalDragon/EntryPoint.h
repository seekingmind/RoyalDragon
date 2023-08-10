#pragma once

#ifdef RD_PLATEFORM_WINDOWS

extern RoyalDragon::Application* RoyalDragon::CreateApplication();

int main(int argc, char** argv)
{
	printf("RoyalDragon Engine\n");
	RoyalDragon::Application* app = RoyalDragon::CreateApplication();
	app->Run();
	delete app;
}

#else
#error "RoyalDragon only support Windows!"
#endif // RD_PLATEFORM_WINDOWS

