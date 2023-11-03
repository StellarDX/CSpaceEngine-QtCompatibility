

#include "CSE/QCSEBase.h"

_CSE_BEGIN

// Qt style CSEDateTime Output

QDebug operator<<(QDebug dbg, _TIME CSEDate date)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "cse::epoch::CSEDate(";
    if (date.IsValid()) { dbg.nospace() << date.toString("{}-{:02}-{:02}"); }
    else { dbg.nospace() << "Invalid"; }
    dbg.nospace() << ')';
    return dbg;
}

QDebug operator<<(QDebug dbg, _TIME CSETime time)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "cse::epoch::CSETime(";
    if (time.IsValid()) { dbg.nospace() << time.toString(); }
    else { dbg.nospace() << "Invalid"; }
    dbg.nospace() << ')';
    return dbg;
}

QDebug operator<<(QDebug dbg, const CSEDateTime& date)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "cse::CSEDateTime(";
    if (date.IsValid())
    {
        dbg.noquote() << date.toString("{}-{:02}-{:02} {:02}:{:02}:{:02}.{:03} UTC{:+03}:{:02}");
    }
    else {dbg.nospace() << "Invalid";}
    return dbg.nospace() << ')';
}

_CSE_END