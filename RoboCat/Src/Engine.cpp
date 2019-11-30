#include <RoboCatPCH.h>
#include <time.h>

std::unique_ptr<Engine>	Engine::sInstance;


Engine::Engine() :
mShouldKeepRunning( true )
{
	SocketUtil::StaticInit();

	srand( static_cast< uint32_t >( time( nullptr ) ) );
	
	GameObjectRegistry::StaticInit();

	World::StaticInit();

	ScoreBoardManager::StaticInit();

}

Engine::~Engine()
{
	SocketUtil::CleanUp();

}


/*int Engine::Run()
{
	return DoRunLoop();
}*/

void Engine::HandleEvent(Hazel::Event& e)
{
}
/*
int Engine::DoRunLoop()
{
	// Main message loop
	bool quit = false;
	//memset( &event, 0, sizeof( SDL_Event ) );

	while( !quit && mShouldKeepRunning )
	{
	}

	return 1;
}*/

void Engine::DoFrame(Hazel::Timestep ts)
{
	World::sInstance->Update();
}

	
