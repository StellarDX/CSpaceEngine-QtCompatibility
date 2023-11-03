/*--------------------------------------------------------------------------------*\
|                              DateTime compatibility                              |
\*--------------------------------------------------------------------------------*/

#include "CSE/QCSEBase.h"

_CSE_BEGIN

QDate QCSEBASE_EXPORT ToQType(_TIME CSEDate Date)
{
	return QDate(Date.year(), Date.month(), Date.day());
}

_TIME CSEDate QCSEBASE_EXPORT ToCSEType(QDate Date)
{
	return _TIME CSEDate(Date.year(), Date.month(), Date.day());
}

QTime QCSEBASE_EXPORT ToQType(_TIME CSETime Time)
{
	return QTime(Time.hour(), Time.minute(), Time.second(), Time.msec());
}

_TIME CSETime QCSEBASE_EXPORT ToCSEType(QTime Time)
{
	return _TIME CSETime(Time.hour(), Time.minute(), Time.second(), Time.msec());
}

QDateTime QCSEBASE_EXPORT ToQType(CSEDateTime DateTime, int ConvertMethod)
{
	switch (ConvertMethod)
	{
	default:
	case 0:
		return QDateTime(ToQType(DateTime.date()), ToQType(DateTime.time()), QTimeZone(DateTime.TimeZone() * 3600));
		break;
	case 1:
		return QDateTime(ToQType(DateTime.date()), ToQType(DateTime.time()), Qt::OffsetFromUTC, DateTime.OffsetFromUTC());
		break;
	}
}

CSEDateTime QCSEBASE_EXPORT ToCSEType(QDateTime DateTime, int ConvertMethod)
{
	switch (ConvertMethod)
	{
	default:
	case 0:
		return CSEDateTime(ToCSEType(DateTime.date()), ToCSEType(DateTime.time()), DateTime.timeZone().fixedSecondsAheadOfUtc());
		break;
	case 1:
		return CSEDateTime(ToCSEType(DateTime.date()), ToCSEType(DateTime.time()), DateTime.offsetFromUtc());
		break;
	}
}

_CSE_END