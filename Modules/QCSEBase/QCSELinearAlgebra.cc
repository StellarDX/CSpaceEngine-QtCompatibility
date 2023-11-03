/*--------------------------------------------------------------------------------*\
|                               GLTypes compatibility                              |
\*--------------------------------------------------------------------------------*/

#include "CSE/QCSEBase.h"

_CSE_BEGIN

QVector2D QCSEBASE_EXPORT ToQType(_GL gl_vec2<float> Data)
{
	return QVector2D(Data.x, Data.y);
}

_GL gl_vec2<float> QCSEBASE_EXPORT ToCSEType(QVector2D Data)
{
	return _GL gl_vec2<float>(Data.x(), Data.y());
}

QVector3D QCSEBASE_EXPORT ToQType(_GL gl_vec3<float> Data)
{
	return QVector3D(Data.x, Data.y, Data.z);
}

_GL gl_vec3<float>QCSEBASE_EXPORT ToCSEType(QVector3D Data)
{
	return _GL gl_vec3<float>(Data.x(), Data.y(), Data.z());
}

QVector4D QCSEBASE_EXPORT ToQType(_GL gl_vec4<float> Data)
{
	return QVector4D(Data.x, Data.y, Data.z, Data.w);
}

_GL gl_vec4<float>QCSEBASE_EXPORT ToCSEType(QVector4D Data)
{
	return _GL gl_vec4<float>(Data.x(), Data.y(), Data.z(), Data.w());
}

_CSE_END