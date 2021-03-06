//_____________________________________________________________________________
//_____________________________________________________________________________
//                                DICTIONARY
// Manages the gui text in labels, buttons etc., allowing the user to choose
// italian or english language.
//_____________________________________________________________________________
//_____________________________________________________________________________

#include "dictionary.h"

Dictionary::Dictionary()
{
}

void Dictionary::setLanguage(lang current_language)
{
    this->current_language = current_language;
}

lang Dictionary::getLanguage()
{
    return current_language;
}

std::string Dictionary::choices(std::string s1, std::string s2)
{
    if (current_language == italian)
            return s1;
    if (current_language == english)
        return s2;
    return "empty";
}

// FrmMain
std::string Dictionary::getTextOflblStart()
{
    return choices("Avviare:", "Start:");
}

std::string Dictionary::getTextOfbtnServer()
{
    return " Server";
}

std::string Dictionary::getTextOfbtnClient()
{
    return " Client";
}

std::string Dictionary::getTextOflblLang()
{
    return choices("Lingua", "Language");
}

void Dictionary::setIconOfbtnLang(QPushButton *btn)
{
    QPixmap lang_img;
    if(current_language == english)
    {
        lang_img.load(":/resources/media/italian.png");
    }
    else
    {
        lang_img.load(":/resources/media/english.png");
    }

    QIcon LangIcon(lang_img);
    btn->setIcon(LangIcon);
    btn->setIconSize(lang_img.rect().size());
}

std::string Dictionary::getTextOfbtnExit()
{
    return choices(" Esci", " Exit");
}

// FrmServer
std::string Dictionary::getTextOflblInfoServer()
{
    return choices("Configurazione connessione", "Connection settings");
}

void Dictionary::setTextOflblIpServerS(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Il tuo indirizzo IP pubblico, da comunicare al "
                             "client.\nSe il sistema non è connesso ad "
                             "internet sarà mostrato l'indirizzo 127.0.0.1.",
                             "Your public IP address, tell it to the client.\n"
                             "If your system isn't connected to internet, "
                             "127.0.0.1 will be shown.")));
    lbl->setText(QString::fromStdString(choices("Tuo IP:", "Your IP:")));
}

void Dictionary::setTextOflblIpClientS(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Inserire l'indirizzo IP del client, pubblico o "
                             "privato.", "Insert client's IP address, "
                                         "either public or private.")));
    lbl->setText("Client IP:");
}

void Dictionary::setTextOflblPort(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Porta del server.", "Server port.")));
    lbl->setText(QString::fromStdString(choices("Porta:", "Port:")));
}

void Dictionary::setTextOflblPasswordS(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("E' possibile impostare una password per la "
                             "connessione del client.\nLasciare vuoto questo"
                             " campo per non utilizzare nessuna password.",
                             "It is possible to set a password for client "
                             "connection.\nLeave it blank in order to use no "
                             "password.")));
    lbl->setText("Password:");
}

void Dictionary::setTextOflblSource(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Sorgente video da inviare al client.",
                             "Video source to use.")));
    lbl->setText(QString::fromStdString(choices("Sorgente:", "Source:")));
}

void Dictionary::setTextOflblVideoChunk(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Imposta la durata in secondi di ogni chunk "
                             "estratto dal file video.", "Set the time length"
                             " in seconds of each chunk extracted from the "
                                                         "video file.")));
    lbl->setText(QString::fromStdString
                 (choices("Video Chunk:", "Video Chunk:")));
}

void Dictionary::setTextOflblNetwork(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Definisce la rete neurale da utilizzare per "
                             "fare detection.", "Defines the neural network to"
                                                " be used for detection.")));
    lbl->setText(QString::fromStdString(choices("Rete", "Network")));
}

std::string Dictionary::getTextOflblConfig()
{
    return choices("Configurazione streaming", "Streaming configuration");
}

std::string Dictionary::getTextOflblLeaveConfig()
{
    return choices("Lascia la configurazione al client:",
                   "Leave the configuration to client:");
}

void Dictionary::setTextOflblResolution(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Risoluzione di output.", "Output resolution.")));
    lbl->setText(QString::fromStdString
                 (choices("Risoluzione:", "Resolution:")));
}

void Dictionary::setTextOflblFps(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("FPS massimi desiderati in output.",
                             "Maximum output FPS desired.")));
    lbl->setText("FPS:");
}

void Dictionary::setTextOflblColorScale(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Scala colori dei pixel delle immagini in "
                             "output.", "Color scale of output image's "
                                        "pixels.")));
    lbl->setText(QString::fromStdString
                 (choices("Scala colori:", "Color scale:")));
}

void Dictionary::setTextOflblBlur(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Quantità dell'effetto sfocatura alle immagini"
                             " trasmesse", "Quantity of blur effect added "
                                           "to transmitted frames")));
    lbl->setText(QString::fromStdString
                 (choices("Sfocatura: ", "Blur: ")));
}

std::string Dictionary::getTextOfbtnBack()
{
    return choices(" Indietro", " Back");
}

