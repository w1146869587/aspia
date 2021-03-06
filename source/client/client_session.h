//
// Aspia Project
// Copyright (C) 2018 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef ASPIA_CLIENT__CLIENT_SESSION_H_
#define ASPIA_CLIENT__CLIENT_SESSION_H_

#include <QObject>

namespace aspia {

class ClientSession : public QObject
{
    Q_OBJECT

public:
    ClientSession(QObject* parent)
        : QObject(parent)
    {
        // Nothing
    }

    virtual ~ClientSession() = default;

public slots:
    // Reads the incoming message for the session.
    virtual void messageReceived(const QByteArray& buffer) = 0;

    // Starts session.
    virtual void startSession() = 0;

    // Closes the session. When a slot is called, signal |sessionClosed| is not generated.
    virtual void closeSession() = 0;

signals:
    // Indicates that the session is started.
    void started();

    // Indicates an outgoing message.
    void sendMessage(const QByteArray& buffer);

    // Indicates an error in the session.
    void errorOccurred(const QString& message);

    // Indicates the end of the session by the user (for example, when the session window
    // is closed).
    void closedByUser();
};

} // namespace aspia

#endif // ASPIA_CLIENT__CLIENT_SESSION_H_
