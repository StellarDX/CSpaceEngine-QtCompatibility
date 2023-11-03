#include <QVectorND.h>
#include <QDateTime.h>
#include <CSE/Core/gltypes.h>
#include <CSE/Core/DateTime.h>
#include <CSE/QCSEBase.h>

using namespace std;
using namespace cse;

int main()
{
    CSEDateTime CSEDT1 = CSEDateTime::currentDateTimeUTC();
    QDateTime QDT1 = ToQType(CSEDT1);
    qDebug() << QDT1 << '\n';

    QDateTime QDT2 = QDateTime::currentDateTime();
    CSEDateTime CSEDT2 = ToCSEType(QDT2);
    qDebug() << CSEDT2 << '\n';
    qDebug() << CSEDT2.date() << '\n';
    qDebug() << CSEDT2.time() << '\n';

    vec3 CSEVec1(12.3, 4.56, 7.89);
    QVector3D QVec1 = ToQType(VConvert<float64, float>(CSEVec1));
    qDebug() << QVec1 << '\n';

    QVector3D QVec2(9.87, 6.54, 32.1);
    vec3 CSEVec = VConvert(ToCSEType(QVec2));
    qDebug() << CSEVec << '\n';

    mat4x3 CSEMat1({ {2,-3,-2},{1,-1,1},{-1,2,2},{8,-11,-3} });
    QGenericMatrix QMat1 = ToQType(CSEMat1);
    qDebug() << QMat1 << '\n';

    float64 PMat2[] = {3, 1, 7, -4};
    QGenericMatrix<2, 2, float64> QMat2(PMat2);
    mat2 CSEMat2 = ToCSEType(QMat2);
    qDebug() << CSEMat2 << '\n';
}
