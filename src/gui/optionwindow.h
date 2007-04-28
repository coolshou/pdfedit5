/*                                                                              
 * PDFedit - free program for PDF document manipulation.                        
 * Copyright (C) 2006, 2007  PDFedit team:      Michal Hocko, 
 *                                              Miroslav Jahoda,       
 *                                              Jozef Misutka, 
 *                                              Martin Petricek                                             
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit                                                                      
 */ 
#ifndef __OPTIONWINDOW_H__
#define __OPTIONWINDOW_H__

#include "qtcompat.h"
#include <qwidget.h>
#include QDICT
#include <qmap.h>
class QLabel;
class QTabWidget;
class QFrame;
class QGridLayout;

namespace gui {

class Menu;
class Option;

/**
 Widget for editing program options<br>
 Options are arranged to tabs and it is ensured, that only one dialog at once is active
 (via Private constructor and static method to invoke the dialog, which will focus on
 existing dialog if it exists, instead of creating second one) 
 \brief Window for showing/editing program settings
*/
class OptionWindow : public QWidget {
 Q_OBJECT
public slots:
 void apply();
 void ok();
public:
 static void optionsDialog(Menu *msystem,const QStringList &units,const QStringList &units_id);
 ~OptionWindow();
protected:
 void closeEvent(QCloseEvent *e);
private:
 OptionWindow(Menu *msystem,const QStringList &units,const QStringList &units_id,QWidget *parent=0, const char *name=0);
 void init();
 QWidget* addTab(const QString name,bool makeSegments=false);
 void initGridFrame(QWidget *grid);
 void addOption(QWidget *otab,const QString &caption,Option *opt);
 void addOption(QWidget *otab,const QString &caption,const QString &key,const QString &defValue=QString::null);
 void addOptionFile(QWidget *otab,const QString &caption,const QString &key,const QString &defValue=QString::null);
 void addOptionFont(QWidget *otab,const QString &caption,const QString &key,const QString &defValue=QString::null);
 void addOptionCombo(QWidget *otab,const QString &caption,const QString &key,const QStringList &values);
 void addOptionCombo(QWidget *otab,const QString &caption,const QString &key,const QStringList &values,const QStringList &descriptions);
 void addOptionInt(QWidget *otab,const QString &caption,const QString &key,int defValue=0);
 void addOptionBool(QWidget *otab,const QString &caption,const QString &key,bool defValue=false);
 void addOptionFloat(QWidget *otab,const QString &caption,const QString &key);
 void addWidget(QWidget *otab,QWidget *elem);
 void addText(QWidget *otab,const QString &text);
 QWidget* addBreak(QWidget *otab);
 void finishTab(QWidget *otab);
private:
 /** List of option names */
 QStringList *list;
 /** Dictionary with option items */
 Q_Dict<Option> *items;
 /** Dictionary with option labels */
 Q_Dict<QLabel> *labels;
 /** Main tab widget */ 
 QTabWidget *tab;
 /** Grid layout for the tab */
 QMap<QWidget*,QGridLayout*> gridl;
 /** Master Grid for the tab */
 QMap<QWidget*,QFrame*> masterGrid;
 /** Number of objects in the tab */
 QMap<QWidget*,int> nObjects;
 /** Menu system (for toolbar list ... ) */
 Menu *menuSystem;
 /** Available length units */
 QStringList l_units;
 /** Available length units - identifiers */
 QStringList l_units_id;
};

void applyLookAndFeel(bool notify=false);
void applyStyle();

} // namespace gui

#endif
