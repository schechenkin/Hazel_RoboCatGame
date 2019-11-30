
#include <RoboCatClientPCH.h>
#include "Hazel/Core/Core.h"
#include "ClientLayer.h"

class ClientApp : public Hazel::Application
{
public:
	ClientApp(char* destination, char* name)
	{
		PushLayer(new ClientLayer(string(destination), string(name)));
	}

	~ClientApp()
	{
	}
};


int main(int argc, char** argv)
{
	Hazel::Log::Init();

	HZ_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Startup.json");
	auto app = new ClientApp(argv[1], argv[2]);
	HZ_PROFILE_END_SESSION();

	HZ_PROFILE_BEGIN_SESSION("Runtime", "HazelProfile-Runtime.json");
	app->Run();
	HZ_PROFILE_END_SESSION();

	HZ_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Shutdown.json");
	delete app;
	HZ_PROFILE_END_SESSION();
}


