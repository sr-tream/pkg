#ifndef DNF_H
#define DNF_H

#include "pkginterface.h"

class dnf : public pkgInterface
{
public:
	dnf();

	virtual void install(QStringList pkg);
	virtual void remove(QStringList pkg);
	virtual void search(QStringList pkg);
	virtual void info(QString pkg);
	virtual void clean();
	virtual void update();
};

#endif // DNF_H
