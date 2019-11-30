#include <RoboCatClientPCH.h>

MouseClient::MouseClient()
{
	mSpriteComponent.reset( new SpriteComponent( this ) );
	mSpriteComponent->SetTexture( Hazel::Texture2D::Create("assets/textures/mouse.png"));
}