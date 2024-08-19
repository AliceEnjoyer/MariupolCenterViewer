#ifndef TABLEMODEL2_H
#define TABLEMODEL2_H
#include <QtWidgets>

class TableModel2 : public QAbstractTableModel {
    Q_OBJECT
public:
    explicit TableModel2 (int rows, int cols, QObject* obj = nullptr);

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
    void refreshTable();
private:
    QHash<QModelIndex, QString> mat;
    int rows;
    int cols;
};
#endif // TABLEMODEL2_H
