/*
 * File:   MGrFormatImporter.hpp
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

#ifndef HTD_HTD_MGRFORMATIMPORTER_HPP
#define	HTD_HTD_MGRFORMATIMPORTER_HPP

#include <htd/IMultiHypergraph.hpp>
#include <htd/LibraryObject.hpp>

#include <string>
#include <iostream>

namespace htd
{
    /**
     *  Importer which allows to read instances in the graph format 'mgr'.
     *
     *  (See https://github.com/mabseher/htd/formats.md for information about the available input formats.)
     */
    class MGrFormatImporter : public htd::LibraryObject
    {
        public:
            /**
             *  Constructor for a new graph importer.
             */
            MGrFormatImporter(void);

            /**
             *  Destructor of a graph importer.
             */
            ~MGrFormatImporter();

            /**
             *  Create a new IMultiHypergraph instance based on the information stored in a given file.
             *
             *  @param[in] path The path to the file from which the information can be read.
             *
             *  @return A new IMultiHypergraph instance based on the information stored in the given file.
             */
            htd::IMultiHypergraph * import(const std::string & path) const;

            /**
             *  Create a new IMultiHypergraph instance based on the information from a given stream.
             *
             *  @param[in] stream   The input stream from which the information can be read.
             *
             *  @return A new IMultiHypergraph instance based on the information from the given stream.
             */
            htd::IMultiHypergraph * import(std::istream & stream) const;
    };
}

#endif /* HTD_HTD_MGRFORMATIMPORTER_HPP */
