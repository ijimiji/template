#include <QApplication>
#include <QListWidget>

static const QStringList LIST_ITEMS = 
    QStringList() << "C++" << "Python" << "Java" << "C#" << "PHP" << "Ruby" << "JavaScript";

// Класс-обработчик сигналов от виджета списка
class ListController : public QObject {
    Q_OBJECT
public slots:
    void onListDoubleClicked( const QModelIndex& index ) {
        if( !index.isValid() ) {
            return;
        }

        if( QListWidget* listWgt = dynamic_cast< QListWidget* >( sender() ) ) {
            if( QListWidgetItem* item = listWgt->takeItem( index.row() ) ) {
                delete item;
            }
        }
    }
};