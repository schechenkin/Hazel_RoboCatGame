#include <RoboCatClientPCH.h>

SpriteComponent::SpriteComponent( GameObject *inGameObject ) :
	mGameObject( inGameObject )
{
	//hardcoded at the moment...
	float textureWidth = 128.f, textureHeight = 128.f;
	//origin should be half texture size, but we're not loading the actual size at the moment
	mOrigin = Vector3( textureWidth * 0.5f, textureHeight * 0.5f, 0.f );

	//and add yourself to the rendermanager...
	RenderManager::sInstance->AddComponent( this );
}

SpriteComponent::~SpriteComponent()
{
	//don't render me, I'm dead!
	RenderManager::sInstance->RemoveComponent( this );
}


void SpriteComponent::Draw()
{
	Vector3 objLocation = mGameObject->GetLocation();
	float objScale = mGameObject->GetScale();
	Vector3 color = mGameObject->GetColor();
	auto rotation = mGameObject->GetRotation();


	
	if( mTexture )
	{		
		Hazel::Renderer2D::DrawQuad({ -objLocation.mX, -objLocation.mY, 0.0 }, { objScale, objScale }, mTexture, -rotation);
	}
}