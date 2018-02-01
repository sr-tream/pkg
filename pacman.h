#ifndef PACMAN_H
#define PACMAN_H

#include "pkginterface.h"

class pacman : public pkgInterface
{
public:
	pacman();

	virtual void install(QStringList pkg);
	virtual void remove(QStringList pkg);
	virtual void search(QStringList pkg);
	virtual void info(QString pkg);
	virtual void clean();
	virtual void update();
};

#endif // PACMAN_H
