#include <RoboCatClientPCH.h>
#include "ClientLayer.h"
#include <imgui/imgui.h>

ClientLayer::ClientLayer(string& destination, string& name)
{
	Client::StaticInit(destination, name);
}

void ClientLayer::OnAttach()
{
	
}

void ClientLayer::OnDetach()
{
	SocketUtil::CleanUp();
}

void ClientLayer::OnUpdate(Hazel::Timestep ts)
{
	Timing::sInstance.Update();

	static_cast<Client*> (Engine::sInstance.get())->DoFrame(ts);

}

void ClientLayer::OnImGuiRender()
{
	ImGui::Begin("ScoreBoard");

	//ImGui::Text("Health %d", HUD::sInstance->GetHealth());

	ImGui::Columns(2, "mycolumns2", false);

	const vector< ScoreBoardManager::Entry >& entries = ScoreBoardManager::sInstance->GetEntries();

	for (const auto& entry : entries)
	{
		ImGui::Text("%s", entry.GetPlayerName().c_str());
		ImGui::NextColumn();
		ImGui::Text("%d", entry.GetScore());
		ImGui::NextColumn();
	}

	ImGui::End();
}

void ClientLayer::OnEvent(Hazel::Event& e)
{
	static_cast<Client*> (Engine::sInstance.get())->HandleEvent(e);
}
