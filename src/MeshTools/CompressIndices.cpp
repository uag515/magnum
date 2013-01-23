/*
    Copyright © 2010, 2011, 2012 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include "CompressIndices.h"

#include <cstring>
#include <algorithm>

#include "Math/Functions.h"

namespace Magnum { namespace MeshTools {

#ifndef DOXYGEN_GENERATING_OUTPUT
namespace {

template<class> constexpr Mesh::IndexType indexType();
template<> inline constexpr Mesh::IndexType indexType<GLubyte>() { return Mesh::IndexType::UnsignedByte; }
template<> inline constexpr Mesh::IndexType indexType<GLushort>() { return Mesh::IndexType::UnsignedShort; }
template<> inline constexpr Mesh::IndexType indexType<GLuint>() { return Mesh::IndexType::UnsignedInt; }

template<class T> inline std::tuple<std::size_t, Mesh::IndexType, char*> compress(const std::vector<std::uint32_t>& indices) {
    char* buffer = new char[indices.size()*sizeof(T)];
    for(std::size_t i = 0; i != indices.size(); ++i) {
        T index = static_cast<T>(indices[i]);
        std::memcpy(buffer+i*sizeof(T), &index, sizeof(T));
    }

    return std::make_tuple(indices.size(), indexType<T>(), buffer);
}

}
#endif

std::tuple<std::size_t, Mesh::IndexType, char*> compressIndices(const std::vector<std::uint32_t>& indices) {
    std::size_t size = *std::max_element(indices.begin(), indices.end());

    switch(Math::log(256, size)) {
        case 0:
            return compress<GLubyte>(indices);
        case 1:
            return compress<GLushort>(indices);
        case 2:
        case 3:
            return compress<GLuint>(indices);

        default:
            CORRADE_ASSERT(false, "MeshTools::compressIndices(): no type able to index" << size << "elements.", {});
    }
}

void compressIndices(Mesh* mesh, Buffer* buffer, Buffer::Usage usage, const std::vector<std::uint32_t>& indices) {
    std::size_t indexCount;
    Mesh::IndexType indexType;
    char* data;
    std::tie(indexCount, indexType, data) = compressIndices(indices);

    mesh->setIndexCount(indices.size())
        ->setIndexBuffer(buffer, 0, indexType);
    buffer->setData(indexCount*Mesh::indexSize(indexType), data, usage);

    delete[] data;
}

}}
