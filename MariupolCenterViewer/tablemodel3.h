#ifndef TABLEMODEL3_H
#define TABLEMODEL3_H

#include <QtWidgets>

class TableModel3 : public QAbstractTableModel {
    Q_OBJECT
public:
    explicit TableModel3 (int rows, int cols, QObject* obj = nullptr);

    QVariant data (const QModelIndex& index, int role) const override;
    QVariant data (int i, int j) const;
    bool setData (const QModelIndex& index, const QVariant& data, int role) override;
    void setData (int i, int j, const QVariant& data);
    void clearData();

    int rowCount (const QModelIndex& index = QModelIndex()) const override;
    int columnCount ( const QModelIndex& parent = QModelIndex()) const override;

    QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags (const QModelIndex&) const override;

    //void addPerson();

    //void setSize(int rowCount);

    //void clear();
private:
    QHash<QModelIndex, QString> mat;
    int rows;
    int cols;
};

#endif // TABLEMODEL3_H
