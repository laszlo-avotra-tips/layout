#include "octkeyboard.h"
#include "ui_octkeyboard.h"

#include <QDebug>

OctKeyboard::OctKeyboard(const vector<QString> &param, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OctKeyboard)
{
    ui->setupUi(this);

    auto paramLabel = ui->labelParam;
    auto paramLineEdit = ui->lineEditParam;

    paramLabel->setText(param[0]);
    paramLineEdit->setText(param[1]);

    auto* enterButton = ui->pushButton_enter;
    connect(enterButton, &QPushButton::clicked, this, &QDialog::accept);

    auto deleteButton = ui->pushButton_delete;
    connect(deleteButton, &QPushButton::clicked, this, &OctKeyboard::handleDelete);

    auto spaceButton = ui->pushButton_space;
    connect(spaceButton, &QPushButton::clicked, this, &OctKeyboard::handleSpace);

    initButtonContainers();
    initNumbers();
    connect(this, &OctKeyboard::numberClicked, this, &OctKeyboard::handleNumbers);
    initLetters();
    connect(this, &OctKeyboard::letterClicked, this, &OctKeyboard::handleLetters);
}

OctKeyboard::~OctKeyboard()
{
    delete ui;
}

QString OctKeyboard::editResult()
{
    return ui->lineEditParam->text();
}

void OctKeyboard::handleDelete()
{
    auto target = ui->lineEditParam;
    auto param = target->text();
    if(!param.isEmpty()){
       int lastPosition = param.size() - 1;
       target->setText(param.remove(lastPosition,1));
    }
}

void OctKeyboard::handleSpace()
{
    QString val = ui->lineEditParam->text() + QString(" ");
    ui->lineEditParam->setText(val);
}

void OctKeyboard::handleNumbers(const QString& addText)
{
    auto stringList = addText.split("\n");
    if(stringList.size() == 2){
        QString val = ui->lineEditParam->text() + stringList[1];
        ui->lineEditParam->setText(val);
    } else if(stringList.size() == 1){
        QString val = ui->lineEditParam->text() + stringList[0];
        ui->lineEditParam->setText(val);
    }
}

void OctKeyboard::handleLetters(const QString &text)
{
    QString val = ui->lineEditParam->text() + text;
    ui->lineEditParam->setText(val);
}

void OctKeyboard::initButtonContainers()
{
    ButtonContainer numbers{
        ui->pushButton_zero,
        ui->pushButton_one,
        ui->pushButton_two,
        ui->pushButton_three,

        ui->pushButton_four,
        ui->pushButton_five,
        ui->pushButton_six,
        ui->pushButton_seven,

        ui->pushButton_eight,
        ui->pushButton_nine,
        ui->pushButton_coma,
        ui->pushButton_dot,

        ui->pushButton_minus,
        ui->pushButton_equal,
        ui->pushButton_angleLeft,
        ui->pushButton_angleRight,

        ui->pushButton_slash,
        ui->pushButton_backSlash,
    };

    m_numberButtons = numbers;

    ButtonContainer letters{
        ui->pushButton_a,
        ui->pushButton_b,
        ui->pushButton_c,
        ui->pushButton_d,

        ui->pushButton_e,
        ui->pushButton_f,
        ui->pushButton_g,
        ui->pushButton_h,

        ui->pushButton_i,
        ui->pushButton_j,
        ui->pushButton_k,
        ui->pushButton_l,

        ui->pushButton_m,
        ui->pushButton_n,
        ui->pushButton_o,
        ui->pushButton_p,

        ui->pushButton_q,
        ui->pushButton_r,
        ui->pushButton_s,
        ui->pushButton_t,

        ui->pushButton_u,
        ui->pushButton_v,
        ui->pushButton_w,
        ui->pushButton_x,

        ui->pushButton_y,
        ui->pushButton_z,
    };

    m_letterButtons = letters;
}

void OctKeyboard::initNumbers()
{
    for(auto* button : m_numberButtons){
        auto text = button->text();
        connect(button, &QPushButton::clicked, [this, text] {numberClicked(text);});
    }
}

void OctKeyboard::initLetters()
{
    for(auto* button : m_letterButtons){
        auto text = button->text();
        connect(button, &QPushButton::clicked, [this, text] {
            QString t = text;
            if(m_isCapLock){
                t = text.toUpper();
            }
            letterClicked(t);
        });
    }
}

void OctKeyboard::on_pushButton_capsLock_toggled(bool checked)
{
    m_isCapLock = checked;
    if(m_isCapLock){
        for( auto* letterButton : m_letterButtons){
            auto letter = letterButton->text();
            auto upperCase = letter.toUpper();
            letterButton->setText(upperCase);
        }
    } else {
        for( auto* letterButton : m_letterButtons){
            auto letter = letterButton->text();
            auto lowerCase = letter.toLower();
            letterButton->setText(lowerCase);
        }
    }
}
