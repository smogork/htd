/* 
 * File:   Hypergraph.hpp
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

#ifndef HTD_HTD_HYPERGRAPH_HPP
#define	HTD_HTD_HYPERGRAPH_HPP

#include <htd/IMutableHypergraph.hpp>

#include <vector>
#include <unordered_set>

namespace htd
{
    class Hypergraph : public virtual htd::IMutableHypergraph
    {
        public:
            Hypergraph(void);

            Hypergraph(const Hypergraph & original);

            Hypergraph(const htd::IHypergraph & original);

            virtual ~Hypergraph();
            
            std::size_t vertexCount(void) const HTD_OVERRIDE;

            std::size_t edgeCount(void) const HTD_OVERRIDE;

            std::size_t edgeCount(htd::vertex_t vertex) const HTD_OVERRIDE;

            bool isVertex(htd::vertex_t vertex) const HTD_OVERRIDE;

            bool isEdge(htd::id_t edgeId) const HTD_OVERRIDE;

            bool isEdge(htd::vertex_t vertex1, htd::vertex_t vertex2) const HTD_OVERRIDE;

            bool isEdge(const std::vector<htd::vertex_t> & elements) const HTD_OVERRIDE;

            bool isEdge(const htd::ConstCollection<htd::vertex_t> & elements) const HTD_OVERRIDE;

            htd::ConstCollection<htd::id_t> associatedEdgeIds(htd::vertex_t vertex1, htd::vertex_t vertex2) const HTD_OVERRIDE;

            htd::ConstCollection<htd::id_t> associatedEdgeIds(const std::vector<htd::vertex_t> & elements) const HTD_OVERRIDE;

            htd::ConstCollection<htd::id_t> associatedEdgeIds(const htd::ConstCollection<htd::vertex_t> & elements) const HTD_OVERRIDE;

            htd::vertex_t vertexAtPosition(htd::index_t index) const HTD_OVERRIDE;
            
            bool isConnected(void) const HTD_OVERRIDE;
            
            bool isConnected(htd::vertex_t vertex1, htd::vertex_t vertex2) const HTD_OVERRIDE;

            bool isNeighbor(htd::vertex_t vertex, htd::vertex_t neighbor) const HTD_OVERRIDE;
            
            std::size_t neighborCount(htd::vertex_t vertex) const HTD_OVERRIDE;

            htd::ConstCollection<htd::vertex_t> neighbors(htd::vertex_t vertex) const HTD_OVERRIDE;

            htd::vertex_t neighbor(htd::vertex_t vertex, htd::index_t index) const HTD_OVERRIDE;

            htd::ConstCollection<htd::vertex_t> vertices(void) const HTD_OVERRIDE;

            std::size_t isolatedVertexCount(void) const HTD_OVERRIDE;

            htd::ConstCollection<htd::vertex_t> isolatedVertices(void) const HTD_OVERRIDE;

            htd::vertex_t isolatedVertex(htd::index_t index) const HTD_OVERRIDE;

            bool isIsolatedVertex(htd::vertex_t vertex) const HTD_OVERRIDE;

            htd::ConstCollection<htd::Hyperedge> hyperedges(void) const HTD_OVERRIDE;

            htd::ConstCollection<htd::Hyperedge> hyperedges(htd::vertex_t vertex) const HTD_OVERRIDE;

            const htd::Hyperedge & hyperedge(htd::id_t edgeId) const HTD_OVERRIDE;

            const htd::Hyperedge & hyperedgeAtPosition(htd::index_t index) const HTD_OVERRIDE;

            const htd::Hyperedge & hyperedgeAtPosition(htd::index_t index, htd::vertex_t vertex) const HTD_OVERRIDE;

            htd::vertex_t addVertex(void) HTD_OVERRIDE;
            
            void removeVertex(htd::vertex_t vertex) HTD_OVERRIDE;

            htd::id_t addEdge(htd::vertex_t vertex1, htd::vertex_t vertex2) HTD_OVERRIDE;

            htd::id_t addEdge(const std::vector<htd::vertex_t> & elements) HTD_OVERRIDE;

            htd::id_t addEdge(const htd::ConstCollection<htd::vertex_t> & elements) HTD_OVERRIDE;

            htd::id_t addEdge(const htd::Hyperedge & hyperedge) HTD_OVERRIDE;

            void removeEdge(htd::id_t edgeId) HTD_OVERRIDE;

            Hypergraph * clone(void) const HTD_OVERRIDE;

            Hypergraph & operator=(const Hypergraph & original);

            Hypergraph & operator=(const htd::IHypergraph & original) HTD_OVERRIDE;

        private:
            std::size_t size_;

            htd::index_t next_edge_;

            htd::vertex_t next_vertex_;

            htd::vertex_container vertices_;

            std::unordered_set<htd::vertex_t> deletions_;

            htd::hyperedge_container edges_;

            std::vector<htd::vertex_container> neighborhood_;
    };
}

#endif /* HTD_HTD_HYPERGRAPH_HPP */
