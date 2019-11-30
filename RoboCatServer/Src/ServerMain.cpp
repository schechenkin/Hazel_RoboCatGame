
#include <RoboCatServerPCH.h>

#include <Hazel.h>

#include "ServerLayer.h"

class ServerApp : public Hazel::Application
{
public:
	ServerApp(uint16_t port)
	{
		PushLayer(new ServerLayer(port));
	}

	~ServerApp()
	{
	}
};

int main(int argc, char** argv)
{
	Hazel::Log::Init();

	HZ_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Startup.json");
	auto app = new ServerApp(atoi(argv[1]));
	HZ_PROFILE_END_SESSION();

	HZ_PROFILE_BEGIN_SESSION("Runtime", "HazelProfile-Runtime.json");
	app->Run();
	HZ_PROFILE_END_SESSION();

	HZ_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Shutdown.json");
	delete app;
	HZ_PROFILE_END_SESSION();
}
