#ifndef STATEVECTORSHELL_H
#define STATEVECTORSHELL_H

#include <QDateTime>



class stateVectorShell
{
public:
    stateVectorShell();
    stateVectorShell(double X, double Y, double Z, double vX, double vY, double vZ);
    ~stateVectorShell();

    double getX() const;
    double getY() const;
    double getZ() const;
    double getvX() const;
    double getvY() const;
    double getvZ() const;


private:
//    QDateTime m_
    double m_X;
    double m_Y;
    double m_Z;
    double m_VX;
    double m_VY;
    double m_VZ;


};

#endif // STATEVECTORSHELL_H
