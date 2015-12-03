/*
 * File:   HypertreeDecompositionLabelingFunction.cpp
 *
 * Author: ABSEHER Michael (abseher@dbai.tuwien.ac.at)
 * 
 * Copyright 2015, Michael Abseher
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

#ifndef HTD_HTD_HYPERTREEDECOMPOSITIONLABELINGFUNCTION_CPP
#define	HTD_HTD_HYPERTREEDECOMPOSITIONLABELINGFUNCTION_CPP

#include <htd/Globals.hpp>
#include <htd/HypertreeDecompositionLabelingFunction.hpp>

#include <htd/ILabel.hpp>
#include <htd/IHypergraph.hpp>
#include <htd/ISetCoverAlgorithm.hpp>
#include <htd/HyperedgeContainerLabel.hpp>

#include <string>

htd::HypertreeDecompositionLabelingFunction::HypertreeDecompositionLabelingFunction(const htd::IHypergraph & graph, const htd::ISetCoverAlgorithm & setCoverAlgorithm) : graph_(graph), setCoverAlgorithm_(setCoverAlgorithm)
{
    htd::hyperedge_container hyperedges;

    graph_.getHyperedges(hyperedges);

    hyperedges_ = htd::hyperedge_container(hyperedges.begin(), hyperedges.end());
}

htd::HypertreeDecompositionLabelingFunction::~HypertreeDecompositionLabelingFunction()
{

}

std::string htd::HypertreeDecompositionLabelingFunction::name() const
{
    return htd::edge_label_name;
}

htd::ILabel * htd::HypertreeDecompositionLabelingFunction::computeLabel(const htd::vertex_container & vertices) const
{
    htd::hyperedge_container label;

    setCoverAlgorithm_.computeSetCover(vertices, hyperedges_, label);

    return new HyperedgeContainerLabel(label);
}

#endif /* HTD_HTD_HYPERTREEDECOMPOSITIONLABELINGFUNCTION_CPP */