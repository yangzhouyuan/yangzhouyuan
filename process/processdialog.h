#ifndef PROCESSDIALOG_H
#define PROCESSDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QProgressBar>
#include <QGridLayout>


class processdialog : public QDialog
{
    Q_OBJECT

public:
    processdialog(QWidget *parent = 0);
    ~processdialog();
private:
    QLabel *label_file__count_ = new QLabel(tr("文件数目"));
    QLineEdit *line_file_count = new QLineEdit(tr("10000"));
    QLabel *label_show_type_ = new QLabel(tr("显示类型"));
    QComboBox *com_progress_ = new QComboBox();
    QPushButton *begin_bth = new QPushButton(tr("开始"));
    QGridLayout *main_layout_ = new QGridLayout(this);
    QProgressBar *bar_ = new QProgressBar;
private slots:
    void startprogress();

};

#endif // PROCESSDIALOG_H
