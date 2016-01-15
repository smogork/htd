/*
 * File:   DirectedMultiGraphFactory.cpp
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

#ifndef HTD_HTD_DIRECTEDMULTIGRAPHFACTORY_CPP
#define HTD_HTD_DIRECTEDMULTIGRAPHFACTORY_CPP

#include <htd/Globals.hpp>
#include <htd/DirectedMultiGraphFactory.hpp>
#include <htd/DirectedMultiGraph.hpp>

#include <stdexcept>

htd::DirectedMultiGraphFactory::DirectedMultiGraphFactory(void)
{
    constructionTemplate_ = new htd::DirectedMultiGraph();
}

htd::DirectedMultiGraphFactory::~DirectedMultiGraphFactory()
{
    if (constructionTemplate_ != nullptr)
    {
        delete constructionTemplate_;

        constructionTemplate_ = nullptr;
    }
}

htd::DirectedMultiGraphFactory & htd::DirectedMultiGraphFactory::instance(void)
{
    static htd::DirectedMultiGraphFactory instance_;

    return instance_;
}

htd::IMutableDirectedMultiGraph * htd::DirectedMultiGraphFactory::getDirectedMultiGraph(void)
{
    return constructionTemplate_->clone();
}

htd::IMutableDirectedMultiGraph * htd::DirectedMultiGraphFactory::getDirectedMultiGraph(std::size_t initialSize)
{
    htd::IMutableDirectedMultiGraph * ret = constructionTemplate_->clone();

    ret->addVertices(initialSize);

    return ret;
}

htd::IMutableDirectedMultiGraph * htd::DirectedMultiGraphFactory::getDirectedMultiGraph(const htd::IDirectedMultiGraph & original)
{
    htd::IMutableDirectedMultiGraph * ret = constructionTemplate_->clone();

    *ret = original;

    return ret;
}

void htd::DirectedMultiGraphFactory::setConstructionTemplate(htd::IMutableDirectedMultiGraph * original)
{
    if (original == nullptr)
    {
        throw std::logic_error("void htd::DirectedMultiGraphFactory::setConstructionTemplate(htd::IMutableDirectedMultiGraph *)");
    }

    if (original->vertexCount() > 0)
    {
        throw std::logic_error("void htd::DirectedMultiGraphFactory::setConstructionTemplate(htd::IMutableDirectedMultiGraph *)");
    }

    if (constructionTemplate_ != nullptr)
    {
        delete constructionTemplate_;

        constructionTemplate_ = nullptr;
    }

    constructionTemplate_ = original;
}

htd::IMutableDirectedMultiGraph & htd::DirectedMultiGraphFactory::accessMutableDirectedMultiGraph(htd::IDirectedMultiGraph & original)
{
    return *(dynamic_cast<htd::IMutableDirectedMultiGraph *>(&original));
}

const htd::IMutableDirectedMultiGraph & htd::DirectedMultiGraphFactory::accessMutableDirectedMultiGraph(const htd::IDirectedMultiGraph & original)
{
    return *(dynamic_cast<const htd::IMutableDirectedMultiGraph *>(&original));
}

#endif /* HTD_HTD_DIRECTEDMULTIGRAPHFACTORY_CPP */
