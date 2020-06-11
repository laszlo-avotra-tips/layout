#ifndef PHYSICIANNAMEMODEL_H
#define PHYSICIANNAMEMODEL_H

#include <QObject>
#include <QStringList>
#include <QString>

class PhysicianNameModel : public QObject
{
    Q_OBJECT
public:
    explicit PhysicianNameModel(QObject *parent = nullptr);
    void addPhysicianName(const QString& pn);


    QStringList physicianNames() const;
    void setPhysicianNames(const QStringList &physicianNames);

    QString selectedPysicianName() const;
    void setSelectedPysicianName(const QString &selectedPysicianName);

    QString defaultPysicianName() const;
    void setDefaultPysicianName(const QString &defaultPysicianName);

signals:


private:
    QStringList m_physicianNames{{"DR. Patel"}, {"DR. Smith"}, {"DR. Johnes"}};
    QString m_selectedPysicianName{"DR. Patel"};
    QString m_defaultPysicianName{"DR. Smith"};

};

#endif // PHYSICIANNAMEMODEL_H
