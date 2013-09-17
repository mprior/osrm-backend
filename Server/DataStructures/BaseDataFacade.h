/*
    open source routing machine
    Copyright (C) Dennis Luxen, others 2010

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU AFFERO General Public License as published by
the Free Software Foundation; either version 3 of the License, or
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
or see http://www.gnu.org/licenses/agpl.txt.
 */

#ifndef QUERY_DATA_FACADE_H
#define QUERY_DATA_FACADE_H

//Exposes all data access interfaces to the algorithms via base class ptr

#include "../../DataStructures/Coordinate.h"
#include "../../DataStructures/PhantomNodes.h"
#include "../../DataStructures/TurnInstructions.h"
#include "../../typedefs.h"

#include <string>

class QueryDataFacade {
public:
    QueryDataFacade() { }
    virtual ~QueryDataFacade() { }

    //search graph access
    //TODO

    //node and edge information access
    virtual FixedPointCoordinate GetCoordinateOfNode(
        const unsigned id
    ) const = 0;

    virtual TurnInstruction GetTurnInstructionForEdgeID(
        const unsigned id
    ) const  = 0;

    virtual NodeID GetNumberOfNodes( ) const  = 0;

    virtual bool LocateClosestEndPointForCoordinate(
        const FixedPointCoordinate& input_coordinate,
        FixedPointCoordinate& result,
        const unsigned zoom_level = 18
    ) const  = 0;

    virtual bool FindPhantomNodeForCoordinate(
        const FixedPointCoordinate & input_coordinate,
        PhantomNode & resulting_phantom_node,
        const unsigned zoom_level
    ) const  = 0;

    virtual unsigned GetCheckSum() const  = 0;

    virtual unsigned GetNameIndexFromEdgeID(const unsigned id) const  = 0;
    virtual void GetName(
        const unsigned name_id,
        std::string & result
    ) const = 0;

};


#endif // QUERY_DATA_FACADE_H
