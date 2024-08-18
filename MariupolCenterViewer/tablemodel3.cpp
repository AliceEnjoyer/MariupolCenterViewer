#include "tablemodel3.h"

TableModel3::TableModel3(int rowsCount, int colsCount, QObject* obj)
    : QAbstractTableModel(obj), rows(rowsCount), cols(colsCount)  { }

QVariant TableModel3::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || index.row() > rows || index.column() > cols) return QVariant();
    return (role == Qt::DisplayRole || role == Qt::EditRole) ? mat.value(index, 0) : QVariant();
}

QVariant TableModel3::data(int i, int j) const {
    return mat.value(index(i, j));
}

Qt::ItemFlags TableModel3::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );
    return index.isValid() ? (flags | Qt::ItemIsEditable) : flags; // TODO make item is not editable
}

//void TableModel3::setSize(int rowCount)
//{

//}

bool TableModel3::setData( const QModelIndex& index, const QVariant& value, int role ) {
    if( !index.isValid() || role != Qt::EditRole || index.row() > rows || index.column() > cols) return false;

//    QString toStr = value.toString();
//    if(toStr == "") return false;
//    bool isOk;
//    double buf = toStr.toDouble(&isOk);
//    if(!isOk || buf < 0) {
//        QMessageBox::information(0, "Error", "You must write some positive integer (like 3) or positive floating point number using dot(like 3.14)");
//        return false;
//    }

//    VectoredMat[index.row()][index.column()] = buf;

//    mat[index] = toStr;
//    emit dataChanged(index, index);
    return true;
}

int TableModel3::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED(parent)
    return rows;
}

int TableModel3::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED(parent)
    return cols;
}

QVariant TableModel3::headerData (int section, Qt::Orientation orientation, int role) const {
    if( role != Qt::DisplayRole ) return QVariant();
    if( orientation == Qt::Vertical) return section;
    if( orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return "meeting";
            break;
        case 1:
            return "topic";
            break;
        case 2:
            return "essence";
            break;
        case 3:
            return "author";
            break;
        case 4:
            return "how_to_use";
            break;
        default:
            return "UNKNOWN";
            break;
        }
    }
    return QVariant();
}
