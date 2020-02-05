#include "ColorFilter.h"
#include "Game.h"
#include "Demos/ContactAction.h"



ColorFilter::ColorFilter(float x, float y, float rot)
	: GameObject2D(
		GameObjectName::EffectsGroup,
		new GraphicsObject_Sprite(ImageName::TrailPuff, Rect(x, y, 35, 5)),
		GameObject2D::Box)
{
	//AZUL STUFF
	this->currAngle = rot;
	this->SetDrawDebug(true);
	this->SetDrawSprite(false);
	this->SetDebugColor(Color::Type::Green);

	//BOX2D STUFF
	// Body Def
	b2BodyDef ColorFilterDef;
	ColorFilterDef.type = b2_dynamicBody;
	ColorFilterDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	ColorFilterDef.angle = currAngle;
	ColorFilterDef.gravityScale = 0;

	// Body
	b2Body *pColorFilterBody = Game::GetB2World()->CreateBody(&ColorFilterDef);

	// Shape
	b2PolygonShape ColorFilterBox;
	ColorFilterBox.SetAsBox(PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(0, 0),	 // center of box relative to body position
		this->origAngle
	);

	// Fixture
	b2FixtureDef ColorFilterFixtureDef;
	ColorFilterFixtureDef.shape = &ColorFilterBox;
	ColorFilterFixtureDef.userData = this;
	ColorFilterFixtureDef.isSensor = true;

	//ColorFilterFixtureDef.filter.categoryBits = FilterCategory::ColorFilter;
	//ColorFilterFixtureDef.filter.maskBits = FilterCategory::GROUND | FilterCategory::WOODBLOCK | FilterCategory::GLASSBLOCK;

	pColorFilterBody->CreateFixture(&ColorFilterFixtureDef);

	// GameObject points to Body
	SetBody(pColorFilterBody);


}

void ColorFilter::Update(float currentTime)
{
	//frames--;
	if (frames < 1)
	{
		MarkForDelete();
	}
	GameObject2D::Update(currentTime);
}

void ColorFilter::CollideVisit(Shrapnel& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
