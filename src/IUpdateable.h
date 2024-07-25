#ifndef IUPDATEABLE_H
#define IUPDATEABLE_H

class IUpdateable {

public:
	virtual ~IUpdateable() = default;
	virtual void update() = 0;
};

#endif