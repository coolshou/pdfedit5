/*
 * PDFedit - free program for PDF document manipulation.
 * Copyright (C) 2006-2009  PDFedit team: Michal Hocko,
 *                                        Jozef Misutka,
 *                                        Martin Petricek
 *                   Former team members: Miroslav Jahoda
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (in doc/LICENSE.GPL); if not, write to the 
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 * MA  02111-1307  USA
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit
 */
#ifndef __TREEITEMOBSERVER_H__
#define __TREEITEMOBSERVER_H__

#include "treeitemgenericobserver.h"
#include <kernel/iproperty.h>
#include <utils/observer.h>

namespace gui {

/**
 This class provides observer monitoring IProperty item.<br>
 The observer will reload associated tree item when the observed item changes.
 \brief Observer for TreeItem
*/
class TreeItemObserver : public TreeItemGenericObserver<pdfobjects::IProperty>  {
public:
 /**
  Constructor
  @param _parent Object to be reloaded on any change to monitored item
 */
 TreeItemObserver(TreeItemAbstract* _parent) : TreeItemGenericObserver<pdfobjects::IProperty> (_parent) {
  //No extra initialization
 };
 /** Destructor */
 virtual ~TreeItemObserver() throw() {
  //Empty for now
 }
};

} // namespace gui

#endif
