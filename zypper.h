#ifndef ZYPPER_H
#define ZYPPER_H

#include "pkginterface.h"

class zypper : public pkgInterface
{
public:
	zypper();

	virtual void install(QStringList pkg);
	virtual void remove(QStringList pkg);
	virtual void search(QStringList pkg);
	virtual void info(QString pkg);
	virtual void clean();
	virtual void update();
};

#endif // ZYPPER_H
