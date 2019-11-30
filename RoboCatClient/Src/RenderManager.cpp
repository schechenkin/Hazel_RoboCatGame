#include <RoboCatClientPCH.h>

std::unique_ptr< RenderManager >	RenderManager::sInstance;

RenderManager::RenderManager()
{
}


void RenderManager::StaticInit()
{
	sInstance.reset(new RenderManager());
}


void RenderManager::AddComponent(SpriteComponent* inComponent)
{
	mComponents.push_back(inComponent);
}

void RenderManager::RemoveComponent(SpriteComponent* inComponent)
{
	int index = GetComponentIndex(inComponent);

	if (index != -1)
	{
		int lastIndex = mComponents.size() - 1;
		if (index != lastIndex)
		{
			mComponents[index] = mComponents[lastIndex];
		}
		mComponents.pop_back();
	}
}

int RenderManager::GetComponentIndex(SpriteComponent* inComponent) const
{
	for (int i = 0, c = mComponents.size(); i < c; ++i)
	{
		if (mComponents[i] == inComponent)
		{
			return i;
		}
	}

	return -1;
}


//this part that renders the world is really a camera-
//in a more detailed engine, we'd have a list of cameras, and then render manager would
//render the cameras in order
void RenderManager::RenderComponents()
{
	for (auto cIt = mComponents.begin(), end = mComponents.end(); cIt != end; ++cIt)
	{
		(*cIt)->Draw();
	}
}

void RenderManager::Render(const Hazel::OrthographicCamera& camera)
{
	Hazel::RenderCommand::SetClearColor({ 100.0 / 256.0, 149.0 / 256.0, 237.0 / 256.0, 1 });
	Hazel::RenderCommand::Clear();

	Hazel::Renderer2D::BeginScene(camera);

	RenderManager::sInstance->RenderComponents();
	//HUD::sInstance->Render();

	Hazel::Renderer2D::EndScene();
	
	RenderManager::sInstance->RenderComponents();
}