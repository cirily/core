/*
 * Copyright (C) 2021 Piscesys Team.
 *
 * Author:     Kate Leet <kate@piscesys.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "notificationpopup.h"

#include <QQmlContext>

#include <KWindowSystem>
#include <KWindowEffects>

NotificationPopup::NotificationPopup(QQuickView *parent)
    : QQuickView(parent)
{
    installEventFilter(this);

    setResizeMode(QQuickView::SizeRootObjectToView);
    setColor(Qt::transparent);
}

bool NotificationPopup::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::Show) {
        KWindowSystem::setState(winId(), NET::SkipTaskbar | NET::SkipPager | NET::SkipSwitcher);
    }

    return QObject::eventFilter(object, event);
}
