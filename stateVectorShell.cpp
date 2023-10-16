#include "stateVectorShell.h"

stateVectorShell::stateVectorShell():
    m_X(0.0), m_Y(0.0), m_Z(0.0), m_VX(0.0), m_VY(0.0), m_VZ(0.0)
{}

stateVectorShell::stateVectorShell(double X, double Y, double Z, double vX, double vY, double vZ):
    m_X(X), m_Y(Y), m_Z(Z), m_VX(vX), m_VY(vY), m_VZ(vZ)
{}

stateVectorShell::~stateVectorShell()
{}

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