std::string Dictionary::getTextOfbtnStartServer()
{
    return choices(" Avvia server", " Start server");
}

void Dictionary::fillcmbSource(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("File video", "Video file")));
    cmb->addItem(QString::fromStdString(choices("Camera", "Camera")));
    cmb->addItem(QString::fromStdString(choices("Schermo", "Screen")));
    cmb->setCurrentIndex(1);
}

void Dictionary::fillcmbResolution(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("Sorgente", "Source")));
    cmb->addItem("3840 x 2160");
    cmb->addItem("2560 x 1440");
    cmb->addItem("1920 x 1080");
    cmb->addItem("1600 x 900");
    cmb->addItem("1280 x 720");
    cmb->addItem("854 x 480");
    cmb->addItem("640 x 360");
    cmb->addItem("426 x 240");
    cmb->addItem("256 x 144");
}

void Dictionary::fillcmbColorScale(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("Sorgente", "Source")));
    cmb->addItem("24 bpp");
    cmb->addItem("16 bpp");
    cmb->addItem("12 bpp");
    cmb->addItem("8 bpp");
    cmb->addItem(QString::fromStdString(choices("8 bpp (grigio)",
                                                "8 bpp (gray)")));
    cmb->addItem(QString::fromStdString(choices("1 bpp (b/n)",
                                                "1 bpp (b/w)")));
}

void Dictionary::fillcmbFps(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("Sorgente", "Source")));
    cmb->addItem("60");
    cmb->addItem("59");
    cmb->addItem("55");
    cmb->addItem("50");
    cmb->addItem("45");
    cmb->addItem("40");
    cmb->addItem("35");
    cmb->addItem("30");
    cmb->addItem("25");
    cmb->addItem("20");
    cmb->addItem("15");
}

void Dictionary::fillcmbVideoChunk(QComboBox *cmb)
{
    cmb->addItem(QString::fromStdString(choices("10 secondi", "10 seconds")));
    cmb->addItem(QString::fromStdString(choices("15 secondi", "15 seconds")));
    cmb->addItem(QString::fromStdString(choices("20 secondi", "20 seconds")));
    cmb->addItem(QString::fromStdString(choices("25 secondi", "25 seconds")));
    cmb->addItem(QString::fromStdString(choices("30 secondi", "30 seconds")));
}

void Dictionary::fillcmbNetwork(QComboBox *cmb)
{
    cmb->addItem("ssd-mobilenet-v2");
}

// FrmClient
std::string Dictionary::getTextOfbtnConnect()
{
    return choices(" Connetti", " Connect");
}

void Dictionary::setTextOflblIpClientC(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Il tuo indirizzo IP pubblico, da comunicare al "
                             "server.\nSe il sistema non è connesso ad "
                             "internet sarà mostrato l'indirizzo 127.0.0.1.",
                             "Your public IP address, tell it to the server."
                             "\nIf your system isn't connected to internet, "
                             "127.0.0.1 will be shown.")));
    lbl->setText(QString::fromStdString(choices("Tuo IP:", "Your IP:")));
}

void Dictionary::setTextOflblIpServerC(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Inserire l'indirizzo IP del server,"
                    " pubblico o privato.", "Insert server's IP address,"
                                            " either public or private.")));
    lbl->setText("Server IP:");
}

void Dictionary::setTextOflblPasswordC(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Password per connettersi al server.\nSe lato "
                             "server non è impostata alcuna password, lasciare"
                             " il campo vuoto.", "Server connection password."
                             "\nIf server side no password is specified, "
                                                 "leave the field blank.")));
    lbl->setText("Password:");
}


// Open a file
std::string Dictionary::getTextOpenafile()
{
    return choices("Apri un file", "Open a file");
}


// FrmRunning
void Dictionary::getTextOflblStateRunning(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Indica lo stato attuale del server.\nPosiziona "
                    "il cursore sulle icone di stato per avere più "
                    "informazioni.", "Indicates the actual state of the "
                    "server.\nPlace the cursor over the status icons for more"
                    " information.")));
    lbl->setText(QString::fromStdString(choices("Stato:", "State:")));
}

std::string Dictionary::getTextOfbtnStopRunning()
{
    return choices(" Ferma server", " Stop server");
}

void Dictionary::setTIbtnStartStopStream(QPushButton *btn, int select)
{
    if(select == 0)
    {
        QPixmap play_img(":/resources/media/play.png");
        QIcon PlayIcon(play_img);
        btn->setIcon(PlayIcon);
        btn->setIconSize(play_img.rect().size());
        btn->setText(QString::fromStdString
                     (choices(" Avvia streaming", " Start streaming")));
    }

    else
    {
        QPixmap stop_img(":/resources/media/stop.png");
        QIcon StopIcon(stop_img);
        btn->setIcon(StopIcon);
        btn->setIconSize(stop_img.rect().size());
        btn->setText(QString::fromStdString
                    (choices(" Ferma streaming", " Stop streaming")));
    }
}

