/* 
 * File:   IMultiGraph.hpp
 *
 * Author: ABSEHER Michael (abseher@dbai.tuwien.ac.at)
 * 
 * Copyright 2015-2016, Michael Abseher
 *    E-Mail: <abseher@dbai.tuwien.ac.at>
 * 
 * This file is part of htd.
 * 
 * htd is free software: you can redistribute it and/or modify it under 
 * the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * htd is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public 
 * License for more details.

 * You should have received a copy of the GNU General Public License
 * along with htd.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HTD_HTD_IMULTIGRAPH_HPP
#define	HTD_HTD_IMULTIGRAPH_HPP

#include <htd/IMultiHypergraph.hpp>

#include <cstdlib>

namespace htd
{
    class IMultiGraph : public virtual htd::IMultiHypergraph
    {
        public:
            virtual ~IMultiGraph() = 0;

            virtual htd::ConstCollection<htd::edge_t> edges(void) const = 0;

            virtual const htd::edge_t & edgeAtPosition(htd::index_t index) const = 0;

            virtual htd::ConstCollection<htd::edge_t> edges(htd::vertex_t vertex) const = 0;

            virtual const htd::edge_t & edgeAtPosition(htd::index_t index, htd::vertex_t vertex) const = 0;

            virtual IMultiGraph * clone(void) const = 0;
    };

    inline htd::IMultiGraph::~IMultiGraph() { }
}

#endif /* HTD_HTD_IMULTIGRAPH_HPP */
