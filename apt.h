#ifndef APT_H
#define APT_H

#include "pkginterface.h"

class apt : public pkgInterface
{
public:
	apt();

	virtual void install(QStringList pkg);
	virtual void remove(QStringList pkg);
	virtual void search(QStringList pkg);
	virtual void info(QString pkg);
	virtual void clean();
	virtual void update();
};

#endif // APT_H
