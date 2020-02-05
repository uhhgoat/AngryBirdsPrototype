#pragma once
#include "Background.h"
class WoodBlockLong;
class WoodBlockMed;
class WoodBlockShort;
class WoodBlockTiny;
class WoodBlockMedThick;
class WoodBlockSquare;
class GlassBlockLong;
class GlassBlockMed;
class GlassBlockShort;
class GlassBlockMedThick;
class GlassBlockTinySquare;
class StoneBlockLong;
class StoneBlockMed;
class StoneBlockShort;
class StoneBlockMedThick;
class BlackBird;
class BlueBird;
class BigRedBird;
class GreenBird;
class RedBird;
class WhiteBird;
class YellowBird;
class b2Contact;
class Egg;
struct b2ContactImpulse;

class ContactAction
{
public:
	//Holy Cow so many pairs
	//RedBird
	static void ContactPair(RedBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RedBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//BigRed bird
	static void ContactPair(BigRedBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BigRedBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//BlackBird
	static void ContactPair(BlackBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlackBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//BlueBird
	static void ContactPair(BlueBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(BlueBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//GreenBird
	static void ContactPair(GreenBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(GreenBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//WhiteBird
	static void ContactPair(WhiteBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(WhiteBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	//YellowBird
	static void ContactPair(YellowBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	//Background
	static void ContactPair(Background& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	
	static void ContactPair(Background& bg, BigRedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, BlackBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, BlueBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, GreenBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, RedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, WhiteBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Background& bg, YellowBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	//Blast
	static void ContactPair(Blast& bl, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, Background& bg, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Blast& bl, Platform& bg, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	//Egg
	static void ContactPair(Egg& egg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, Background& bg, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Egg& egg, Platform& bg, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	//Platform
	static void ContactPair(Platform& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(Platform& bg, BigRedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, BlackBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, BlueBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, GreenBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, RedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, WhiteBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Platform& bg, YellowBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	//RegularPig
	static void ContactPair(RegularPig& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(RegularPig& bg, BigRedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, BlackBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, BlueBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, GreenBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, RedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, WhiteBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, YellowBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, Blast& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(RegularPig& bg, Egg& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	//HelmetPig
	static void ContactPair(HelmetPig& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(HelmetPig& bg, BigRedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, BlackBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, BlueBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, GreenBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, RedBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, WhiteBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, YellowBird& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, Blast& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(HelmetPig& bg, Egg& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

private:
	static void ShowBang(b2Contact* pContact);

};