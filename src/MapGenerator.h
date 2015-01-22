/*
    Random Map Generator.
    Copyright (C) 2014  Paul Wortmann

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    paul.wortmann@gmail.com
*/

#ifndef MAP_GENERATOR_H
#define MAP_GENERATOR_H

#include <iostream>

#define GEN_ALGORITHM_C1  0
#define GEN_ALGORITHM_D1  1
#define GEN_ALGORITHM_D2  2
#define GEN_ALGORITHM_D3  3
#define GEN_ALGORITHM_M1  4
#define GEN_ALGORITHM_T1  5

class MapType
{
    public:
        int  dimension_x;
        int  dimension_y;
        int  no_of_tiles;
        int  algorithm;
        int* layer_background;
        int* layer_object;
        int* layer_collision;
        std::string map_name;
        MapType(void);
        ~MapType(void);
};

class MapGenerator
{
    public:
        virtual ~MapGenerator(void) {};
        virtual void Initialize (MapType* map_pointer);
        virtual void Generate (MapType* map_pointer) = 0;
        virtual void Export (MapType* map_pointer);
};

void MapGenerate(MapType* map_pointer);

#endif // MAP_GENERATOR_H
