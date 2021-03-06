// ContactAction

#ifndef _ContactAction
#define _ContactAction

struct b2ContactImpulse;
class b2Contact;
class BlockWoodLong;
class RedBird;
class YellowBird;

class ContactAction
{
public:
	static void ContactPair(RedBird& bird, BlockWoodLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(YellowBird& bird, BlockWoodLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

private:
	static void ShowBang(b2Contact* pContact);
	static void NormalImpulseDamage(BlockWoodLong& B, const b2ContactImpulse* pImpulse);
};

#endif _ContactAction
