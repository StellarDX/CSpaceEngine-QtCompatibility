/***
*       Qt Compatibility for CSpaceEngine
*
*       Copyright (C) 2020 The Qt Company Ltd.
*       Copyright (C) StellarDX Astronomy.
*       SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
*
*       This program is free software; you can redistribute it and/or modify
*       it under the terms of the GNU General Public License as published by
*       the Free Software Foundation; either version 3 of the License, or
*       (at your option) any later version.
*
*       This program is distributed in the hope that it will be useful,
*       but WITHOUT ANY WARRANTY; without even the implied warranty of
*       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*       GNU General Public License for more details.
*
*       You should have received a copy of the GNU General Public License along
*       with this program; If not, see <https://www.gnu.org/licenses/>.
*
****/

#pragma once

#ifndef _QCSEBASE_
#define _QCSEBASE_

#include <QGlobal.h>
#include <QvectorND.h>
#include <QGenericMatrix.h>
#include <QDateTime.h>
#include <QTimezone.h>
#include <CSE/Core/gltypes.h>
#include <CSE/Core/DateTime.h>

#ifndef BUILD_STATIC
# if defined(QCSEBASE_LIB)
#  define QCSEBASE_EXPORT Q_DECL_EXPORT
# else
#  define QCSEBASE_EXPORT Q_DECL_IMPORT
# endif
#else
# define QCSEBASE_EXPORT
#endif

_CSE_BEGIN

class QCSEBase
{
public:
    QCSEBase() { /*Nothing...*/ };
};

/*--------------------------------------------------------------------------------*\
|                              Type convert functions                              |
\*--------------------------------------------------------------------------------*/

// cse::vecN <-> QVectorND

/// <summary>
/// Convert CSE type to compatable Qt type
/// </summary>
QVector2D QCSEBASE_EXPORT ToQType(_GL gl_vec2<float> Data);
/// <summary>
/// Convert Qt type to compatable CSE type
/// </summary>
_GL gl_vec2<float> QCSEBASE_EXPORT ToCSEType(QVector2D Data);

/// <summary>
/// Convert CSE type to compatable Qt type
/// </summary>
QVector3D QCSEBASE_EXPORT ToQType(_GL gl_vec3<float> Data);
/// <summary>
/// Convert Qt type to compatable CSE type
/// </summary>
_GL gl_vec3<float> QCSEBASE_EXPORT ToCSEType(QVector3D Data);

/// <summary>
/// Convert CSE type to compatable Qt type
/// </summary>
QVector4D QCSEBASE_EXPORT ToQType(_GL gl_vec4<float> Data);
/// <summary>
/// Convert Qt type to compatable CSE type
/// </summary>
_GL gl_vec4<float> QCSEBASE_EXPORT ToCSEType(QVector4D Data);

/// <summary>
/// Convert vector type between float-32 and float-64
/// </summary>
template<typename Ty1 = float, typename Ty2 = float64>
requires _STD is_floating_point_v<Ty1> && _STD is_floating_point_v<Ty2> && (!_STD is_same_v<Ty1, Ty2>)
_GL gl_vec2<Ty2> VConvert(_GL gl_vec2<Ty1> Data)
{
    return _GL gl_vec2<Ty2>(Data.x, Data.y);
}

template<typename Ty1 = float, typename Ty2 = float64>
requires _STD is_floating_point_v<Ty1> && _STD is_floating_point_v<Ty2> && (!_STD is_same_v<Ty1, Ty2>)
_GL gl_vec3<Ty2> VConvert(_GL gl_vec3<Ty1> Data)
{
    return _GL gl_vec3<Ty2>(Data.x, Data.y, Data.z);
}

template<typename Ty1 = float, typename Ty2 = float64>
requires _STD is_floating_point_v<Ty1> && _STD is_floating_point_v<Ty2> && (!_STD is_same_v<Ty1, Ty2>)
_GL gl_vec4<Ty2> VConvert(_GL gl_vec4<Ty1> Data)
{
    return _GL gl_vec4<Ty2>(Data.x, Data.y, Data.z, Data.w);
}

/// <summary>
/// Convert CSE type to compatable Qt type
/// </summary>
template<typename Ty, int Column, int Line>
QGenericMatrix<Column, Line, Ty> ToQType(matrix<Ty, Column, Line> Data)
{
    QGenericMatrix<Column, Line, Ty> Result;
    for (size_t i = 0; i < Column; i++)
    {
        for (size_t j = 0; j < Line; j++)
        {
            Result(j, i) = Data[i][j];
        }
    }
    return Result;
}
/// <summary>
/// Convert Qt type to compatable CSE type
/// </summary>
template<typename Ty, int Column, int Line>
matrix<Ty, Column, Line> ToCSEType(QGenericMatrix<Column, Line, Ty> Data)
{
    matrix<Ty, Column, Line> Result;
    for (size_t i = 0; i < Column; i++)
    {
        for (size_t j = 0; j < Line; j++)
        {
            Result[i][j] = Data(j, i);
        }
    }
    return Result;
}

// CSEDateTime <-> QDateTime

/// <summary>
/// Convert CSE type to compatable Qt type
/// </summary>
QDate QCSEBASE_EXPORT ToQType(_TIME CSEDate Date);
/// <summary>
/// Convert Qt type to compatable CSE type
/// </summary>
_TIME CSEDate QCSEBASE_EXPORT ToCSEType(QDate Date);

/// <summary>
/// Convert CSE type to compatable Qt type
/// </summary>
QTime QCSEBASE_EXPORT ToQType(_TIME CSETime Time);
/// <summary>
/// Convert Qt type to compatable CSE type
/// </summary>
_TIME CSETime QCSEBASE_EXPORT ToCSEType(QTime Time);

/// <summary>
/// Convert CSE type to compatable Qt type
/// </summary>
/// <param name="ConvertMethod">0 = using timezone, 1 = using offset seconds</param>
QDateTime QCSEBASE_EXPORT ToQType(CSEDateTime DateTime, int ConvertMethod = 0);
/// <summary>
/// Convert CSE type to compatable Qt type
/// </summary>
/// <param name="ConvertMethod">0 = using timezone, 1 = using offset seconds</param>
CSEDateTime QCSEBASE_EXPORT ToCSEType(QDateTime DateTime, int ConvertMethod = 0);

_CSE_END

#endif