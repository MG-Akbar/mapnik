
/*****************************************************************************
 *
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2014 Artem Pavlenko
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

// mapnik
#include <mapnik/config.hpp>
#include <mapnik/image.hpp>
#include <mapnik/pixel_types.hpp>

//stl
#include <stdexcept>

namespace mapnik
{

template <>
class image<null_t>
{
public:
    using pixel_type = typename null_t::type;
    static const image_dtype dtype = null_t::id;
private:
public:
    image() {}
    image(int width, 
          int height, 
          bool initialize = true, 
          bool premultiplied = false, 
          bool painted = false) {}
    image(image<null_t> const& rhs) {}
    image(image<null_t> && rhs) noexcept {}

    void swap(image<null_t> & rhs) {}
    std::size_t width() const { return 0; }
    std::size_t height() const { return 0; }
    unsigned getSize() const { return 0; }
    unsigned getRowSize() const { return 0; }
    void set(pixel_type const& t) { throw std::runtime_error("Can not set values for null image"); }
    const unsigned char* getBytes() const { return nullptr; }
    unsigned char* getBytes() {return nullptr; }
    double get_offset() const { return 0.0; }
    void set_offset(double set) {}
    double get_scaling() const { return 1.0; }
    void set_scaling(double set) {}
    bool get_premultiplied() const { return false; }
    void set_premultiplied(bool set) {}
    void painted(bool painted) {}
    bool painted() const { return false; }
    image_dtype get_dtype() const { return dtype; }
};

} // end ns mapnik
