#include <iostream>
#include <QWidget>
#include <QtWidgets/QApplication>
#include "panel.h"
#include "form.h"
int main(int argc, char** argv) {
    QApplication app(argc,argv);
    Form* form=new Form;
    Panel* panel=new Panel;
    form->setWindowTitle("Form Qt");
    panel->setWindowTitle("Panel Qt");
    form->setLabel("SBN");
    (static_cast<QObject*>(panel))->connect(panel,&Panel::reqSetLabel,form,&Form::setLabel);

    form->show();

    panel->show();
    Q_EMIT panel->reqSetLabel("FMS");

    app.exec();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}