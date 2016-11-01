#include "processdialog.h"
#include <QGridLayout>
#include <QProgressDialog>
#include <QFont>
processdialog::processdialog(QWidget *parent)
    : QDialog(parent)
{
    com_progress_->addItem(tr("progressBar"));
    com_progress_->addItem(tr("progressDialog"));
    main_layout_->addWidget(label_file__count_, 0, 0);
    main_layout_->addWidget(line_file_count,0, 1);
    main_layout_->addWidget(label_show_type_, 1, 0);
    main_layout_->addWidget(com_progress_, 1, 1);
    main_layout_->addWidget(bar_, 2, 0, 1, 2);
    main_layout_->addWidget(begin_bth, 3, 1);
    main_layout_->setMargin(15);
    main_layout_->setSpacing(10);
    connect(begin_bth, SIGNAL(clicked()), this, SLOT(startprogress()));
}

processdialog::~processdialog()
{

    qDebug()<< "git";
///只commit，没有add，使用git checkout -- filename 退回到原来的状态
    qDebug() << "hahha";

}

void processdialog::startprogress()
{
    bool ok;
    int num =  line_file_count ->text().toInt(&ok);///获取到编辑框需要记录进度的数目
    if(com_progress_->currentIndex() == 0)///查到当前下标
    {
        bar_->setRange(0,num);
        {
            for(int i =1; i<num; i++)
            {
                bar_->setValue(i);
            }
        }
    }
    else if(com_progress_->currentIndex() == 1)
    {
        QProgressDialog *progressdialog = new QProgressDialog(this);
        QFont font("ZYSong",12);
        progressdialog->setFont(font);
        progressdialog->setWindowModality(Qt::WindowModal);///设置对话框是模态方式进行显示，其他窗口不进行显示
        progressdialog->setMinimumDuration(5);
        progressdialog->setWindowTitle(tr("please wait"));
        progressdialog->setLabelText(tr("copy..."));
        progressdialog->setCancelButtonText(tr("cancle"));
        progressdialog->setRange(0,num);
        for(int i =1; i < num; i++)
        {
            progressdialog->setValue(i);
            if(progressdialog->wasCanceled())
            {
                return;
            }
        }

    }

}
