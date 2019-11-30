
#include <RoboCatClientPCH.h>

bool Client::StaticInit(string& destination, string& name)
{
	// Create the Client pointer first because it initializes SDL
	Client* client = new Client(destination, name);

	TextureManager::StaticInit();
	RenderManager::StaticInit();
	InputManager::StaticInit();

	HUD::StaticInit();

	sInstance.reset( client );

	return true;
}

Client::Client(string& destination, string& name)
	: m_CameraController(1280.0f / 720.0f)
{
	GameObjectRegistry::sInstance->RegisterCreationFunction( 'RCAT', RoboCatClient::StaticCreate );
	GameObjectRegistry::sInstance->RegisterCreationFunction( 'MOUS', MouseClient::StaticCreate );
	GameObjectRegistry::sInstance->RegisterCreationFunction( 'YARN', YarnClient::StaticCreate );

	SocketAddressPtr serverAddress = SocketAddressFactory::CreateIPv4FromString( destination );

	NetworkManagerClient::StaticInit( *serverAddress, name );

	//NetworkManagerClient::sInstance->SetDropPacketChance( 0.6f );
	//NetworkManagerClient::sInstance->SetSimulatedLatency( 0.25f );
	//NetworkManagerClient::sInstance->SetSimulatedLatency( 0.5f );
	//NetworkManagerClient::sInstance->SetSimulatedLatency( 0.1f );
}



void Client::DoFrame(Hazel::Timestep ts)
{
	InputManager::sInstance->Update();

	Engine::DoFrame(ts);

	NetworkManagerClient::sInstance->ProcessIncomingPackets();

	RenderManager::sInstance->Render(m_CameraController.GetCamera());

	NetworkManagerClient::sInstance->SendOutgoingPackets();
}

void Client::HandleEvent(Hazel::Event& e)
{
	Hazel::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Hazel::KeyPressedEvent>(HZ_BIND_EVENT_FN(Client::OnKeyPressed));
	dispatcher.Dispatch<Hazel::KeyReleasedEvent>(HZ_BIND_EVENT_FN(Client::OnKeyReleased));
}

bool Client::OnKeyPressed(Hazel::KeyPressedEvent& e)
{
	InputManager::sInstance->HandleInput(EIA_Pressed, e.GetKeyCode());
	return false;
}

bool Client::OnKeyReleased(Hazel::KeyReleasedEvent& e)
{
	InputManager::sInstance->HandleInput(EIA_Released, e.GetKeyCode());
	return false;
}

