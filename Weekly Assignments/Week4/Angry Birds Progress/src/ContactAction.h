#pragma once
#include "Background.h"
class WoodBlockLong;
class WoodBlockMed;
class WoodBlockShort;
class GlassBlockLong;
class GlassBlockMed;
class GlassBlockShort;
class BlackBird;
class BlueBird;
class BigRedBird;
class GreenBird;
class RedBird;
class WhiteBird;
class YellowBird;
class b2Contact;
struct b2ContactImpulse;

class ContactAction
{
public:
	//Holy Cow so many pairs
	//RedBird
	static void ContactPair(RedBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//BigRed bird
	static void ContactPair(BigRedBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//BlackBird
	static void ContactPair(BlackBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//BlueBird
	static void ContactPair(BlueBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//GreenBird
	static void ContactPair(GreenBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//WhiteBird
	static void ContactPair(WhiteBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//YellowBird
	static void ContactPair(YellowBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	//Background
	static void ContactPair(Background& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	
	static void ContactPair(Background& bg, BigRedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, BlackBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, BlueBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GreenBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, RedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, WhiteBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, YellowBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	//Blast
	static void ContactPair(Blast& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);


private:
	static void ShowBang(b2Contact* pContact);

};