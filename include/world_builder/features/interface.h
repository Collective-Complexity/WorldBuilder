/*
  Copyright (C) 2018 by the authors of the World Builder code.

  This file is part of the World Builder.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef _world_builder_features_interface_h
#define _world_builder_features_interface_h

#include <vector>

#include <boost/property_tree/ptree.hpp>

#include <world_builder/world.h>
#include <world_builder/parameters.h>
#include <world_builder/point.h>


using boost::property_tree::ptree;


namespace WorldBuilder
{
  class World;

  /**
   * This class is an interface for the specific plate tectonic feature classes,
   * such as continental plate, oceanic plate and subduction zone.
   */
  namespace Features
  {

    class Interface
    {
      public:
        /**
         * constructor
         */
        Interface();

        /**
         * Destructor
         */
        virtual
        ~Interface();

        /**
         * declare and read in the world builder file into the parameters class
         */
        virtual
        void decare_entries(std::string &path) = 0;

        /**
         * read in the world builder file
         */
        virtual
        void read(const ptree &property_tree, std::string &path) = 0;

        /**
         * takes temperature and position and returns a temperature.
         */
        virtual
        double temperature(const Point<3> &position,
                           const double depth,
                           const double gravity,
                           double temperature) const = 0;
        /**
         * Returns a value for the reqeusted composition (0 is not present,
         * 1 is present) based on the given position and
         */
        virtual
        bool composition(const Point<3> &position,
                         const double depth,
                         const unsigned int composition_number,
                         bool temperature) const = 0;


      protected:
        /**
         * A pointer to the world class to retrieve variables.
         */
        WorldBuilder::World *world;

        /**
         * The name of the feature type.
         */
        std::string name;

        /**
         * The coordinates at the surface of the feature
         */
        std::vector<Point<2> > coordinates;

        /**
         * The name of the temperature submodule used by this feature.
         */
        std::string temperature_submodule_name;

        /**
         * The name of the composition submodule used by this feature.
         */
        std::string composition_submodule_name;

    };


    /**
     * factory function
     */
    std::unique_ptr<Interface>
    create_feature(const std::string name, WorldBuilder::World *world);

  }
}

#endif