void Dictionary::setTooltipOflblState2(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Stato del collegamento Client-Server.\nGrigio: "
                    "in attesa di collegamento.\nVerde: client collegato.",
                    "Client-Server connection state.\nGrey: waiting for a "
                    "connection.\nGreen: client connected.")));
}

void Dictionary::setTooltipOflblState3(QLabel *lbl)
{
    lbl->setToolTip(QString::fromStdString
                    (choices("Stato dello streaming video Client-Server.\n"
                             "Grigio: non attivo.\nVerde: attivo.", "Client-"
                             "Server video streaming state.\nGrey: not active."
                             "\nGreen: active.")));
}

void Dictionary::fillModel(QStandardItemModel *model)
{
    QString resolution, color_scale, source, seconds,
            enable, disable, network, blur_effect, cs_choice;
    int row;

    row = 0;

    if(current_language == english)
    {
        resolution = "Resolution: ";
        source = "source";
        color_scale = "Color scale: ";
        seconds = " seconds";
        enable = "enabled";
        disable = "disabled";
        network = "Network: ";
        blur_effect = "Blur: ";
    }
    else
    {
        resolution = "Risoluzione: ";
        source = "sorgente";
        color_scale = "Scala colori: ";
        seconds = " secondi";
        enable = "abilitato";
        disable = "disabilitato";
        network = "Rete: ";
        blur_effect = "Sfocatura: ";
    }

    if(Configurations::resolution != 0)
        model->setItem(row, 0, new QStandardItem(resolution +
                      QString::fromStdString(Configurations::resolution_choices
                                               [Configurations::resolution])));
    else
        model->setItem(row, 0, new QStandardItem(resolution + source));
    row++;

    if(Configurations::fps != 0)
        model->setItem(row, 0, new QStandardItem(QString("FPS: ") +
                        QString::number(Configurations::fps_choices
                                               [Configurations::fps])));
    else
        model->setItem(row, 0, new QStandardItem(QString("FPS: ") + source));
    row++;

    if(Configurations::color_scale != 0)
    {
        switch(Configurations::color_scale_choices
               [Configurations::color_scale])
        {
        case 24:
            cs_choice = "24 bpp";
            break;
        case 16:
            cs_choice = "16 bpp";
            break;
        case 12:
            cs_choice = "12 bpp";
            break;
        case 80:
            cs_choice = "8 bpp";
            break;
        case 81:
            cs_choice = QString::fromStdString
                    (choices("8 bpp (grigio)", "8 bpp (grey)"));
            break;
        case 1:
            cs_choice = QString::fromStdString
                    (choices("1 bpp (b/n)", "1 bpp (b/w)"));
            break;
        default:
            cs_choice = source;
            break;
        }
        model->setItem(row, 0, new QStandardItem(color_scale + cs_choice));
    }
    else
        model->setItem(row, 0, new QStandardItem(color_scale + source));
    row++;

    if(Configurations::source == 0)
    {
        model->setItem(row, 0, new QStandardItem(QString("Video chunk: ") +
                       QString::number(Configurations::video_chunk_seconds)
                                               + seconds));
        row++;
    }

    if(Configurations::intrusion_detection_enabled)
        model->setItem(row, 0, new QStandardItem(QString
                       ("CUDA Intrusion Detection: ") + enable));
    else
        model->setItem(row, 0, new QStandardItem(QString
                       ("CUDA Intrusion Detection: ") + disable));
    row++;

    model->setItem(row, 0, new QStandardItem(network +
                   QString::fromStdString(Configurations::network)));
    row++;
    model->setItem(row, 0, new QStandardItem(blur_effect + QString::number
                                             (Configurations::blur_effect)));
}

// FrmConnected
std::string Dictionary::getTextOfbtnDisconnect(int select)
{
    if(select == 0)
        return choices(" Annulla", " Cancel");
    else
        return choices(" Disconnetti", " Disconnect");
}

void Dictionary::getTextOfbtnStartStreaming(QPushButton *btn, int select)
{
    if(select == 0)
    {
        QPixmap play_img(":/resources/media/play.png");
        QIcon PlayIcon(play_img);
        btn->setIcon(PlayIcon);
        btn->setIconSize(play_img.rect().size());
        btn->setToolTip(QString::fromStdString
                        (choices("Crea una connessione RTSP con il server e "
                        "inizia ad acquisire lo streaming video.", "Start a "
                        "RTSP connection with the server and begin to "
                        "capture video streaming.")));
        btn->setText(QString::fromStdString
                     (choices(" Avvia streaming", " Start streaming")));
    }

    else
    {
        QPixmap stop_img(":/resources/media/stop.png");
        QIcon StopIcon(stop_img);
        btn->setIcon(StopIcon);
        btn->setIconSize(stop_img.rect().size());
        btn->setToolTip(QString::fromStdString
                        (choices("Interrompe la connessione RTSP "
                                 "con il server.",
                                 "End the RTSP connection.")));
        btn->setText(QString::fromStdString(
                         choices(" Ferma streaming", " Stop streaming")));
    }
}
