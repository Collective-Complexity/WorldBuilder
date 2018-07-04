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

#ifndef _world_builder_feature_features_continental_plate_h
#define _world_builder_feature_features_continental_plate_h

#include <world_builder/utilities.h>
#include <world_builder/coordinate_systems/interface.h>


namespace WorldBuilder
{
  namespace CoordinateSystems
  {

    /**
     * This implements a Cartesian geometry model.The Cartesian geometry model
     * doesn't do anything with the coordinates, but is needed to have a common
     * interface for all the geometry models.
     */
    class Cartesian : public Interface
    {
      public:
        /**
         * constructor
         */
        Cartesian();

        /**
         * Destructor
         */
        ~Cartesian();

        /**
         * Read in the world builder file
         */
        virtual
        void read(const ptree &property_tree, std::string &path);

        /**
         * Returns what the natural coordinate system for this Coordinate System is.
         */
        virtual
        CoordinateSystem natural_coordinate_system() const;

        /**
         * Takes the Cartesian points (x,z or x,y,z) and returns standardized
         * coordinates which are most 'natural' to the geometry model. For a box
         * this will  be (x,z) in 2d or (x,y,z) in 3d, and for a spheroid geometry
         * model it  will be (radius, longitude) in 2d and (radius, longitude,
         * latitude) in 3d.
         */
        virtual
        std::array<double,3> cartesian_to_natural_coordinates(const std::array<double,3> &position) const;

        /**
         * Undoes the action of cartesian_to_natural_coordinates, and turns the
         * coordinate system which is most 'natural' to the geometry model into
         * Cartesian coordinates.
         */
        virtual
        std::array<double,3> natural_to_cartesian_coordinates(const std::array<double,3> &position) const;


      private:

    };
  }
}

#endif
