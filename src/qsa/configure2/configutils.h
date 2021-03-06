#ifndef CONFIGUTILS_H
#define CONFIGUTILS_H

#include <QString>
#include <QStringList>
#include <QDir>

extern QString *qtDir;
extern int processes;
extern int errors;
extern int warnings;
extern bool autoShutdown;


void message( const QString &msg );
QStringList messages();

void setQMake( const QString &str );
void runQMake( const QStringList &configs, const QStringList &antiConfigs, const QString &prefix );
void mkDir( const QString &dir );
bool writeQSConfig( bool buildIde );

#endif
