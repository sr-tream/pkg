#include "pkginterface.h"
#include <QProcess>
#include <QDebug>


QString pkgInterface::getCmd()
{
	return cmd;
}

void pkgInterface::execute(QStringList args)
{
	QProcess proc;

	proc.setProgram(cmd);
	proc.setArguments(args);
	proc.setProcessChannelMode(QProcess::ForwardedChannels);
	proc.setInputChannelMode(QProcess::ForwardedInputChannel);
	proc.start();
	proc.waitForFinished(-1);

	if (proc.exitCode() == 255)
		qDebug() << "Package manager" << cmd << "is not installed";
}

QStringList pkgInterface::mergeArgs(QStringList args1, QStringList args2)
{
	for (auto arg : args2)
		args1 << arg;
	return args1;
}
