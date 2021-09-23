#include <QApplication>
#include <QListWidget>
#include "list.h"

int main( int argc, char* argv[] ) {
    QApplication a( argc, argv );

    QListWidget listWgt;
    listWgt.addItems( LIST_ITEMS );
    listWgt.resize( 300, 300 );
    listWgt.show();

    ListController listController;
    QObject::connect( 
        &listWgt, 
        SIGNAL( doubleClicked( QModelIndex ) ), 
        &listController, 
        SLOT( onListDoubleClicked( QModelIndex ) ) 
    );

    return a.exec();
}
