#include <RoboCatServerPCH.h>
#include "ServerLayer.h"

ServerLayer::ServerLayer(uint16_t port)
{
	Server::StaticInit(port);
}

void ServerLayer::OnAttach()
{
	static_cast<Server*> (Engine::sInstance.get())->SetupWorld();
}

void ServerLayer::OnDetach()
{
	SocketUtil::CleanUp();
}

void ServerLayer::OnUpdate(Hazel::Timestep ts)
{
	Timing::sInstance.Update();
	static_cast<Server*> (Engine::sInstance.get())->DoFrame(ts);
}

void ServerLayer::OnImGuiRender()
{
}

void ServerLayer::OnEvent(Hazel::Event& e)
{
	static_cast<Server*> (Engine::sInstance.get())->HandleEvent(e);
}
