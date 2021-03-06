/***************************************************************************
 *   Copyright (C) 2010 by Pierre Marchand   *
 *   pierre@oep-h.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef SAMPLETOOLBAR_H
#define SAMPLETOOLBAR_H

#include <QWidget>
#include <QStringList>

namespace Ui {
    class SampleToolBar;
}

class SampleToolBar : public QWidget
{
    Q_OBJECT

public:
    explicit SampleToolBar(QWidget *parent = 0);
    ~SampleToolBar();

    enum Button{
	    SampleButton,
	    OpenTypeButton
    };

    double getFontSize() const;
    void setFontSize(double fs);

    bool isChecked(Button b);
    void toggle(Button b, bool c);

    void enableButton(Button b, bool c);

    void setScripts(const QStringList& ll);
    QString getScript();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SampleToolBar *ui;

signals:
    void SizeChanged(double);
    void SampleToggled(bool);
    void OpenTypeToggled(bool);
    void ScriptSelected();
};

#endif // SAMPLETOOLBAR_H
