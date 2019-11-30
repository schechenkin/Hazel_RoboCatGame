#include "Hazel.h"

class SpriteComponent
{
public:

	SpriteComponent( GameObject* inGameObject );
	~SpriteComponent();

	virtual void		Draw();

			void		SetTexture(Hazel::Ref<Hazel::Texture2D> inTexture )			{ mTexture = inTexture; }

			Vector3		GetOrigin()					const			{ return mOrigin; }
			void		SetOrigin( const Vector3& inOrigin )		{ mOrigin = inOrigin; }


private:

	Vector3											mOrigin;

	Hazel::Ref<Hazel::Texture2D>					mTexture;

	//don't want circular reference...
	GameObject*										mGameObject;
};

typedef shared_ptr< SpriteComponent >	SpriteComponentPtr;