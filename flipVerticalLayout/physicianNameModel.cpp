#include "physicianNameModel.h"

PhysicianNameModel::PhysicianNameModel(QObject *parent) : QObject(parent)
{

}

QStringList PhysicianNameModel::physicianNames() const
{
    return m_physicianNames;
}

void PhysicianNameModel::setPhysicianNames(const QStringList &physicianNames)
{
    m_physicianNames = physicianNames;
}

QString PhysicianNameModel::selectedPysicianName() const
{
    return m_selectedPysicianName;
}

void PhysicianNameModel::setSelectedPysicianName(const QString &selectedPysicianName)
{
    m_selectedPysicianName = selectedPysicianName;
}

QString PhysicianNameModel::defaultPysicianName() const
{
    return m_defaultPysicianName;
}

void PhysicianNameModel::setDefaultPysicianName(const QString &defaultPysicianName)
{
    m_defaultPysicianName = defaultPysicianName;
}
