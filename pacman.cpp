#include "pacman.h"

pacman::pacman()
{
	cmd = "pacman";
}

void pacman::install(QStringList pkg)
{
	execute(mergeArgs(QStringList("-S"), pkg));
}

void pacman::remove(QStringList pkg)
{
	execute(mergeArgs(QStringList("-R"), pkg));
}

void pacman::search(QStringList pkg)
{
	execute(mergeArgs(QStringList("-Ss"), pkg));
}

void pacman::info(QString pkg)
{
	execute(QStringList() << "-Qi" << pkg);
}

void pacman::clean()
{
	execute(QStringList() << "-Sc");
}

void pacman::update()
{
	execute(QStringList() << "-Syu");
}
