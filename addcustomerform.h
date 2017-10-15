#ifndef ADDCUSTOMERFORM_H
#define ADDCUSTOMERFORM_H

#include <QDialog>

namespace Ui {
class AddCustomerForm;
}

class AddCustomerForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerForm(QWidget *parent = 0);
    ~AddCustomerForm();

private:
    Ui::AddCustomerForm *ui;
};

#endif // ADDCUSTOMERFORM_H
