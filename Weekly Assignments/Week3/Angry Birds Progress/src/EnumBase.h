#ifndef ENUM_NAME_H
#define ENUM_NAME_H

#ifndef ENUM_BASE
#define ENUM_BASE

struct EnumBase
{
	enum Name
	{
		Stubb // needed for overloading
	};

	bool operator == (EnumBase tmp)
	{
		return (this->value == tmp.value);
	}

	int value;
};

#endif

struct ModelName : public EnumBase
{
	ModelName(ModelName::Name n)
	{
		this->value = n;
	}

	enum Name
	{
		Sprite = 0x60000,
		Circle,
		Box,
		Tri,
		NOT_INITIALIZED
	};
};

#endif