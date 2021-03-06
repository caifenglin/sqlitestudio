#ifndef JAVASCRIPTSYNTAXHIGHLIGHTER_H
#define JAVASCRIPTSYNTAXHIGHLIGHTER_H

/*
  This file is part of the Ofi Labs X2 project.

  Copyright (C) 2010 Ariya Hidayat <ariya.hidayat@gmail.com>

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "guiSQLiteStudio_global.h"
#include "plugins/builtinplugin.h"
#include "syntaxhighlighterplugin.h"
#include <QSyntaxHighlighter>
#include <QtGui>

/**
 * @brief The JavaScript (also QtScript) highlighter
 *
 * This class is mostly copied from Ofi Labs X2 project. It has been slightly modified for SQLiteStudio needs.
 * See the source code for the full license disclaimer.
 */
class GUI_API_EXPORT JavaScriptSyntaxHighlighter : public QSyntaxHighlighter
{
    public:
        explicit JavaScriptSyntaxHighlighter(QTextDocument *parent = 0);
        void mark(const QString &str, Qt::CaseSensitivity caseSensitivity);

    protected:
        void highlightBlock(const QString &text);

    private:
        QSet<QString> m_keywords;
        QSet<QString> m_knownIds;
        QString m_markString;
        Qt::CaseSensitivity m_markCaseSensitivity;
        QTextCharFormat normalFormat;
        QTextCharFormat keywordsFormat;
        QTextCharFormat commentFormat;
};

class GUI_API_EXPORT JavaScriptHighlighterPlugin : public BuiltInPlugin, public SyntaxHighlighterPlugin
{
    Q_OBJECT

    SQLITESTUDIO_PLUGIN_TITLE("QtScript highlighter")
    SQLITESTUDIO_PLUGIN_DESC("QtScript (JavaScript) syntax highlighter.")
    SQLITESTUDIO_PLUGIN_VERSION(10000)
    SQLITESTUDIO_PLUGIN_AUTHOR("sqlitestudio.pl")

    public:
        QString getLanguageName() const;
        QSyntaxHighlighter* createSyntaxHighlighter(QWidget* textEdit) const;
};
#endif // JAVASCRIPTSYNTAXHIGHLIGHTER_H
