<h1>Qt Compatibility for CSpaceEngine</h1>

<h2>System requirements</h2>
<ul>
	<li>CSpaceEngine</li>
	<li>Qt 6.6.0 or higher version</li>
</ul>

<h2>Type compatibilities</h2>
<p>
	Some types in CSE and Qt are almost same, so this module provides convert functions for each other.<br>
	Use "cse::ToQType" and "cse::ToCSEType" to convert them between CSE and Qt.<br>
	The following types are supported.
</p>
<table>
	<tr><th>CSE Type</th><th>Qt Type</th></tr>
	<tr><td>cse::gl::gl_vec2&ltfloat&gt</td><td>QVector2D</td></tr>
	<tr><td>cse::gl::gl_vec3&ltfloat&gt</td><td>QVector3D</td></tr>
	<tr><td>cse::gl::gl_vec4&ltfloat&gt</td><td>QVector4D</td></tr>
	<tr><td>cse::matrix&lttype, col, row&gt</td><td>QGenericMatrix&ltcol, row, type&gt</td></tr>
	<tr><td>cse::epoch::CSEDate</td><td>QDate</td></tr>
	<tr><td>cse::epoch::CSETime</td><td>QTime</td></tr>
	<tr><td>cse::CSEDateTime</td><td>QDateTime</td></tr>
</table>

<p><i>
Note: QVectorND uses 32-bit floating point to store values and only has this type. 
So it convertion to CSE type is also using 32-bit floating point and not cse::vec2
Because cse::vecN uses 64-bit floating point. If you want to convert to cse::vecN,
use "cse::VConvert" to convert. Also, QVectorND can't get values directly, it uses
"x()" function instead. I think this feature is "chicken ribs", "pitiful to throw 
them away, yet there is not much to eat."
</i></p>