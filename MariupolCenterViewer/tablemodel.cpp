#include "tablemodel.h"
#include "helpFunctions.h"

TableModel::TableModel(int rowsCount, int colsCount, QObject* obj)
    : QAbstractTableModel(obj), rows(rowsCount), cols(colsCount)  { }

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || index.row() > rows || index.column() > cols) return QVariant();
    return (role == Qt::DisplayRole || role == Qt::EditRole) ? mat.value(index, 0) : QVariant();
}

QVariant TableModel::data(int i, int j) const {
    return mat.value(index(i, j));
}

Qt::ItemFlags TableModel::flags( const QModelIndex& index ) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags( index );
    return index.isValid() ? (flags | Qt::ItemIsEditable) : flags; // TODO make item is not editable
}

void TableModel::refreshTable()
{
    QFile f(QCoreApplication::applicationDirPath() + "/db/participants.db");
    if (!f.open(QIODevice::ReadOnly)) {
        qDebug() << "Can not open file:" << f.errorString();
        return;
    }

    beginResetModel();
    mat.clear();
    int i = 0;
    while (!f.atEnd()) {
        QString line = f.readLine().trimmed();
        if (line.isEmpty()) {
            continue; // Пропуск пустых строк
        }

        QList<QString> l = split(line.toStdString(), ';');
        if (l.size() < 3) {
            qDebug() << "Ошибка: недостаточно элементов в строке";
            continue; // Пропуск некорректных строк
        }
        qDebug() << l[0] << l[1] << l[2];
        mat.insert(createIndex(i, 0), l[0]);
        mat.insert(createIndex(i, 1), l[1]);
        mat.insert(createIndex(i, 2), l[2]);
        ++i;
    }
    rows = i;
    endResetModel();

    f.close();

    //if (i > 0) emit dataChanged(createIndex(0,0), createIndex(i - 1, 2));
}


//void TableModel::setSize(int rowCount)
//{

//}

bool TableModel::setData( const QModelIndex& index, const QVariant& value, int role ) {
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

//    mat[index] = value.toString();
//    emit dataChanged(index, index);
    return true;
}

int TableModel::rowCount( const QModelIndex& parent ) const {
    Q_UNUSED(parent)
    return rows;
}

int TableModel::columnCount( const QModelIndex& parent ) const {
    Q_UNUSED(parent)
    return cols;
}

QVariant TableModel::headerData (int section, Qt::Orientation orientation, int role) const {
    if( role != Qt::DisplayRole ) return QVariant();
    if( orientation == Qt::Vertical) return section;
    if( orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return "name";
            break;
        case 1:
            return "city";
            break;
        case 2:
            return "meetings visited";
            break;
        default:
            return "UNKNOWN";
            break;
        }
    }
    return QVariant();
}
