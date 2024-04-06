#include "menuwindow.h"

MenuWindow::MenuWindow(QWidget* parent)
{
	this->setWindowTitle("Menu du jeu");

	//Modes : normal, rafale, stratégique

	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	// Create a QWidget to hold the grid layout
	QWidget* gridWidget = new QWidget(this);

	// Create the grid layout
	QGridLayout* layout = new QGridLayout(gridWidget);

	// Set margins for the grid widget
	gridWidget->setContentsMargins(15, 15, 15, 15);

	QFont comics("Comic Sans MS", 16, QFont::Bold);
	comics.setPointSizeF(20);

	QLabel* lblTitre = new QLabel(gridWidget);
	lblTitre->setAlignment(Qt::AlignCenter);
	lblTitre->setText("Choisir le mode de jeu!!!!!!");
	lblTitre->setFont(comics);


	QStringList fontFamilies = QFontDatabase::families();

	comics.setPointSizeF(16);

	QPushButton* btnNormal = new QPushButton(gridWidget);
	btnNormal->setText("Normal");
	btnNormal->setObjectName("btnNormal");
	btnNormal->setFont(comics);
	btnNormal->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	btnNormal->setStyleSheet("border-image: url(:/sprites/menu/bar.png);");

	QPushButton* btnRafale = new QPushButton(gridWidget);
	btnRafale->setText("Rafale");
	btnRafale->setFont(comics);
	btnRafale->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

	QPushButton* btnStrategique = new QPushButton(gridWidget);
	btnStrategique->setText("Stratégique");
	btnStrategique->setFont(comics);
	btnStrategique->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

	layout->addWidget(lblTitre, 0, 0, 1, 3);
	layout->addWidget(btnNormal, 1, 1);
	layout->addWidget(btnRafale, 2, 1);
	layout->addWidget(btnStrategique, 3, 1);

	mainLayout->addWidget(gridWidget);

	this->show();
}

MenuWindow::~MenuWindow() {
}



void MenuWindow::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_Escape) {
		// Exit the application if the Escape key is pressed
		QCoreApplication::quit();
	}
	else {
		// Call the base class implementation for other key events
		QWidget::keyPressEvent(event);
	}
}

