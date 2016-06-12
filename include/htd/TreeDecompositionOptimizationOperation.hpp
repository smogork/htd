/*
 * File:   TreeDecompositionOptimizationOperation.hpp
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

#ifndef HTD_HTD_TREEDECOMPOSITIONOPTIMIZATIONOPERATION_HPP
#define	HTD_HTD_TREEDECOMPOSITIONOPTIMIZATIONOPERATION_HPP

#include <htd/Globals.hpp>
#include <htd/ITreeDecompositionManipulationOperation.hpp>
#include <htd/ITreeDecompositionFitnessFunction.hpp>
#include <htd/ITreeDecompositionManipulationOperation.hpp>

#include <vector>

namespace htd
{
    /**
     *  Implementation of the IDecompositionManipulationOperation interface which manipulates
     *  given tree decompositions in such a way that the fitness value of the resulting tree 
     *  decomposition is maximal.
     */
    class TreeDecompositionOptimizationOperation : public virtual htd::ITreeDecompositionManipulationOperation
    {
        public:
            /**
             *  Constructor for a new manipulation operation of type TreeDecompositionOptimizationOperation.
             *
             *  @param[in] fitnessFunction  The fitness function which is used to determine the quality of tree decompositions.
             */
            TreeDecompositionOptimizationOperation(const htd::ITreeDecompositionFitnessFunction & fitnessFunction);

            ~TreeDecompositionOptimizationOperation();

            void apply(htd::IMutableTreeDecomposition & decomposition) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::vertex_t> & relevantVertices) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const HTD_OVERRIDE;

            void apply(htd::IMutableTreeDecomposition & decomposition, const std::vector<htd::vertex_t> & relevantVertices, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const HTD_OVERRIDE;

            TreeDecompositionOptimizationOperation * clone(void) const HTD_OVERRIDE;

        private:
            htd::ITreeDecompositionFitnessFunction * fitnessFunction_;

            std::vector<htd::ITreeDecompositionManipulationOperation *> manipulationOperations_;
    };
}

#endif /* HTD_HTD_TREEDECOMPOSITIONOPTIMIZATIONOPERATION_HPP */