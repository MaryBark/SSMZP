#include "inc/stateVectorShell.h"

stateVectorShell::stateVectorShell():
    m_dt(QDateTime()), m_X(0.0), m_Y(0.0), m_Z(0.0), m_VX(0.0), m_VY(0.0), m_VZ(0.0)
{}

stateVectorShell::stateVectorShell(QDateTime dt, double X, double Y, double Z, double vX, double vY, double vZ):
    m_dt(dt), m_X(X), m_Y(Y), m_Z(Z), m_VX(vX), m_VY(vY), m_VZ(vZ)
{}

stateVectorShell::~stateVectorShell()
{}

QDateTime stateVectorShell::getDt() const
{
    return m_dt;
}

double stateVectorShell::getX() const
{
    return m_X;
}

double stateVectorShell::getY() const
{
    return m_Y;
}

double stateVectorShell::getZ() const
{
    return m_Z;
}

double stateVectorShell::getvX() const
{
    return m_VX;
}

double stateVectorShell::getvY() const
{
    return m_VY;
}

double stateVectorShell::getvZ() const
{
    return m_VZ;
}
