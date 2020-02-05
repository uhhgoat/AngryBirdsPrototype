#ifndef _MFStack
#define _MFStack


class GameObject2D;

// Storage for ABEntities to be recycled
class LinkNode
{
public:
	LinkNode()
		:pEnt(nullptr), pNext(nullptr)
	{ }

	LinkNode* pNext;
	GameObject2D* pEnt;
};

class MFStack
{
private:
	LinkNode * pHead;
	int count;

public:
	MFStack();
	virtual ~MFStack();
	MFStack(const MFStack&) = delete;
	MFStack& operator=(const MFStack&) = delete;

	int Size() const { return count; };
	bool IsEmpty() const { return count == 0; };

	void push(LinkNode* pEnt);
	LinkNode* Pop();


};


#endif _MFStack
