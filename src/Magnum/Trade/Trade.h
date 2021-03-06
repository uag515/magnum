#ifndef Magnum_Trade_Trade_h
#define Magnum_Trade_Trade_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/** @file
 * @brief Forward declarations for Magnum::Trade namespace
 */

#include "Magnum/Types.h"

namespace Magnum { namespace Trade {

#ifndef DOXYGEN_GENERATING_OUTPUT
class AbstractImageConverter;
class AbstractImporter;
class AbstractMaterialData;
class CameraData;

template<UnsignedInt> class ImageData;
typedef ImageData<1> ImageData1D;
typedef ImageData<2> ImageData2D;
typedef ImageData<3> ImageData3D;

class LightData;
class MeshData2D;
class MeshData3D;
class MeshObjectData2D;
class MeshObjectData3D;
class ObjectData2D;
class ObjectData3D;
class PhongMaterialData;
class TextureData;
class SceneData;
#endif

}}

#endif
