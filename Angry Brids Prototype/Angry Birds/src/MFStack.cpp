#include "MFStack.h"
#include <assert.h>

MFStack::MFStack()
{
	this->pHead = nullptr;
	this->count = 0;
}

void MFStack::push(LinkNode* pEnt)
{
	assert(pEnt != nullptr);

	pEnt->pNext = pHead;
	this->pHead = pEnt;
	this->count++;
}

LinkNode* MFStack::Pop()
{
	assert(this->pHead != nullptr);

	LinkNode* ptmp = this->pHead;
	pHead = this->pHead->pNext;
	this->count--;

	return ptmp;
}

MFStack::~MFStack()
{
	while (this->pHead != nullptr)
	{
		LinkNode* ptmp = pHead;
		this->pHead = pHead->pNext;

		delete ptmp;
		this->count--;
	}

	assert(count == 0);
}